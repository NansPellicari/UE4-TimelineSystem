const path = require('path');
const fs = require('fs');
const chalk = require('chalk');
const { spawnSync } = require("child_process");

// config list can be foud here: https://github.com/mermaid-js/mermaid/blob/master/docs/mermaidAPI.md#mermaidapi-configuration-defaults

async function compileDiagram(file, format) {
    const result = file.replace(".mmd", "." + format);
    // eslint-disable-next-line no-console
    console.warn(`Compiling ${file} into ${result}`);
    let child = null;
    try {
        child = await spawnSync("node", [
            __dirname + "/node_modules/@mermaid-js/mermaid-cli/index.bundle.js",
            "-i",
            file,
            "-o",
            result,
            "-s 1",
            "-c",
            __dirname + "/mermaid.config.json",
            "-b #f7f7f7"
        ], { timeout: 5000 });
    } catch (err) {
        throw new Error(err)
    }

    if (child != null) {
        const stdout = child.stdout.toString('utf8').trim()
        if (stdout !== "") {
            console.info(stdout)
        }
        const stderr = child.stderr.toString('utf8').trim()
        if (stderr !== "") {
            console.warn(chalk.yellow(stderr))
        }

        if (child.status !== 0 || child.error) {
            // eslint-disable-next-line no-console
            console.error(chalk.red(`${file}: child process exited with code ${child.status}, error ${child.error}`));
        }
    }
}

async function fromDir(startPath, filter, callback) {
    if (!fs.existsSync(startPath)) {
        console.log("no dir ", startPath);
        return;
    }

    var files = fs.readdirSync(startPath);
    for (var i = 0; i < files.length; i++) {
        var filename = path.join(startPath, files[i]);
        var stat = fs.lstatSync(filename);
        if (stat.isDirectory()) {
            fromDir(filename, filter, callback);
        }
        else if (filter.test(filename)) {
            try {
                await callback(filename);
            } catch (err) {
                throw new Error(err);
            };
        }
    };
};

(async () => {
    try {
        await fromDir('./Docs', /\.mmd$/, async (filename) => {
            try {
                await compileDiagram(filename, 'png');
            } catch (err) {
                throw new Error(err);
            }
        });
    } catch (err) {
        console.error(chalk.red(`error: ${err}`));
        process.exit(1);
    }
})();