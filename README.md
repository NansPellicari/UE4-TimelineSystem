# Timeline system

This plugins allows to keep tracks of time for different paradigm ([Real](#real) life time, [Game](#game) life and [Level](#level) life), attached events to them and managed serialzation for Save and Load game.

<!-- TOC -->

-   [Dependencies](#dependencies)
    -   [UE4 plugins](#ue4-plugins)
    -   [for docs](#for-docs)
-   [Usages](#usages)
-   [Definitions](#definitions)
    -   [Timeline](#timeline)
    -   [Timeline manager](#timeline-manager)
    -   [Timeline manager types](#timeline-manager-types)
        -   [1- Real Life](#1--real-life)
        -   [2- Game Life](#2--game-life)
        -   [3- Level Life](#3--level-life)
        -   [4- And ...](#4--and-)
    -   [Events](#events)

<!-- /TOC -->

For developers:

-   [Developers docs](./Docs/Developers.md)

<a id="markdown-dependencies" name="dependencies"></a>

## Dependencies

<a id="markdown-ue4-plugins" name="ue4-plugins"></a>

### UE4 plugins

-   [NansUE4TestsHelpers](https://github.com/NansPellicari/NansUE4TestsHelpers) (free UE4 plugins)

<a id="markdown-for-docs" name="for-docs"></a>

### for docs

-   [node](https://nodejs.org/en/download/) + npm (installed by default with node-js)
-   [Doxygen](http://www.doxygen.nl/download.html)

> [What I used for API documentation](https://sourcey.com/articles/generating-beautiful-cpp-markdown-documentation-with-moxygen)

<a id="markdown-usages" name="usages"></a>

## Usages

I use this for differents purposes.  
First I created this to manage a **bonus/malus** system cause I needed to centralized their life duration.  
Then I realized that it can be very helpfull for **different purposes** in my game as creating **promotionnal content**, **bonus/malus**, **temporary skills**, **xp earning factors**, ... with a limited time and having **precise stats** for **player activities**.

<a id="markdown-definitions" name="definitions"></a>

## Definitions

<a id="markdown-timeline" name="timeline"></a>

### Timeline

A timeline is a simple **queue of events** which is dedicated to store (to keep traces for stats) and notify them (depending on their parameters and timeline paradigm) on their lifetime events: start & time increase.  
As a client, you should never have to use it.

<a id="markdown-timeline-manager" name="timeline-manager"></a>

### Timeline manager

Is working as a remote control for **Timeline**, it controls time state (Play, Pause) and stream (tick interval, slow motion, ...).  
As a client, it is your main interface.

<a id="markdown-timeline-manager-types" name="timeline-manager-types"></a>

### Timeline manager types

<a id="markdown-1--real-life" name="1--real-life"></a>

#### 1- Real Life

The intent of the **Real Life** timeline is to tracks times **since** the **game started**.  
It is **not affected** by **time alterations** such as **play/pause** and **slow motion**, ...  
After the game stops, it shoulds **replay** all the **missing time** on game reloading to **update** attached **Events states**.  
As real life is, its state is always **Play**.  
Be careful when you attached events, it could increase memory if they have indeterminate life time.

<a id="markdown-2--game-life" name="2--game-life"></a>

#### 2- Game Life

It keep track of player game session. It follow the same stream, **Play/Pause**, **Stop**, **slow motion**, ...  
After the game stops, it shoulds restart at the exact same time as the last session.  
Be careful too when you attached event here.

<a id="markdown-3--level-life" name="3--level-life"></a>

#### 3- Level Life

The same as [Game Life](#2--game-life) but it is reinitialized when level changes.  
You can be less worried on attaching event here, but be aware that all events are definitively removed on reinitialization (level changes).

<a id="markdown-4--and-" name="4--and-"></a>

#### 4- And ...

You can easily create your own timeline manager. See [Developers docs](./Docs/Developers.md).

<a id="markdown-events" name="events"></a>

### Events

They are intended to be the most extensible as possible.  
So in their actual state, they just embeds the necessary data to managed their lifetime.  
You can specialized them with only a simple Blueprint or in c++ classes to do what your want.  
To get some examples:

-   I create a **scheduled event** to **trigger a message** to motivate the player when it cumulates an amount of succeeded actions during a determinate range of time.
-   In combination with my [Factors System](https://github.com/NansPellicari/UE4-NansDifficultySystem) and [Interaction System](...), I used them to create temp **Bonus/Malus** after an Actor interaction.
-   ... Sky's the limit!
