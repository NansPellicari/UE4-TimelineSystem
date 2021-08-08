# Developers
<a id="markdown-developers" name="developers"></a>

Get the full documentation of the [API here](Api.md).

<!-- TOC -->

- [1. Dependencies](#1-dependencies)
    - [1.1. Plugins](#11-plugins)
    - [1.2. for docs](#12-for-docs)
- [2. Design decisions](#2-design-decisions)
    - [2.1. Core & UE4 separation](#21-core--ue4-separation)
- [3. How to override, create my own Event, Timeline, etc...](#3-how-to-override-create-my-own-event-timeline-etc)
    - [3.1. TimelineManager](#31-timelinemanager)
    - [3.2. Timeline](#32-timeline)
    - [3.3. Event](#33-event)
- [4. Special case: Load game](#4-special-case-load-game)
    - [4.1. Create USaveGame Object](#41-create-usavegame-object)
    - [4.2. Copy/Paste to override UE functions](#42-copypaste-to-override-ue-functions)
    - [4.3. Trigger Save/Load](#43-trigger-saveload)
- [5. Testing](#5-testing)
    - [5.1. Launch UE4 tests](#51-launch-ue4-tests)
    - [5.2. Make Google Tests works](#52-make-google-tests-works)
- [6. Contributing](#6-contributing)

<!-- /TOC -->


## 1. Dependencies
<a id="markdown-dependencies" name="dependencies"></a>

### 1.1. Plugins
<a id="markdown-plugins" name="plugins"></a>
Those specified in the main readme + [UE4-GoogleTest](https://github.com/NansPellicari/UE4-GoogleTest)


### 1.2. for docs
<a id="markdown-for-docs" name="for-docs"></a>

-   [node](https://nodejs.org/en/download/) + npm (installed by default with node-js)
-   [Doxygen](http://www.doxygen.nl/download.html)

> [What I used for API documentation](https://sourcey.com/articles/generating-beautiful-cpp-markdown-documentation-with-moxygen)


## 2. Design decisions
<a id="markdown-design-decisions" name="design-decisions"></a>

My goal was to create the most extensible plugin as possible and keep things simple and readable as inspired by [separation of concerns](https://en.wikipedia.org/wiki/Separation_of_concerns) philosophy and [SOLID principles](https://en.wikipedia.org/wiki/SOLID).


### 2.1. Core & UE4 separation
<a id="markdown-core--ue4-separation" name="core--ue4-separation"></a>

**> Core** module manage every "basic" functionnalities:

-   it manipulates basics data
-   it tries to be the most **UE4 agnostic**
-   it is a lightweight library with the less dependencies as possible (only **Core** UE4 modules)
-   it provides basics interfaces or abstract classes to work with
-   it can be build for simple project as **program** build instead of **game** build (to run fast unit tests for example, see [UE4-TPL-CppWithTestEnv](https://github.com/NansPellicari/UE4-TPL-CppWithTestEnv) for an "how to")

**> UE4** module is a more high level paradigm:

-   it is the bridge from **Core** library to **UE4 Editor** and **Game** program
-   it provides more complex implementations of **Core** interfaces or abstract classes thanks to a bunch of [decorators](https://refactoring.guru/design-patterns/decorator) to fit with general **game needs**.
-   it provides **configs** & **UI** (blueprints) for editor manipulations
-   it manages **serialization** for the whole system
-   it provides an interface for your **GameInstance** to work with the [TimelineClient](../Source/NansTimelineSystemUE4/Public/TimelineClient.h) object, this makes the glue with configurations, blueprint functions and serialization for savegame.


## 3. How to override, create my own Event, Timeline, etc...
<a id="markdown-how-to-override-create-my-own-event-timeline-etc" name="how-to-override-create-my-own-event-timeline-etc"></a>

First, I create the whole structure to be the most extensible.  
To doing it, we have to consider **3** basics elements:

![basic class](./mermaid/basic-class.png)

> To get more details, you can read the [README definitions](../README.md#3-definitions) section.

Each of these **Core** classes in `Source/NansTimelineSystemCore` have their **decorator(s)** in the `Source/NansTimelineSystemUE4`.  
The most preferable way to extend them, it's to create your own decorators or override existants decorators.


### 3.1. TimelineManager
<a id="markdown-timelinemanager" name="timelinemanager"></a>

It can be easily decorated, see [Source/NansTimelineSystemUE4/Public/Manager/\*](../Source/NansTimelineSystemUE4/Public/Manager/) for examples.  
The easy way is to override the base decorator [TimelineManagerDecorator](../Source/NansTimelineSystemUE4/Public/Manager/TimelineManagerDecorator.h).  
You can create your own manager for your game specificities.


### 3.2. Timeline
<a id="markdown-timeline" name="timeline"></a>

This class should not be overrided, it provides the basic functionnalities to manage events and serialization, it works more as extended queues rather than client object with complex usage.


### 3.3. Event
<a id="markdown-event" name="event"></a>

You **should** create an asset for it based on the [EventView](../Source/NansTimelineSystemUE4/Public/Event/EventView.h) class.  
You can create a **blueprint** child based on it or a **c++** override.

> To make your data saveable, don't forget to use `UPROPERTY(SaveGame)` in your dedicated fields,  
> or in your blueprint details panel:  
> ![blueprint savegame](./img/savegame-prop.png)


## 4. Special case: Load game
<a id="markdown-special-case-load-game" name="special-case-load-game"></a>

**Load** is a bit tricky here, because we need to pass a `UWorld` object to the `USaveGame` object to retrieve `UNTimelineManager` from the `UGameInstance`.  
As I explain [here](https://answers.unrealengine.com/questions/958879/what-is-the-best-way-to-populate-usavegame-on-load.html) the actual code (UE4.25) doesn't allow it with the standard approach.


### 4.1. Create USaveGame Object
<a id="markdown-create-usavegame-object" name="create-usavegame-object"></a>

First you can follow [this UE4 doc page](https://docs.unrealengine.com/en-US/Gameplay/SaveGame/index.html) to create your own.
Then you have to add a public `UObject* WorldContextObject` property and add these lines:

```cpp
// at the top of the file
#include "NansTimelineSystemUE4/Public/TimelineGameSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"

// in your `Serialize()` method
if (WorldContextObject == nullptr) return;
if (WorldContextObject->GetWorld() == nullptr) return;
if (WorldContextObject->GetWorld()->GetGameInstance() == nullptr) return;

// To retrieve the c++ layer of the interface
UGameInstance* GI = WorldContextObject->GetWorld()->GetGameInstance());
UTimelineGameSubsystem* MySubsystem = GI->GetSubsystem<UTimelineGameSubsystem>();

MySubsystem->GetTimelineClient()->Serialize(Ar);

```


### 4.2. Copy/Paste to override UE functions
<a id="markdown-copypaste-to-override-ue-functions" name="copypaste-to-override-ue-functions"></a>

> /!\ Important note:  
> Due to UE4 license limitation, I can't copy/paste too much engine's code here.  
> I'll try to give you the most clues as possible to do it on your own.

All the party in question is located in the [UGameplayStatics](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp) class.

So first you need to create a custom `UBlueprintFunctionLibrary` and copy/paste [UGameplayStatics::LoadGameFromMemory()](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp#L2077) and [UGameplayStatics::LoadGameFromSlot()](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp#L2150) on your project side.

-   `LoadGameFromSlot()` is the blueprint function you will call on the editor side. In its declaration, you need to add a WorldContext Parameter:

```cpp
// In .h file
UFUNCTION(..., meta = (WorldContext = "WorldContextObject",...))
... LoadGameFromSlot(UObject* WorldContext,...);
// In .cpp file you need to call your LoadGameFromMemory() with this object as parameter
LoadGameFromMemory(...,WorldContext WorldContextObject);
```

-   `LoadGameFromMemory()` is the c++ function that `LoadGameFromSlot()` should call and this is where you can add the world to the `USaveGame` object. Just between the [USaveGame instantiation](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp#L2102) and the call of [Serialize()](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp#L2105) method you need to add:

```cpp
// USaveGame instanciation
OutSaveGameObject->WorldContextObject = WorldContextObject;
// USaveGame::Serialize() call
```

And because life is not so easy, unfortunatly you have to copy/paste and include other dependencies...

First in your cpp header:

```cpp
#include "Misc/EngineVersion.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
```

and from the [UGameplayStatics](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp) you have to copy:

-   the static var [UE4_SAVEGAME_FILE_TYPE_TAG](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp#L52)
-   the full struct [FSaveGameFileVersion](https://github.com/EpicGames/UnrealEngine/blob/42d84f7d1f9c2147ad109179f268fd1542b2ccd2/Engine/Source/Runtime/Engine/Private/GameplayStatics.cpp#L75)

In [this post](https://answers.unrealengine.com/questions/958879/what-is-the-best-way-to-populate-usavegame-on-load.html) I've suggested 2 ways to simplify this process, but I still don't have any response.


### 4.3. Trigger Save/Load
<a id="markdown-trigger-saveload" name="trigger-saveload"></a>

Now you can use you special function to load game:

![save & load](./img/save-load.png)


## 5. Testing
<a id="markdown-testing" name="testing"></a>

They are 2 kinds of tests in this project:

-   [Google Test](https://github.com/google/googletest/) for **unit test** the core lib.
-   [UE4 automation tests](https://docs.unrealengine.com/en-US/Programming/Automation/TechnicalGuide/index.html) which I use more like **functionnal test** here.

In my workflow I use this project template https://github.com/NansPellicari/UE4-TPL-CppWithTestEnv to simplify all the testing settings, tests launches and to get nice reports.  
I invite you to using it if you want to [contribute](#6-contributing) to this project or quick testing these features.


### 5.1. Launch UE4 tests
<a id="markdown-launch-ue4-tests" name="launch-ue4-tests"></a>

All tests definitions begin with `Nans.TimelineSystem`, and for all plugins I made or will made tests defs are prefixed with `Nans` for simplicity sake.

If you don't want to use my [template](https://github.com/NansPellicari/UE4-TPL-CppWithTestEnv) repo, you can launch your tests with this command line:

```powershell
# this command must be launched from <YourUE4RootDir>/Engine/Binaries/Win<YourOsVersion> directory
UE4Editor-Cmd.exe "<YourProjectPath>\YourProject.uproject" -unattended -nopause -NullRHI -ExecCmds="Automation RunTests Nans.TimelineSystem; quit" -TestExit="Automation Test Queue Empty" -log -log=RunTests.log -ReportOutputPath="<YourProjectPath>\TheFolderYouWantForReports"
```


### 5.2. Make Google Tests works
<a id="markdown-make-google-tests-works" name="make-google-tests-works"></a>

After installing the https://github.com/NansPellicari/UE4-TPL-CppWithTestEnv following the [Step by step guide](https://github.com/NansPellicari/UE4-TPL-CppWithTestEnv#3-step-by-step-guide), you have to download this repo and dependencies as git submodules using this:

```powershell
# in your project root folder
git submodule add https://github.com/NansPellicari/UE4-TestsHelpers.git .\Plugins\NansUE4TestsHelpers
git submodule add https://github.com/NansPellicari/UE4-CoreHelpers.git .\Plugins\NansCoreHelpers
git submodule add https://github.com/NansPellicari/UE4-TimelineSystem.git .\Plugins\NansTimelineSystem
# this to place in the right directory and rename correctly
# the plugin's folder to avoid UE4 misconfiguration.
```

After that you just have to link tests located into the `GGTest` folder of the plugin from the **GoogleTestApp project** test's entry point like this:

```cpp
// in Source/Tests/GoogleTestApp/Private/Test.cpp
#define WITH_GG_TESTS = 1
#include "../../../Plugins/NansTimelineSystem/Source/GGTest/Timeline.test.cpp"
```

And that it!


## 6. Contributing
<a id="markdown-contributing" name="contributing"></a>

You are very welcome if you want to contribute.
I explain in [CONTRIBUTING.md](../CONTRIBUTING.md) what is the most comfortable way to me you can contribute.
