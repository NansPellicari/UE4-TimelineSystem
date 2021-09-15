## 1. To brings external plugins here

The better way seems to `git rebase -i` the `UE4Marketplace` branch and remove all previous `git subtree add` and do it again. This way we can keep only necessary altered files.

Source: https://stackoverflow.com/questions/20102594/git-subtree-push-squash-does-not-squash

### 1.1. NansCoreHelpers

```powershell
git remote add CoreHelpers https://github.com/NansPellicari/UE4-CoreHelpers.git
git fetch CoreHelpers
git branch CoreHelpers_dev CoreHelpers/develop
git checkout -f CoreHelpers_dev
git subtree split --prefix=Source/NansCoreHelpers -b tmp_br
git checkout UE4Marketplace
git subtree add --squash --prefix=Source/NansCoreHelpers tmp_br
git branch -D tmp_br
```

### 1.2. NansUE4TestsHelpers

```powershell
git remote add TestsHelpers https://github.com/NansPellicari/UE4-TestsHelpers.git
git fetch TestsHelpers
git branch TestsHelpers_dev TestsHelpers/develop
git checkout -f TestsHelpers_dev
git subtree split --prefix=Source/NansUE4TestsHelpers -b tmp_br
git checkout UE4Marketplace
git subtree add --squash --prefix=Source/NansUE4TestsHelpers tmp_br
git branch -D tmp_br
```
