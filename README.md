# Timeline system

This plugins allows to keep tracks of time for different paradigm ([Real](#real) life time, [Game](#game) life and [Level](#level) life), attached events to them and managed serialzation for Save and Load game.

<!-- TOC -->

-   [1. Requirements](#1-requirements)
    -   [1.1. UE4 plugins](#11-ue4-plugins)
    -   [1.2. for docs](#12-for-docs)
-   [2. Usages](#2-usages)
-   [3. Definitions](#3-definitions)
    -   [3.1. Timeline](#31-timeline)
    -   [3.2. Timeline manager](#32-timeline-manager)
    -   [3.3. Timeline manager types](#33-timeline-manager-types)
        -   [3.3.1. - Real Life](#331---real-life)
        -   [3.3.2. - Game Life](#332---game-life)
        -   [3.3.3. - Level Life](#333---level-life)
        -   [3.3.4. - And ...](#334---and-)
    -   [3.4. Events](#34-events)
-   [4. Step by step guide](#4-step-by-step-guide)

<!-- /TOC -->

For developers:

-   [Developers docs](./Docs/Developers.md)

<a id="markdown-1-requirements" name="1-requirements"></a>

## 1. Requirements

<a id="markdown-11-ue4-plugins" name="11-ue4-plugins"></a>

### 1.1. UE4 plugins

-   [NansUE4TestsHelpers](https://github.com/NansPellicari/NansUE4TestsHelpers) (free UE4 plugins)

<a id="markdown-2-usages" name="2-usages"></a>

## 2. Usages

I use this for differents purposes.  
First I created this to manage a **bonus/malus** system cause I needed to centralized their life duration.  
Then I realized that it can be very helpfull for **different purposes** in my game as creating **promotionnal content**, **bonus/malus**, **temporary skills**, **xp earning factors**, ... with a limited time and having **precise stats** for **player activities**.

<a id="markdown-3-definitions" name="3-definitions"></a>

## 3. Definitions

<a id="markdown-31-timeline" name="31-timeline"></a>

### 3.1. Timeline

A timeline is a simple **queue of events** which is dedicated to store (to keep traces for stats) and notify them (depending on their parameters and timeline paradigm) on their lifetime events: start & time increase.  
As a client, you should never have to use it.

<a id="markdown-32-timeline-manager" name="32-timeline-manager"></a>

### 3.2. Timeline manager

Is working as a remote control for **Timeline**, it controls time state (Play, Pause) and stream (tick interval, slow motion, ...).  
As a client, it is your main interface.

<a id="markdown-33-timeline-manager-types" name="33-timeline-manager-types"></a>

### 3.3. Timeline manager types

<a id="markdown-331---real-life" name="331---real-life"></a>

#### 3.3.1. - Real Life

The intent of the **Real Life** timeline is to tracks times **since** the **game started**.  
It is **not affected** by **time alterations** such as **play/pause** and **slow motion**, ...  
After the game stops, it shoulds **replay** all the **missing time** on game reloading to **update** attached **Events states**.  
As real life is, its state is always **Play**.  
Be careful when you attached events, it could increase memory if they have indeterminate life time.

<a id="markdown-332---game-life" name="332---game-life"></a>

#### 3.3.2. - Game Life

It keep track of player game session. It follow the same stream, **Play/Pause**, **Stop**, **slow motion**, ...  
After the game stops, it shoulds restart at the exact same time as the last session.  
Be careful too when you attached event here.

<a id="markdown-333---level-life" name="333---level-life"></a>

#### 3.3.3. - Level Life

The same as [Game Life](#2--game-life) but it is reinitialized when level changes.  
You can be less worried on attaching event here, but be aware that all events are definitively removed on reinitialization (level changes).

<a id="markdown-334---and-" name="334---and-"></a>

#### 3.3.4. - And ...

You can easily create your own timeline manager. See [Developers docs](./Docs/Developers.md).

<a id="markdown-34-events" name="34-events"></a>

### 3.4. Events

They are intended to be the most extensible as possible.  
So in their actual state, they just embeds the necessary data to managed their lifetime.  
You can specialized them with only a simple Blueprint or in c++ classes (creating a [Decorator](https://refactoring.guru/design-patterns/decorator)) to do what your want.  
To get some examples:

-   I create a **scheduled event** to **trigger a message** to motivate the player when it cumulates an amount of succeeded actions during a determinate range of time.
-   In combination with my [Factors Factory System](https://github.com/NansPellicari/UE4-NansFactorsFactory) and [Interaction System](...), I used them to create temp **Bonus/Malus** after an Actor interaction.
-   ... Sky's the limit!

<a id="markdown-4-step-by-step-guide" name="4-step-by-step-guide"></a>

## 4. Step by step guide
