# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | Required to create a UE4 module
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | Required to create a UE4 module
`class `[`FTimelinePinFactory`](#classFTimelinePinFactory) | It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NTimeline`](#classNTimeline) | Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManagerBase](#classNTimelineManagerBase) class is dedicated to handle it.
`class `[`NTimelineEventBase`](#classNTimelineEventBase) | An abstract class to manage events which can be attached to a timeline.
`class `[`NTimelineManagerBase`](#classNTimelineManagerBase) | This class is the client for the [NTimeline](#classNTimeline) object. Its goal is to decoupled client interface with timeline management.
`class `[`NTimelineManagerFake`](#classNTimelineManagerFake) | This class is used for tests only
`class `[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin) | This class allows to create a dedicated pin to get names from [UNTimelineConfig](#classUNTimelineConfig).
`class `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake) | This class is used for tests only
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | This adapter is fitted to track time when player plays since the game is launched.
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | It tracks game session but refreshes when level changed.
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | It tracks realtime, it is not altered by pause or slowmo.
`class `[`UNTimelineAdapter`](#classUNTimelineAdapter) | The adapter for [NTimeline](#classNTimeline) object.
`class `[`UNTimelineBlueprintHelpers`](#classUNTimelineBlueprintHelpers) | A simple Blueprint Library class to manage Timeline creation.
`class `[`UNTimelineConfig`](#classUNTimelineConfig) | A simple configuration to ease timeline instanciation for developpers.
`class `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter) | Base abstract class to create [NTimelineEventBase](#classNTimelineEventBase) adapters (Blueprint or c++).
`class `[`UNTimelineEventAdapterFake`](#classUNTimelineEventAdapterFake) | This class is used for tests only
`class `[`UNTimelineGameInstance`](#classUNTimelineGameInstance) | This is a based class which need to be instanciated to get all the timeline configuration system works.
`class `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter) | This is the abstract adapter that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or c++.
`struct `[`FConfiguredTimeline`](#structFConfiguredTimeline) | This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.
`struct `[`FNEventRecord`](#structFNEventRecord) | This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) and a record object used for savegame.

# class `FNansTimelineSystemCoreModule` <a id="classFNansTimelineSystemCoreModule"></a>

```
class FNansTimelineSystemCoreModule
  : public IModuleInterface
```  

Required to create a UE4 module

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansTimelineSystemCoreModule_1a0367b574b1dfb4034956f94a7f06757d)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansTimelineSystemCoreModule_1a88a4f19c78774708a5e017da20c80e6e)`()` | IModuleInterface implementation

## Members

#### `public virtual void `[`StartupModule`](#classFNansTimelineSystemCoreModule_1a0367b574b1dfb4034956f94a7f06757d)`()` <a id="classFNansTimelineSystemCoreModule_1a0367b574b1dfb4034956f94a7f06757d"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansTimelineSystemCoreModule_1a88a4f19c78774708a5e017da20c80e6e)`()` <a id="classFNansTimelineSystemCoreModule_1a88a4f19c78774708a5e017da20c80e6e"></a>

IModuleInterface implementation

# class `FNansTimelineSystemUE4Module` <a id="classFNansTimelineSystemUE4Module"></a>

```
class FNansTimelineSystemUE4Module
  : public IModuleInterface
```  

Required to create a UE4 module

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansTimelineSystemUE4Module_1a8b5df09796b8c28fb25faea9f05d9363)`()` | IModuleInterface implementation

## Members

#### `public virtual void `[`StartupModule`](#classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235)`()` <a id="classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansTimelineSystemUE4Module_1a8b5df09796b8c28fb25faea9f05d9363)`()` <a id="classFNansTimelineSystemUE4Module_1a8b5df09796b8c28fb25faea9f05d9363"></a>

IModuleInterface implementation

# class `FTimelinePinFactory` <a id="classFTimelinePinFactory"></a>

```
class FTimelinePinFactory
  : public FGraphPanelPinFactory
```  

It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.

**See also**: [FNansTimelineSystemUE4Module::StartupModule()](#classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `NansTimelineSystemCore` <a id="classNansTimelineSystemCore"></a>

```
class NansTimelineSystemCore
  : public ModuleRules
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NansTimelineSystemCore`](#classNansTimelineSystemCore_1acee618440b9fce7d8dca175db67099ce)`(ReadOnlyTargetRules Target)` | 

## Members

#### `public inline  `[`NansTimelineSystemCore`](#classNansTimelineSystemCore_1acee618440b9fce7d8dca175db67099ce)`(ReadOnlyTargetRules Target)` <a id="classNansTimelineSystemCore_1acee618440b9fce7d8dca175db67099ce"></a>

# class `NansTimelineSystemUE4` <a id="classNansTimelineSystemUE4"></a>

```
class NansTimelineSystemUE4
  : public ModuleRules
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4_1a2afc62eae1322f281d15ae6fff754572)`(ReadOnlyTargetRules Target)` | 

## Members

#### `public inline  `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4_1a2afc62eae1322f281d15ae6fff754572)`(ReadOnlyTargetRules Target)` <a id="classNansTimelineSystemUE4_1a2afc62eae1322f281d15ae6fff754572"></a>

# class `NTimeline` <a id="classNTimeline"></a>

Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManagerBase](#classNTimelineManagerBase) class is dedicated to handle it.

**See also**: ./TimelineManagerBase.h

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimelineEventDelegate `[`EventExpired`](#classNTimeline_1a7eca090412c8d34e3c598d7769173040) | **See also**: [OnExpired()](#classNTimeline_1a5fa6f33a2b53e4bf6ac71381b36b9905)
`public  `[`NTimeline`](#classNTimeline_1a6f3d9119691eb4e6534ca495e85f9ea0)`(`[`NTimelineManagerBase`](#classNTimelineManagerBase)` * TimerManager,FName _Label)` | A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.
`public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` | Calls [Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
`public virtual bool `[`Attached`](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` | It creates a FEventTuple and calls [BeforeOnAttached()](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1) to checks if it can be attached and [AfterOnAttached()](#classNTimeline_1a427fef6206ba24c609a56884de4167e5) for any custom usages
`public virtual void `[`Attached`](#classNTimeline_1a404dbb01b58fff5746568ceac1226a0c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` | Same as [Attached(TSharedPtr<NTimelineEventBase> Event)](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6) but for a collection of objects.
`public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` | This method is mainly used for savegame serialization
`public virtual float `[`GetCurrentTime`](#classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1)`()` | Get CurrentTime
`public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` | Returns the FEventTuple collection
`public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` | Give a name to this timeline 
`public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` | Return the actual name
`public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` Tuple)` | This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6) methods to set data during runtime.
`public virtual void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`NotifyTick`](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.
`protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) | The name of this timeline
`protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) | It is computed internally in the [NotifyTick()](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) return.
`protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` | This to allow inherited adapters to have a default constructor
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | In case of specialisation needs to avoid the attach process in some cases
`protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | If needed to make some stats, analytics, trigger error,...
`protected inline virtual const float & `[`GetTickInterval`](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3)`() const` | This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.
`protected virtual void `[`OnExpired`](#classNTimeline_1a5fa6f33a2b53e4bf6ac71381b36b9905)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float & ExpiredTime,const int32 & Index)` | Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference
`typedef `[`FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) | An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time

## Members

#### `public FTimelineEventDelegate `[`EventExpired`](#classNTimeline_1a7eca090412c8d34e3c598d7769173040) <a id="classNTimeline_1a7eca090412c8d34e3c598d7769173040"></a>

**See also**: [OnExpired()](#classNTimeline_1a5fa6f33a2b53e4bf6ac71381b36b9905)

#### `public  `[`NTimeline`](#classNTimeline_1a6f3d9119691eb4e6534ca495e85f9ea0)`(`[`NTimelineManagerBase`](#classNTimelineManagerBase)` * TimerManager,FName _Label)` <a id="classNTimeline_1a6f3d9119691eb4e6534ca495e85f9ea0"></a>

A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.

#### Parameters
* `TimerManager` - Timer which manage all time behavior (tick, pause, stop, play,...) 

* `_Label` - (optionnal) The name of this timeline. If not provided it creates a name with a static incremented value.

#### `public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` <a id="classNTimeline_1adffcefb7fc7f2768021994f8730eb356"></a>

Calls [Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

#### `public virtual bool `[`Attached`](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` <a id="classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6"></a>

It creates a FEventTuple and calls [BeforeOnAttached()](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1) to checks if it can be attached and [AfterOnAttached()](#classNTimeline_1a427fef6206ba24c609a56884de4167e5) for any custom usages

#### Parameters
* `Event` - The event you want to put in the timeline stream

#### `public virtual void `[`Attached`](#classNTimeline_1a404dbb01b58fff5746568ceac1226a0c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` <a id="classNTimeline_1a404dbb01b58fff5746568ceac1226a0c"></a>

Same as [Attached(TSharedPtr<NTimelineEventBase> Event)](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6) but for a collection of objects.

#### `public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` <a id="classNTimeline_1a0411bf651e453dd5446074b11829654d"></a>

This method is mainly used for savegame serialization

#### `public virtual float `[`GetCurrentTime`](#classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1)`()` <a id="classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1"></a>

Get CurrentTime

#### `public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` <a id="classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6"></a>

Returns the FEventTuple collection

#### `public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` <a id="classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153"></a>

Give a name to this timeline 
#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` <a id="classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25"></a>

Return the actual name

#### `public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` Tuple)` <a id="classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec"></a>

This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6) methods to set data during runtime.

#### Parameters
* `Tuple` - Data which will be added to the Events TArray

#### `public virtual void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` <a id="classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8"></a>

This completely reset every events. It should be used with caution.

#### `public virtual void `[`NotifyTick`](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c)`()` <a id="classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c"></a>

This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.

#### `protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) <a id="classNTimeline_1a008f3afba683e14f05887e4df108c260"></a>

The name of this timeline

#### `protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) <a id="classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740"></a>

It is computed internally in the [NotifyTick()](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) return.

#### `protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` <a id="classNTimeline_1a6143741ff06add02f22ee82e5f1b6147"></a>

This to allow inherited adapters to have a default constructor

#### `protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1"></a>

In case of specialisation needs to avoid the attach process in some cases

#### `protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1a427fef6206ba24c609a56884de4167e5"></a>

If needed to make some stats, analytics, trigger error,...

#### `protected inline virtual const float & `[`GetTickInterval`](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3)`() const` <a id="classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3"></a>

This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.

#### `protected virtual void `[`OnExpired`](#classNTimeline_1a5fa6f33a2b53e4bf6ac71381b36b9905)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classNTimeline_1a5fa6f33a2b53e4bf6ac71381b36b9905"></a>

Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference

#### `typedef `[`FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) <a id="classNTimeline_1a632c8756e47d7e95507296250c40e6db"></a>

An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time

# class `NTimelineEventBase` <a id="classNTimelineEventBase"></a>

An abstract class to manage events which can be attached to a timeline.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Label`](#classNTimelineEventBase_1a35bb1df5489f8efaebfd9f36dfae42fe) | 
`public float `[`LocalTime`](#classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306) | 
`public float `[`StartedAt`](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903) | 
`public float `[`Duration`](#classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394) | 
`public float `[`Delay`](#classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78) | 
`public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a216c1203c83023a2549f1ae3276f6e41)`()` | Default ctor
`public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a046e029f6b108f7bf43fac60386a7031)`(FName _Label)` | Ctor to gives directly a name for this event.
`public virtual bool `[`IsExpired`](#classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7)`() const` | It computes with Duration and LocalTime
`public virtual const float `[`GetLocalTime`](#classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1)`() const` | Getter for LocalTime
`public virtual const float `[`GetStartedAt`](#classNTimelineEventBase_1a602096932bdacf10e984d52516a84486)`() const` | Getter for StartedAt
`public virtual float `[`GetDuration`](#classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f)`() const` | Getter for Duration
`public virtual void `[`Start`](#classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7)`(float StartTime)` | A setter for StartedAt
`public virtual void `[`NotifyAddTime`](#classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871)`(float NewTime)` | Increments LocalTime 
`public virtual float `[`GetDelay`](#classNTimelineEventBase_1a376d56329b872474913fa39487d97a69)`() const` | Increments LocalTime
`public virtual const FName `[`GetEventLabel`](#classNTimelineEventBase_1a4b274830671935a296d22df0b2f91b3a)`() const` | Getter for Label
`public virtual void `[`Clear`](#classNTimelineEventBase_1a589cb9a517e7cc59d1d95c7342d3156e)`()` | Reset all default data

## Members

#### `public FName `[`Label`](#classNTimelineEventBase_1a35bb1df5489f8efaebfd9f36dfae42fe) <a id="classNTimelineEventBase_1a35bb1df5489f8efaebfd9f36dfae42fe"></a>

#### `public float `[`LocalTime`](#classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306) <a id="classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306"></a>

#### `public float `[`StartedAt`](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903) <a id="classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903"></a>

#### `public float `[`Duration`](#classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394) <a id="classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394"></a>

#### `public float `[`Delay`](#classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78) <a id="classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78"></a>

#### `public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a216c1203c83023a2549f1ae3276f6e41)`()` <a id="classNTimelineEventBase_1a216c1203c83023a2549f1ae3276f6e41"></a>

Default ctor

#### `public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a046e029f6b108f7bf43fac60386a7031)`(FName _Label)` <a id="classNTimelineEventBase_1a046e029f6b108f7bf43fac60386a7031"></a>

Ctor to gives directly a name for this event.

#### `public virtual bool `[`IsExpired`](#classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7)`() const` <a id="classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7"></a>

It computes with Duration and LocalTime

#### `public virtual const float `[`GetLocalTime`](#classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1)`() const` <a id="classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1"></a>

Getter for LocalTime

#### `public virtual const float `[`GetStartedAt`](#classNTimelineEventBase_1a602096932bdacf10e984d52516a84486)`() const` <a id="classNTimelineEventBase_1a602096932bdacf10e984d52516a84486"></a>

Getter for StartedAt

#### `public virtual float `[`GetDuration`](#classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f)`() const` <a id="classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f"></a>

Getter for Duration

#### `public virtual void `[`Start`](#classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7)`(float StartTime)` <a id="classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7"></a>

A setter for StartedAt

#### `public virtual void `[`NotifyAddTime`](#classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871)`(float NewTime)` <a id="classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual float `[`GetDelay`](#classNTimelineEventBase_1a376d56329b872474913fa39487d97a69)`() const` <a id="classNTimelineEventBase_1a376d56329b872474913fa39487d97a69"></a>

Increments LocalTime

#### `public virtual const FName `[`GetEventLabel`](#classNTimelineEventBase_1a4b274830671935a296d22df0b2f91b3a)`() const` <a id="classNTimelineEventBase_1a4b274830671935a296d22df0b2f91b3a"></a>

Getter for Label

#### `public virtual void `[`Clear`](#classNTimelineEventBase_1a589cb9a517e7cc59d1d95c7342d3156e)`()` <a id="classNTimelineEventBase_1a589cb9a517e7cc59d1d95c7342d3156e"></a>

Reset all default data

# class `NTimelineManagerBase` <a id="classNTimelineManagerBase"></a>

This class is the client for the [NTimeline](#classNTimeline) object. Its goal is to decoupled client interface with timeline management.

* [NTimeline](#classNTimeline) manages time computation, notify events accordingly and save all states

* [NTimelineManagerBase](#classNTimelineManagerBase) manages client controls.

**See also**: [NTimeline](#classNTimeline)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NTimelineManagerBase`](#classNTimelineManagerBase_1a13e377bcc309051ae1ee3c5bfb15676d)`()` | Calls the [Init()](#classNTimelineManagerBase_1ac2e483be82d0d11125c217748a007e35) method.
`public virtual  `[`~NTimelineManagerBase`](#classNTimelineManagerBase_1aa0c078bc089e24f179512a91d2219a32)`()` | Calls [Clear()](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054) and release Timeline TSharedPtr
`public virtual void `[`Init`](#classNTimelineManagerBase_1ac2e483be82d0d11125c217748a007e35)`(FName _Label)` | Instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Pause`](#classNTimelineManagerBase_1a101a281c4e161a206b1677ce410464ab)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classNTimelineManagerBase_1a460e6b974a885f32e75c39c5d8fd2f50)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classNTimelineManagerBase_1a996371baf5dc0e51a32c14325c1c1091)`()` | This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0
`public virtual void `[`TimerTick`](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)`()` | This checks the actual play state (ENTimelineTimerState) and tick the [NTimeline](#classNTimeline) accordingly.
`public `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManagerBase_1aab80003c9c3e15446e3283f7884ad001)`()` | Get the actual state.
`public float `[`GetTickInterval`](#classNTimelineManagerBase_1a7c355c6bad3a84fb4e00f3f2ba0658b9)`()` | Get the tick interval which a timermanager should use to process
`public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classNTimelineManagerBase_1acf58e576105745b11d2a591cbf9cf530)`()` | Get the coupled [NTimeline](#classNTimeline)
`protected float `[`TickInterval`](#classNTimelineManagerBase_1a194b51bd0c7ac34786bc256b77218f8d) | The interval retrieve from the timeline.
`protected `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManagerBase_1aea2bb1bd9437ff032c686389a7734c1a) | The actual state
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classNTimelineManagerBase_1a1edf40f8bb3b300a8f3d6cb14e539c74) | The coupled timeline
`protected virtual void `[`Clear`](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054)`()` | Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
`protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManagerBase_1a14d64e5d6ed18abaf85d24f8c5f1a598)`()` | This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.
`protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerBase_1a34257aba82c08f245f2e2465a24d2071)`()` | This method is call immediately before ticking
`protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManagerBase_1aab9090f586908b3f53ab7938dda511c7)`()` | This method is call immediately after ticking
`protected void `[`SetTickInterval`](#classNTimelineManagerBase_1addc91da92ff0d218c8f677e1705483d2)`(const float _TickInterval)` | It is used by [NTimeline](#classNTimeline) to set its desired ticking interval TODO not a good idea, should be updatable by client for its needs

## Members

#### `public  `[`NTimelineManagerBase`](#classNTimelineManagerBase_1a13e377bcc309051ae1ee3c5bfb15676d)`()` <a id="classNTimelineManagerBase_1a13e377bcc309051ae1ee3c5bfb15676d"></a>

Calls the [Init()](#classNTimelineManagerBase_1ac2e483be82d0d11125c217748a007e35) method.

#### `public virtual  `[`~NTimelineManagerBase`](#classNTimelineManagerBase_1aa0c078bc089e24f179512a91d2219a32)`()` <a id="classNTimelineManagerBase_1aa0c078bc089e24f179512a91d2219a32"></a>

Calls [Clear()](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054) and release Timeline TSharedPtr

#### `public virtual void `[`Init`](#classNTimelineManagerBase_1ac2e483be82d0d11125c217748a007e35)`(FName _Label)` <a id="classNTimelineManagerBase_1ac2e483be82d0d11125c217748a007e35"></a>

Instanciate the embeded [NTimeline](#classNTimeline)

#### `public virtual void `[`Pause`](#classNTimelineManagerBase_1a101a281c4e161a206b1677ce410464ab)`()` <a id="classNTimelineManagerBase_1a101a281c4e161a206b1677ce410464ab"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classNTimelineManagerBase_1a460e6b974a885f32e75c39c5d8fd2f50)`()` <a id="classNTimelineManagerBase_1a460e6b974a885f32e75c39c5d8fd2f50"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classNTimelineManagerBase_1a996371baf5dc0e51a32c14325c1c1091)`()` <a id="classNTimelineManagerBase_1a996371baf5dc0e51a32c14325c1c1091"></a>

This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0

#### `public virtual void `[`TimerTick`](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)`()` <a id="classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865"></a>

This checks the actual play state (ENTimelineTimerState) and tick the [NTimeline](#classNTimeline) accordingly.

#### `public `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManagerBase_1aab80003c9c3e15446e3283f7884ad001)`()` <a id="classNTimelineManagerBase_1aab80003c9c3e15446e3283f7884ad001"></a>

Get the actual state.

#### `public float `[`GetTickInterval`](#classNTimelineManagerBase_1a7c355c6bad3a84fb4e00f3f2ba0658b9)`()` <a id="classNTimelineManagerBase_1a7c355c6bad3a84fb4e00f3f2ba0658b9"></a>

Get the tick interval which a timermanager should use to process

#### `public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classNTimelineManagerBase_1acf58e576105745b11d2a591cbf9cf530)`()` <a id="classNTimelineManagerBase_1acf58e576105745b11d2a591cbf9cf530"></a>

Get the coupled [NTimeline](#classNTimeline)

#### `protected float `[`TickInterval`](#classNTimelineManagerBase_1a194b51bd0c7ac34786bc256b77218f8d) <a id="classNTimelineManagerBase_1a194b51bd0c7ac34786bc256b77218f8d"></a>

The interval retrieve from the timeline.

#### `protected `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManagerBase_1aea2bb1bd9437ff032c686389a7734c1a) <a id="classNTimelineManagerBase_1aea2bb1bd9437ff032c686389a7734c1a"></a>

The actual state

#### `protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classNTimelineManagerBase_1a1edf40f8bb3b300a8f3d6cb14e539c74) <a id="classNTimelineManagerBase_1a1edf40f8bb3b300a8f3d6cb14e539c74"></a>

The coupled timeline

#### `protected virtual void `[`Clear`](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054)`()` <a id="classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054"></a>

Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

#### `protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManagerBase_1a14d64e5d6ed18abaf85d24f8c5f1a598)`()` <a id="classNTimelineManagerBase_1a14d64e5d6ed18abaf85d24f8c5f1a598"></a>

This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.

#### `protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerBase_1a34257aba82c08f245f2e2465a24d2071)`()` <a id="classNTimelineManagerBase_1a34257aba82c08f245f2e2465a24d2071"></a>

This method is call immediately before ticking

#### `protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManagerBase_1aab9090f586908b3f53ab7938dda511c7)`()` <a id="classNTimelineManagerBase_1aab9090f586908b3f53ab7938dda511c7"></a>

This method is call immediately after ticking

#### `protected void `[`SetTickInterval`](#classNTimelineManagerBase_1addc91da92ff0d218c8f677e1705483d2)`(const float _TickInterval)` <a id="classNTimelineManagerBase_1addc91da92ff0d218c8f677e1705483d2"></a>

It is used by [NTimeline](#classNTimeline) to set its desired ticking interval TODO not a good idea, should be updatable by client for its needs

# class `NTimelineManagerFake` <a id="classNTimelineManagerFake"></a>

```
class NTimelineManagerFake
  : public NTimelineManagerBase
```  

This class is used for tests only

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classNTimelineManagerFake_1ab98da0cd865c83d9efae36fffeb3d945) | 
`public FTimerDelegate `[`TimerDelegate`](#classNTimelineManagerFake_1af3aaef867edeed4bc74dcc7a395b22e5) | 
`public float `[`Counter`](#classNTimelineManagerFake_1a306140c2405b462aa14888d0c7f24d7b) | 
`public inline  `[`NTimelineManagerFake`](#classNTimelineManagerFake_1a08eefe10a89eeb974cfdcd125226fa9b)`()` | 
`public inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerFake_1a8e72a51addddb286486168ec28280705)`()` | This method is call immediately before ticking
`public inline virtual void `[`Clear`](#classNTimelineManagerFake_1a2d2f36ba2e92f7568093868d184e3ef6)`()` | Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

## Members

#### `public FTimerHandle `[`TimerHandle`](#classNTimelineManagerFake_1ab98da0cd865c83d9efae36fffeb3d945) <a id="classNTimelineManagerFake_1ab98da0cd865c83d9efae36fffeb3d945"></a>

#### `public FTimerDelegate `[`TimerDelegate`](#classNTimelineManagerFake_1af3aaef867edeed4bc74dcc7a395b22e5) <a id="classNTimelineManagerFake_1af3aaef867edeed4bc74dcc7a395b22e5"></a>

#### `public float `[`Counter`](#classNTimelineManagerFake_1a306140c2405b462aa14888d0c7f24d7b) <a id="classNTimelineManagerFake_1a306140c2405b462aa14888d0c7f24d7b"></a>

#### `public inline  `[`NTimelineManagerFake`](#classNTimelineManagerFake_1a08eefe10a89eeb974cfdcd125226fa9b)`()` <a id="classNTimelineManagerFake_1a08eefe10a89eeb974cfdcd125226fa9b"></a>

#### `public inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerFake_1a8e72a51addddb286486168ec28280705)`()` <a id="classNTimelineManagerFake_1a8e72a51addddb286486168ec28280705"></a>

This method is call immediately before ticking

#### `public inline virtual void `[`Clear`](#classNTimelineManagerFake_1a2d2f36ba2e92f7568093868d184e3ef6)`()` <a id="classNTimelineManagerFake_1a2d2f36ba2e92f7568093868d184e3ef6"></a>

Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

# class `SConfiguredTimelinePin` <a id="classSConfiguredTimelinePin"></a>

```
class SConfiguredTimelinePin
  : public SGraphPin
```  

This class allows to create a dedicated pin to get names from [UNTimelineConfig](#classUNTimelineConfig).

**See also**: [UNTimelineConfig](#classUNTimelineConfig)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SLATE_BEGIN_ARGS`](#classSConfiguredTimelinePin_1a664953bacc3ddafa43b7e2cdd54dba45)`(`[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin)`)` | 
`public void `[`Construct`](#classSConfiguredTimelinePin_1af56dc553ef07101c38d8b60365abd51e)`(const FArguments & InArgs,UEdGraphPin * InGraphPinObj)` | 
`protected virtual TSharedRef< SWidget > `[`GetDefaultValueWidget`](#classSConfiguredTimelinePin_1a5ca27fd0e2ce94e5a368c23373d6dd5a)`()` | 
`protected void `[`OnAttributeSelected`](#classSConfiguredTimelinePin_1ae05fe1b5c765e7b90aae22f9b5525ee6)`(TSharedPtr< FName > ItemSelected,ESelectInfo::Type SelectInfo)` | It is called by the combobox SNameComboBox::OnSelectionChanged() event. It checks selected data and saved it to the node.
`protected void `[`OnComboBoxOpening`](#classSConfiguredTimelinePin_1a226aa24934d74e20f8702f1d589eed14)`()` | It is called by the combobox SNameComboBox::OnComboBoxOpening() event. It checks if data selected is valid and set a the selected item for the combobox.
`protected TSharedPtr< FName > `[`GetSelectedName`](#classSConfiguredTimelinePin_1a2f71066ddab874e65cafc8fa1bfdb0b1)`() const` | Get the previous selected or default name from Names.
`protected void `[`SetPropertyWithName`](#classSConfiguredTimelinePin_1a6f0033e7fc6dc96ee5d47ec42ef9c61f)`(const FName & Name)` | It is called by [OnAttributeSelected()](#classSConfiguredTimelinePin_1ae05fe1b5c765e7b90aae22f9b5525ee6) only. It saves the selected name in the blueprint node.
`protected void `[`GetPropertyAsName`](#classSConfiguredTimelinePin_1ae4bfa613e83b6c32d079b5e3fe2058ec)`(FName & OutName) const` | It is called by [GetSelectedName()](#classSConfiguredTimelinePin_1a2f71066ddab874e65cafc8fa1bfdb0b1) only. Try to retrieve property from the GraphPin Object. 

## Members

#### `public inline  `[`SLATE_BEGIN_ARGS`](#classSConfiguredTimelinePin_1a664953bacc3ddafa43b7e2cdd54dba45)`(`[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin)`)` <a id="classSConfiguredTimelinePin_1a664953bacc3ddafa43b7e2cdd54dba45"></a>

#### `public void `[`Construct`](#classSConfiguredTimelinePin_1af56dc553ef07101c38d8b60365abd51e)`(const FArguments & InArgs,UEdGraphPin * InGraphPinObj)` <a id="classSConfiguredTimelinePin_1af56dc553ef07101c38d8b60365abd51e"></a>

#### `protected virtual TSharedRef< SWidget > `[`GetDefaultValueWidget`](#classSConfiguredTimelinePin_1a5ca27fd0e2ce94e5a368c23373d6dd5a)`()` <a id="classSConfiguredTimelinePin_1a5ca27fd0e2ce94e5a368c23373d6dd5a"></a>

#### `protected void `[`OnAttributeSelected`](#classSConfiguredTimelinePin_1ae05fe1b5c765e7b90aae22f9b5525ee6)`(TSharedPtr< FName > ItemSelected,ESelectInfo::Type SelectInfo)` <a id="classSConfiguredTimelinePin_1ae05fe1b5c765e7b90aae22f9b5525ee6"></a>

It is called by the combobox SNameComboBox::OnSelectionChanged() event. It checks selected data and saved it to the node.

#### `protected void `[`OnComboBoxOpening`](#classSConfiguredTimelinePin_1a226aa24934d74e20f8702f1d589eed14)`()` <a id="classSConfiguredTimelinePin_1a226aa24934d74e20f8702f1d589eed14"></a>

It is called by the combobox SNameComboBox::OnComboBoxOpening() event. It checks if data selected is valid and set a the selected item for the combobox.

#### `protected TSharedPtr< FName > `[`GetSelectedName`](#classSConfiguredTimelinePin_1a2f71066ddab874e65cafc8fa1bfdb0b1)`() const` <a id="classSConfiguredTimelinePin_1a2f71066ddab874e65cafc8fa1bfdb0b1"></a>

Get the previous selected or default name from Names.

#### `protected void `[`SetPropertyWithName`](#classSConfiguredTimelinePin_1a6f0033e7fc6dc96ee5d47ec42ef9c61f)`(const FName & Name)` <a id="classSConfiguredTimelinePin_1a6f0033e7fc6dc96ee5d47ec42ef9c61f"></a>

It is called by [OnAttributeSelected()](#classSConfiguredTimelinePin_1ae05fe1b5c765e7b90aae22f9b5525ee6) only. It saves the selected name in the blueprint node.

* 
#### Parameters
* `Name` - A FName reference which saved retrieved or default value.

#### `protected void `[`GetPropertyAsName`](#classSConfiguredTimelinePin_1ae4bfa613e83b6c32d079b5e3fe2058ec)`(FName & OutName) const` <a id="classSConfiguredTimelinePin_1ae4bfa613e83b6c32d079b5e3fe2058ec"></a>

It is called by [GetSelectedName()](#classSConfiguredTimelinePin_1a2f71066ddab874e65cafc8fa1bfdb0b1) only. Try to retrieve property from the GraphPin Object. 
#### Parameters
* `Name` - A FName reference which saved retrieved value.

# class `TimelineManagerTickableOnPauseFake` <a id="classTimelineManagerTickableOnPauseFake"></a>

```
class TimelineManagerTickableOnPauseFake
  : public NTimelineManagerBase
  : public FTickableGameObject
```  

This class is used for tests only

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Counter`](#classTimelineManagerTickableOnPauseFake_1a483f3ec73b04012d36e133041a8d0abd) | 
`public float `[`TotalLifeTime`](#classTimelineManagerTickableOnPauseFake_1a37d6baa007b2a483343e98903243eb2d) | 
`public float `[`LastTimeTick`](#classTimelineManagerTickableOnPauseFake_1a536acb38661c8751ab31cda61a995aba) | 
`public UWorld * `[`World`](#classTimelineManagerTickableOnPauseFake_1a4293e0b8cefa82f3121ec35d72689e06) | 
`public inline  `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake_1ae8c7cef4868a385204d4f24f73fed2fc)`(UWorld * _World)` | 
`public inline virtual bool `[`IsTickableWhenPaused`](#classTimelineManagerTickableOnPauseFake_1a64c71f133190b5de035e0fa1a4bf36cf)`() const` | 
`public inline virtual void `[`Tick`](#classTimelineManagerTickableOnPauseFake_1a726780b6116ebf1de654dccc462ec8d4)`(float DeltaTime)` | 
`public inline virtual bool `[`IsTickable`](#classTimelineManagerTickableOnPauseFake_1a075870b681cdca6dc49f4bb50c06db9c)`() const` | 
`public inline virtual void `[`onNotifyTimelineTickBefore`](#classTimelineManagerTickableOnPauseFake_1aaa08cfaf9f42b2d3b22307ccc02ff816)`()` | This method is call immediately before ticking
`public inline virtual TStatId `[`GetStatId`](#classTimelineManagerTickableOnPauseFake_1a9aa901ddef7820bf99e367cc410f1a27)`() const` | 
`public inline virtual UWorld * `[`GetTickableGameObjectWorld`](#classTimelineManagerTickableOnPauseFake_1a6d9c0af3f6a3aada468e32ae01f5ec4c)`() const` | 

## Members

#### `public float `[`Counter`](#classTimelineManagerTickableOnPauseFake_1a483f3ec73b04012d36e133041a8d0abd) <a id="classTimelineManagerTickableOnPauseFake_1a483f3ec73b04012d36e133041a8d0abd"></a>

#### `public float `[`TotalLifeTime`](#classTimelineManagerTickableOnPauseFake_1a37d6baa007b2a483343e98903243eb2d) <a id="classTimelineManagerTickableOnPauseFake_1a37d6baa007b2a483343e98903243eb2d"></a>

#### `public float `[`LastTimeTick`](#classTimelineManagerTickableOnPauseFake_1a536acb38661c8751ab31cda61a995aba) <a id="classTimelineManagerTickableOnPauseFake_1a536acb38661c8751ab31cda61a995aba"></a>

#### `public UWorld * `[`World`](#classTimelineManagerTickableOnPauseFake_1a4293e0b8cefa82f3121ec35d72689e06) <a id="classTimelineManagerTickableOnPauseFake_1a4293e0b8cefa82f3121ec35d72689e06"></a>

#### `public inline  `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake_1ae8c7cef4868a385204d4f24f73fed2fc)`(UWorld * _World)` <a id="classTimelineManagerTickableOnPauseFake_1ae8c7cef4868a385204d4f24f73fed2fc"></a>

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classTimelineManagerTickableOnPauseFake_1a64c71f133190b5de035e0fa1a4bf36cf)`() const` <a id="classTimelineManagerTickableOnPauseFake_1a64c71f133190b5de035e0fa1a4bf36cf"></a>

#### `public inline virtual void `[`Tick`](#classTimelineManagerTickableOnPauseFake_1a726780b6116ebf1de654dccc462ec8d4)`(float DeltaTime)` <a id="classTimelineManagerTickableOnPauseFake_1a726780b6116ebf1de654dccc462ec8d4"></a>

#### `public inline virtual bool `[`IsTickable`](#classTimelineManagerTickableOnPauseFake_1a075870b681cdca6dc49f4bb50c06db9c)`() const` <a id="classTimelineManagerTickableOnPauseFake_1a075870b681cdca6dc49f4bb50c06db9c"></a>

#### `public inline virtual void `[`onNotifyTimelineTickBefore`](#classTimelineManagerTickableOnPauseFake_1aaa08cfaf9f42b2d3b22307ccc02ff816)`()` <a id="classTimelineManagerTickableOnPauseFake_1aaa08cfaf9f42b2d3b22307ccc02ff816"></a>

This method is call immediately before ticking

#### `public inline virtual TStatId `[`GetStatId`](#classTimelineManagerTickableOnPauseFake_1a9aa901ddef7820bf99e367cc410f1a27)`() const` <a id="classTimelineManagerTickableOnPauseFake_1a9aa901ddef7820bf99e367cc410f1a27"></a>

#### `public inline virtual UWorld * `[`GetTickableGameObjectWorld`](#classTimelineManagerTickableOnPauseFake_1a6d9c0af3f6a3aada468e32ae01f5ec4c)`() const` <a id="classTimelineManagerTickableOnPauseFake_1a6d9c0af3f6a3aada468e32ae01f5ec4c"></a>

# class `UNGameLifeTimelineManager` <a id="classUNGameLifeTimelineManager"></a>

```
class UNGameLifeTimelineManager
  : public UNTimelineManagerBaseAdapter
```  

This adapter is fitted to track time when player plays since the game is launched.

It used internally an FTimerManager to tick and to works accordingly with all time alterations (game pause, slowmo, ...). It could be usefull for bonus/malus attribution which works during the full game session.

For example: Player makes a very benevolent actions which gives him a health bonus for 10 minutes in game.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) | Created by the FTimerManager
`public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) | Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)
`public virtual void `[`Init`](#classUNGameLifeTimelineManager_1abc4a66f9884b1af3ae470939d3f564a6)`(FName _Label)` | It creates the timer with a FTimerManager and attached TimerDelegate to it. 
`public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` | clears timer + unbind delegate + invalidate handle. It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor
`protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) | This is only used for savegame to keep time between sessions
`protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` | A default ctor for engine system

## Members

#### `public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) <a id="classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab"></a>

Created by the FTimerManager

#### `public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) <a id="classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61"></a>

Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)

#### `public virtual void `[`Init`](#classUNGameLifeTimelineManager_1abc4a66f9884b1af3ae470939d3f564a6)`(FName _Label)` <a id="classUNGameLifeTimelineManager_1abc4a66f9884b1af3ae470939d3f564a6"></a>

It creates the timer with a FTimerManager and attached TimerDelegate to it. 
#### Parameters
* `_Label` - Name of the timer

#### `public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` <a id="classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8"></a>

clears timer + unbind delegate + invalidate handle. It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor

#### `protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) <a id="classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4"></a>

This is only used for savegame to keep time between sessions

#### `protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` <a id="classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b"></a>

A default ctor for engine system

# class `UNLevelLifeTimelineManager` <a id="classUNLevelLifeTimelineManager"></a>

```
class UNLevelLifeTimelineManager
  : public UNGameLifeTimelineManager
```  

It tracks game session but refreshes when level changed.

It could be usefull for level bonus/malus attribution during a level session, or create a sheduled event.

For example:

* a player character take drugs and his capacities are altered for an amount of time

* player init a bomb and it should explosed in a determined time.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1aa21f092650d6adad0ac7c242f5c087fd)`(FName _Label)` | Attaches event on level changes It creates the timer with a FTimerManager and attached TimerDelegate to it. 
`public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` | This method to clear and reload timeline when level changed
`public void `[`OnLevelAdded`](#classUNLevelLifeTimelineManager_1a377ebe035faf84250cb3ac5416ae1fb7)`(ULevel * Level,UWorld * World)` | This method to clear and reload timeline when level changed
`public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75)`()` | This method to clear and reload timeline when level changed
`public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a464dbe9bdc4bd9380268f5cd71e2b897)`()` | Removes all attached events clears timer + unbind delegate + invalidate handle. It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor
`public virtual void `[`Serialize`](#classUNLevelLifeTimelineManager_1af8219c4c92afed8f7a45913235ef821f)`(FArchive & Ar)` | This only saves level name and checks
`protected FName `[`Label`](#classUNLevelLifeTimelineManager_1ab995fbe611974a32f0d09fcd2aec2513) | Used for savegame
`protected FString `[`LevelName`](#classUNLevelLifeTimelineManager_1a8141bcb7087a653bf7fa32509d12eab2) | Used for savegame to make a sanity check (verify if current world is the same as the load game)
`protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` | Default ctor
`protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` | WIP

## Members

#### `public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1aa21f092650d6adad0ac7c242f5c087fd)`(FName _Label)` <a id="classUNLevelLifeTimelineManager_1aa21f092650d6adad0ac7c242f5c087fd"></a>

Attaches event on level changes It creates the timer with a FTimerManager and attached TimerDelegate to it. 
#### Parameters
* `_Label` - Name of the timer

#### `public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` <a id="classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632"></a>

This method to clear and reload timeline when level changed

#### `public void `[`OnLevelAdded`](#classUNLevelLifeTimelineManager_1a377ebe035faf84250cb3ac5416ae1fb7)`(ULevel * Level,UWorld * World)` <a id="classUNLevelLifeTimelineManager_1a377ebe035faf84250cb3ac5416ae1fb7"></a>

This method to clear and reload timeline when level changed

#### `public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75)`()` <a id="classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75"></a>

This method to clear and reload timeline when level changed

#### `public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a464dbe9bdc4bd9380268f5cd71e2b897)`()` <a id="classUNLevelLifeTimelineManager_1a464dbe9bdc4bd9380268f5cd71e2b897"></a>

Removes all attached events clears timer + unbind delegate + invalidate handle. It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor

#### `public virtual void `[`Serialize`](#classUNLevelLifeTimelineManager_1af8219c4c92afed8f7a45913235ef821f)`(FArchive & Ar)` <a id="classUNLevelLifeTimelineManager_1af8219c4c92afed8f7a45913235ef821f"></a>

This only saves level name and checks

#### `protected FName `[`Label`](#classUNLevelLifeTimelineManager_1ab995fbe611974a32f0d09fcd2aec2513) <a id="classUNLevelLifeTimelineManager_1ab995fbe611974a32f0d09fcd2aec2513"></a>

Used for savegame

#### `protected FString `[`LevelName`](#classUNLevelLifeTimelineManager_1a8141bcb7087a653bf7fa32509d12eab2) <a id="classUNLevelLifeTimelineManager_1a8141bcb7087a653bf7fa32509d12eab2"></a>

Used for savegame to make a sanity check (verify if current world is the same as the load game)

#### `protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` <a id="classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839"></a>

Default ctor

#### `protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` <a id="classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb"></a>

WIP

# class `UNRealLifeTimelineManager` <a id="classUNRealLifeTimelineManager"></a>

```
class UNRealLifeTimelineManager
  : public UNTimelineManagerBaseAdapter
  : public FTickableGameObject
```  

It tracks realtime, it is not altered by pause or slowmo.

It could be useful for creating some bonus/malus which has a determinate times.

For example: A promo code which gives a market discount for 2 days.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FDateTime `[`CreationTime`](#classUNRealLifeTimelineManager_1a48e60566f34f0807ea0aebba3c648294) | It should be set only the first time the game is launched.
`public inline virtual void `[`Pause`](#classUNRealLifeTimelineManager_1ac2ec8f296c32a540bd6f91f3ea5f69f3)`()` | This do nothing. Excepts in our deepest dreams, we can't altered time in real life!!
`public inline virtual void `[`Play`](#classUNRealLifeTimelineManager_1a1a53b520ad6595e1314f044e6e59bc7d)`()` | This do nothing. Excepts in our deepest dreams, we can't altered time in real life!!
`public inline virtual void `[`Stop`](#classUNRealLifeTimelineManager_1acc4a988642b5ab6fa912706710eac2c3)`()` | This do nothing. Excepts in our deepest dreams, we can't altered time in real life!!
`public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a8408abf299f82de536717ac1e4018125)`(FName _Label)` | This just init State to "Play" and time variables. The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` | Always returns true 'cause it can be paused or stopped
`public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` | Always returns true 'cause it can be paused or stopped
`public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` | This override methods allows to tick [UNTimelineManagerBaseAdapter::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865) and to increment times vars.
`public inline virtual TStatId `[`GetStatId`](#classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25)`() const` | Required by FTickableGameObject.
`public virtual UWorld * `[`GetTickableGameObjectWorld`](#classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060)`() const` | 
`public virtual void `[`Serialize`](#classUNRealLifeTimelineManager_1a530e89eb20a2a984e5d532c7532aae76)`(FArchive & Ar)` | Used for save to retrieve last datetime and save it, for load to compute missing time during last saves and ticks accordingly.
`protected float `[`TotalLifeTime`](#classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584) | It tracks time (secs) since it has been created
`protected FDateTime `[`LastPlayTime`](#classUNRealLifeTimelineManager_1a083676a7926f5f527f000b3b4f3a1b89) | It tracks time (FDateTime) since it has been created
`protected float `[`LastTimeTick`](#classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08) | It tracks time (FDateTime) since timeline has been ticked 
`protected  `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52)`()` | Default ctor

## Members

#### `public FDateTime `[`CreationTime`](#classUNRealLifeTimelineManager_1a48e60566f34f0807ea0aebba3c648294) <a id="classUNRealLifeTimelineManager_1a48e60566f34f0807ea0aebba3c648294"></a>

It should be set only the first time the game is launched.

#### `public inline virtual void `[`Pause`](#classUNRealLifeTimelineManager_1ac2ec8f296c32a540bd6f91f3ea5f69f3)`()` <a id="classUNRealLifeTimelineManager_1ac2ec8f296c32a540bd6f91f3ea5f69f3"></a>

This do nothing. Excepts in our deepest dreams, we can't altered time in real life!!

#### `public inline virtual void `[`Play`](#classUNRealLifeTimelineManager_1a1a53b520ad6595e1314f044e6e59bc7d)`()` <a id="classUNRealLifeTimelineManager_1a1a53b520ad6595e1314f044e6e59bc7d"></a>

This do nothing. Excepts in our deepest dreams, we can't altered time in real life!!

#### `public inline virtual void `[`Stop`](#classUNRealLifeTimelineManager_1acc4a988642b5ab6fa912706710eac2c3)`()` <a id="classUNRealLifeTimelineManager_1acc4a988642b5ab6fa912706710eac2c3"></a>

This do nothing. Excepts in our deepest dreams, we can't altered time in real life!!

#### `public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a8408abf299f82de536717ac1e4018125)`(FName _Label)` <a id="classUNRealLifeTimelineManager_1a8408abf299f82de536717ac1e4018125"></a>

This just init State to "Play" and time variables. The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerBaseAdapter()](#classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2)

#### Parameters
* `_Label` - Name of the Timeline.

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` <a id="classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` <a id="classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` <a id="classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e"></a>

This override methods allows to tick [UNTimelineManagerBaseAdapter::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865) and to increment times vars.

#### Parameters
* `DeltaTime` - It is not used here, it used FDateTime::Now() - LastPlayTime to compute the real life delta time

#### `public inline virtual TStatId `[`GetStatId`](#classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25)`() const` <a id="classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25"></a>

Required by FTickableGameObject.

#### `public virtual UWorld * `[`GetTickableGameObjectWorld`](#classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060)`() const` <a id="classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060"></a>

#### `public virtual void `[`Serialize`](#classUNRealLifeTimelineManager_1a530e89eb20a2a984e5d532c7532aae76)`(FArchive & Ar)` <a id="classUNRealLifeTimelineManager_1a530e89eb20a2a984e5d532c7532aae76"></a>

Used for save to retrieve last datetime and save it, for load to compute missing time during last saves and ticks accordingly.

#### Parameters
* `Ar` - Used to saved binary data.

#### `protected float `[`TotalLifeTime`](#classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584) <a id="classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584"></a>

It tracks time (secs) since it has been created

#### `protected FDateTime `[`LastPlayTime`](#classUNRealLifeTimelineManager_1a083676a7926f5f527f000b3b4f3a1b89) <a id="classUNRealLifeTimelineManager_1a083676a7926f5f527f000b3b4f3a1b89"></a>

It tracks time (FDateTime) since it has been created

#### `protected float `[`LastTimeTick`](#classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08) <a id="classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08"></a>

It tracks time (FDateTime) since timeline has been ticked 
**See also**: [Tick()](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e) for usage.

#### `protected  `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52)`()` <a id="classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52"></a>

Default ctor

# class `UNTimelineAdapter` <a id="classUNTimelineAdapter"></a>

```
class UNTimelineAdapter
  : public UObject
  : public NTimeline
```  

The adapter for [NTimeline](#classNTimeline) object.

It manages:

* serialization

* attachment of [UNTimelineEventAdapter](#classUNTimelineEventAdapter) object to the embeded [NTimeline](#classNTimeline)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNTimelineAdapter`](#classUNTimelineAdapter_1a7ed83ce3cc2a1eb21347bc4ed675f9e4)`()` | Just a default ctor for UObject paradigme
`public virtual void `[`Init`](#classUNTimelineAdapter_1a09b97102e0fa1f410b3f86eb4de44975)`(`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * TimelineManager,FName _Label)` | this method is used to instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Clear`](#classUNTimelineAdapter_1af2a938dd80ceb1bda0d7bdf024438ad0)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`SetCurrentTime`](#classUNTimelineAdapter_1adf7ba90b6d70265258de964f7647e56e)`(float _CurrentTime)` | This method is mainly used for savegame serialization
`public virtual float `[`GetCurrentTime`](#classUNTimelineAdapter_1aeba89667659cdecc3f52ff7db923116c)`()` | Get CurrentTime
`public virtual void `[`SetLabel`](#classUNTimelineAdapter_1a4109af151689d0f04397dfc8bf213621)`(FName _Label)` | Give a name to this timeline 
`public virtual FName `[`GetLabel`](#classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495)`() const` | Return the actual name
`public virtual void `[`NotifyTick`](#classUNTimelineAdapter_1a30f47f32c8382b94541f96938e592009)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.
`public inline virtual bool `[`Attached`](#classUNTimelineAdapter_1a6243471ebd042f4ce5e46d0f40e315a0)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` | This object should works only with Adapters. This method is reserved for core objects. 
`public inline virtual void `[`Attached`](#classUNTimelineAdapter_1a491f5f752b4f22cf2d9642ba9755986c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` | This object should works only with Adapters. This method is reserved for core objects. 
`public virtual void `[`BeginDestroy`](#classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483)`()` | 
`public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classUNTimelineAdapter_1a99ff82b5d7046ecb96880bd9f5bc2174)`() const` | 
`public virtual bool `[`Attached`](#classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` | This method is made to work with adapters object. It will save data in the EventStore array for serialization and save game. 
`public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineAdapter_1a82e3c75c4a8da9468aeb760c7949dea9)`() const` | This retrieve the EventStore
`public void `[`OnEventExpired`](#classUNTimelineAdapter_1a81584d67d7a6bdee974c9fcf46b6b1d5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float & ExpiredTime,const int32 & Index)` | A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a7eca090412c8d34e3c598d7769173040). It controls the EventStore data refreshing.
`public virtual void `[`Serialize`](#classUNTimelineAdapter_1aad49188cf7383fb6bf6cf9cf9a26700f)`(FArchive & Ar)` | It used to save all events state in the EventStore, and reload them correclty.
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateNewEvent`](#classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` | Creates a new Event and use this timeline as the outer for this new object.
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineAdapter_1a8d571050be62d2ece357c4997bbbd9a3) | The embeded object
`protected virtual void `[`RefreshRecordData`](#classUNTimelineAdapter_1a63c8311fb81eb1c175ed26bcbbafe6eb)`(const int32 & Index)` | This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

## Members

#### `public inline  `[`UNTimelineAdapter`](#classUNTimelineAdapter_1a7ed83ce3cc2a1eb21347bc4ed675f9e4)`()` <a id="classUNTimelineAdapter_1a7ed83ce3cc2a1eb21347bc4ed675f9e4"></a>

Just a default ctor for UObject paradigme

#### `public virtual void `[`Init`](#classUNTimelineAdapter_1a09b97102e0fa1f410b3f86eb4de44975)`(`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * TimelineManager,FName _Label)` <a id="classUNTimelineAdapter_1a09b97102e0fa1f410b3f86eb4de44975"></a>

this method is used to instanciate the embeded [NTimeline](#classNTimeline)
#### Parameters
* `TimelineManager` - The Adapter which provide the [NTimelineManagerBase](#classNTimelineManagerBase) object.

#### `public virtual void `[`Clear`](#classUNTimelineAdapter_1af2a938dd80ceb1bda0d7bdf024438ad0)`()` <a id="classUNTimelineAdapter_1af2a938dd80ceb1bda0d7bdf024438ad0"></a>

This completely reset every events. It should be used with caution.

#### `public virtual void `[`SetCurrentTime`](#classUNTimelineAdapter_1adf7ba90b6d70265258de964f7647e56e)`(float _CurrentTime)` <a id="classUNTimelineAdapter_1adf7ba90b6d70265258de964f7647e56e"></a>

This method is mainly used for savegame serialization

#### `public virtual float `[`GetCurrentTime`](#classUNTimelineAdapter_1aeba89667659cdecc3f52ff7db923116c)`()` <a id="classUNTimelineAdapter_1aeba89667659cdecc3f52ff7db923116c"></a>

Get CurrentTime

#### `public virtual void `[`SetLabel`](#classUNTimelineAdapter_1a4109af151689d0f04397dfc8bf213621)`(FName _Label)` <a id="classUNTimelineAdapter_1a4109af151689d0f04397dfc8bf213621"></a>

Give a name to this timeline 
#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495)`() const` <a id="classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495"></a>

Return the actual name

#### `public virtual void `[`NotifyTick`](#classUNTimelineAdapter_1a30f47f32c8382b94541f96938e592009)`()` <a id="classUNTimelineAdapter_1a30f47f32c8382b94541f96938e592009"></a>

This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.

#### `public inline virtual bool `[`Attached`](#classUNTimelineAdapter_1a6243471ebd042f4ce5e46d0f40e315a0)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` <a id="classUNTimelineAdapter_1a6243471ebd042f4ce5e46d0f40e315a0"></a>

This object should works only with Adapters. This method is reserved for core objects. 
**See also**: [UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)](#classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f)

#### `public inline virtual void `[`Attached`](#classUNTimelineAdapter_1a491f5f752b4f22cf2d9642ba9755986c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` <a id="classUNTimelineAdapter_1a491f5f752b4f22cf2d9642ba9755986c"></a>

This object should works only with Adapters. This method is reserved for core objects. 
**See also**: [UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)](#classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f)

#### `public virtual void `[`BeginDestroy`](#classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483)`()` <a id="classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483"></a>

#### `public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classUNTimelineAdapter_1a99ff82b5d7046ecb96880bd9f5bc2174)`() const` <a id="classUNTimelineAdapter_1a99ff82b5d7046ecb96880bd9f5bc2174"></a>

#### `public virtual bool `[`Attached`](#classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` <a id="classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f"></a>

This method is made to work with adapters object. It will save data in the EventStore array for serialization and save game. 
#### Parameters
* `Event` - The adapter event

#### `public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineAdapter_1a82e3c75c4a8da9468aeb760c7949dea9)`() const` <a id="classUNTimelineAdapter_1a82e3c75c4a8da9468aeb760c7949dea9"></a>

This retrieve the EventStore

#### `public void `[`OnEventExpired`](#classUNTimelineAdapter_1a81584d67d7a6bdee974c9fcf46b6b1d5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classUNTimelineAdapter_1a81584d67d7a6bdee974c9fcf46b6b1d5"></a>

A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a7eca090412c8d34e3c598d7769173040). It controls the EventStore data refreshing.

#### Parameters
* `Event` - The native Event which will be killed 

* `ExpiredTime` - The time when this event expires 

* `Index` - The index of the NTimeline::Events array

#### `public virtual void `[`Serialize`](#classUNTimelineAdapter_1aad49188cf7383fb6bf6cf9cf9a26700f)`(FArchive & Ar)` <a id="classUNTimelineAdapter_1aad49188cf7383fb6bf6cf9cf9a26700f"></a>

It used to save all events state in the EventStore, and reload them correclty.

#### Parameters
* `Ar` - Archive for save and load

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateNewEvent`](#classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f"></a>

Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineAdapter_1a8d571050be62d2ece357c4997bbbd9a3) <a id="classUNTimelineAdapter_1a8d571050be62d2ece357c4997bbbd9a3"></a>

The embeded object

#### `protected virtual void `[`RefreshRecordData`](#classUNTimelineAdapter_1a63c8311fb81eb1c175ed26bcbbafe6eb)`(const int32 & Index)` <a id="classUNTimelineAdapter_1a63c8311fb81eb1c175ed26bcbbafe6eb"></a>

This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

#### Parameters
* `Index` - The index of the NTimeline::Events array 

* `Record` - The record you want to synchronize.

# class `UNTimelineBlueprintHelpers` <a id="classUNTimelineBlueprintHelpers"></a>

```
class UNTimelineBlueprintHelpers
  : public UBlueprintFunctionLibrary
```  

A simple Blueprint Library class to manage Timeline creation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNTimelineConfig` <a id="classUNTimelineConfig"></a>

```
class UNTimelineConfig
  : public UDeveloperSettings
```  

A simple configuration to ease timeline instanciation for developpers.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TArray< `[`FConfiguredTimeline`](#structFConfiguredTimeline)` > `[`ConfiguredTimeline`](#classUNTimelineConfig_1a774b18fcf703d79e6f13839986b849b2) | 

## Members

#### `public TArray< `[`FConfiguredTimeline`](#structFConfiguredTimeline)` > `[`ConfiguredTimeline`](#classUNTimelineConfig_1a774b18fcf703d79e6f13839986b849b2) <a id="classUNTimelineConfig_1a774b18fcf703d79e6f13839986b849b2"></a>

# class `UNTimelineEventAdapter` <a id="classUNTimelineEventAdapter"></a>

```
class UNTimelineEventAdapter
  : public UObject
  : public NTimelineEventBase
```  

Base abstract class to create [NTimelineEventBase](#classNTimelineEventBase) adapters (Blueprint or c++).

For a simple usage with blueprint: you can derived blueprint base on this. This way the [NTimelineEventBase](#classNTimelineEventBase) instance should only manage timeline behavior.

For a more complex usage in c++: You should derive this and [NTimelineEventBase](#classNTimelineEventBase) too to fit on your needs.

* This class should only manage specifics behaviors related to the engine (serialization, blueprint's specifics functionnalities, etc...)

* [NTimelineEventBase](#classNTimelineEventBase)'s derivation: all your core functionnalities

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual bool `[`IsExpired`](#classUNTimelineEventAdapter_1a28740a23b48d5e5bb506741d38cdc863)`() const` | It computes with Duration and LocalTime
`public virtual const float `[`GetLocalTime`](#classUNTimelineEventAdapter_1a2edf2ce0df1c79f1df430c30b26b5074)`() const` | Getter for LocalTime
`public virtual const float `[`GetStartedAt`](#classUNTimelineEventAdapter_1abcecdb2fb024edfe779d1481a6cd383b)`() const` | Getter for StartedAt
`public virtual float `[`GetDuration`](#classUNTimelineEventAdapter_1a5d748f27c66c9b529ecf49f7f568b0c7)`() const` | Getter for Duration
`public virtual void `[`Start`](#classUNTimelineEventAdapter_1a35d26f8b38840360f13bcfac5830b391)`(float StartTime)` | A setter for StartedAt
`public virtual void `[`NotifyAddTime`](#classUNTimelineEventAdapter_1a6d59680a996c8dd837fd7e2fce248cf3)`(float NewTime)` | Increments LocalTime 
`public virtual float `[`GetDelay`](#classUNTimelineEventAdapter_1a0594d2318fe3c9ab3e965d9bda437292)`() const` | Increments LocalTime
`public virtual const FName `[`GetEventLabel`](#classUNTimelineEventAdapter_1a30ef331e61d220bcac0e1995cd78a26c)`() const` | Getter for Label
`public virtual void `[`BeginDestroy`](#classUNTimelineEventAdapter_1a8cf301901a7d6a6e0bd2aa107e7f85fd)`()` | 
`public virtual void `[`Serialize`](#classUNTimelineEventAdapter_1ab523da9edf384ad0bd7829806db63b53)`(FArchive & Ar)` | 
`public void `[`SetDelay`](#classUNTimelineEventAdapter_1ac377c3c48141d6c44bfa459c5d148d31)`(float _Delay)` | 
`public void `[`SetDuration`](#classUNTimelineEventAdapter_1aa90a54d717511260c722ce87f3a31ec7)`(float _Duration)` | 
`public virtual void `[`Init`](#classUNTimelineEventAdapter_1a8bb42c0d06a213c57128b2ec9e447e8a)`(FName _Label)` | This is where the Core object is instanciated. You should override this to instanciate your derived core object.
`public TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`GetEvent`](#classUNTimelineEventAdapter_1a973ca8f2607f42407d87316786061000)`()` | This is used by other adapters which need to pass the core object to their own. 
`protected TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`Event`](#classUNTimelineEventAdapter_1a9308593395993b79ad1ecb8bbe5ec446) | The actual adapter is for this object. It shoulds be instanciate on a ctor or a dedicated init function
`protected inline  `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter_1a40a87f0b1504ff4eb90fc97ced767d2f)`()` | Default ctor for the engine

## Members

#### `public virtual bool `[`IsExpired`](#classUNTimelineEventAdapter_1a28740a23b48d5e5bb506741d38cdc863)`() const` <a id="classUNTimelineEventAdapter_1a28740a23b48d5e5bb506741d38cdc863"></a>

It computes with Duration and LocalTime

#### `public virtual const float `[`GetLocalTime`](#classUNTimelineEventAdapter_1a2edf2ce0df1c79f1df430c30b26b5074)`() const` <a id="classUNTimelineEventAdapter_1a2edf2ce0df1c79f1df430c30b26b5074"></a>

Getter for LocalTime

#### `public virtual const float `[`GetStartedAt`](#classUNTimelineEventAdapter_1abcecdb2fb024edfe779d1481a6cd383b)`() const` <a id="classUNTimelineEventAdapter_1abcecdb2fb024edfe779d1481a6cd383b"></a>

Getter for StartedAt

#### `public virtual float `[`GetDuration`](#classUNTimelineEventAdapter_1a5d748f27c66c9b529ecf49f7f568b0c7)`() const` <a id="classUNTimelineEventAdapter_1a5d748f27c66c9b529ecf49f7f568b0c7"></a>

Getter for Duration

#### `public virtual void `[`Start`](#classUNTimelineEventAdapter_1a35d26f8b38840360f13bcfac5830b391)`(float StartTime)` <a id="classUNTimelineEventAdapter_1a35d26f8b38840360f13bcfac5830b391"></a>

A setter for StartedAt

#### `public virtual void `[`NotifyAddTime`](#classUNTimelineEventAdapter_1a6d59680a996c8dd837fd7e2fce248cf3)`(float NewTime)` <a id="classUNTimelineEventAdapter_1a6d59680a996c8dd837fd7e2fce248cf3"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual float `[`GetDelay`](#classUNTimelineEventAdapter_1a0594d2318fe3c9ab3e965d9bda437292)`() const` <a id="classUNTimelineEventAdapter_1a0594d2318fe3c9ab3e965d9bda437292"></a>

Increments LocalTime

#### `public virtual const FName `[`GetEventLabel`](#classUNTimelineEventAdapter_1a30ef331e61d220bcac0e1995cd78a26c)`() const` <a id="classUNTimelineEventAdapter_1a30ef331e61d220bcac0e1995cd78a26c"></a>

Getter for Label

#### `public virtual void `[`BeginDestroy`](#classUNTimelineEventAdapter_1a8cf301901a7d6a6e0bd2aa107e7f85fd)`()` <a id="classUNTimelineEventAdapter_1a8cf301901a7d6a6e0bd2aa107e7f85fd"></a>

#### `public virtual void `[`Serialize`](#classUNTimelineEventAdapter_1ab523da9edf384ad0bd7829806db63b53)`(FArchive & Ar)` <a id="classUNTimelineEventAdapter_1ab523da9edf384ad0bd7829806db63b53"></a>

#### `public void `[`SetDelay`](#classUNTimelineEventAdapter_1ac377c3c48141d6c44bfa459c5d148d31)`(float _Delay)` <a id="classUNTimelineEventAdapter_1ac377c3c48141d6c44bfa459c5d148d31"></a>

#### `public void `[`SetDuration`](#classUNTimelineEventAdapter_1aa90a54d717511260c722ce87f3a31ec7)`(float _Duration)` <a id="classUNTimelineEventAdapter_1aa90a54d717511260c722ce87f3a31ec7"></a>

#### `public virtual void `[`Init`](#classUNTimelineEventAdapter_1a8bb42c0d06a213c57128b2ec9e447e8a)`(FName _Label)` <a id="classUNTimelineEventAdapter_1a8bb42c0d06a213c57128b2ec9e447e8a"></a>

This is where the Core object is instanciated. You should override this to instanciate your derived core object.

#### `public TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`GetEvent`](#classUNTimelineEventAdapter_1a973ca8f2607f42407d87316786061000)`()` <a id="classUNTimelineEventAdapter_1a973ca8f2607f42407d87316786061000"></a>

This is used by other adapters which need to pass the core object to their own. 
**See also**: [UNTimelineAdapter::Attached()](#classUNTimelineAdapter_1a6243471ebd042f4ce5e46d0f40e315a0)

#### `protected TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`Event`](#classUNTimelineEventAdapter_1a9308593395993b79ad1ecb8bbe5ec446) <a id="classUNTimelineEventAdapter_1a9308593395993b79ad1ecb8bbe5ec446"></a>

The actual adapter is for this object. It shoulds be instanciate on a ctor or a dedicated init function

#### `protected inline  `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter_1a40a87f0b1504ff4eb90fc97ced767d2f)`()` <a id="classUNTimelineEventAdapter_1a40a87f0b1504ff4eb90fc97ced767d2f"></a>

Default ctor for the engine

# class `UNTimelineEventAdapterFake` <a id="classUNTimelineEventAdapterFake"></a>

```
class UNTimelineEventAdapterFake
  : public UNTimelineEventAdapter
```  

This class is used for tests only

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNTimelineGameInstance` <a id="classUNTimelineGameInstance"></a>

```
class UNTimelineGameInstance
  : public UGameInstance
```  

This is a based class which need to be instanciated to get all the timeline configuration system works.

This is the main client which instances Configured Timeline ([UNTimelineConfig](#classUNTimelineConfig)) and [UNTimelineBlueprintHelpers::CreateAndAttachedEvent()](#classUNTimelineBlueprintHelpers_1a2bb5aa6b0a319b571d70c95b42b290ba) used.

**See also**: [UNTimelineBlueprintHelpers::CreateAndAttachedEvent()](#classUNTimelineBlueprintHelpers_1a2bb5aa6b0a319b571d70c95b42b290ba). 

**See also**: [UNTimelineConfig](#classUNTimelineConfig) to get more details on the configuration. 

**See also**: [FConfiguredTimeline](#structFConfiguredTimeline) to see how to use Configured Timeline as blueprint pins. 

**See also**:

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UNTimelineGameInstance`](#classUNTimelineGameInstance_1a17798fb14e8987739ea8ed59c7280ed3)`()` | 
`public virtual void `[`Init`](#classUNTimelineGameInstance_1a018b557362d4743c76f702f098d5c9db)`()` | 
`public `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * `[`GetTimeline`](#classUNTimelineGameInstance_1afb3e6a9414f1690c7620811b0d81be53)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` | A blueprint pass-through for GetTimeline(FName Name).
`public `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * `[`GetTimeline`](#classUNTimelineGameInstance_1a66c32d7df097c894dc3e23ec2c6a3aaf)`(FName Name) const` | Get the timeline from TimelinesCollection by its name.
`public virtual void `[`Serialize`](#classUNTimelineGameInstance_1a391fee3c32abfabece1aea48370f3474)`(FArchive & Ar)` | It used to save all timelines in the EventStore, and reload them correctly.
`protected TMap< FName, `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * > `[`TimelinesCollection`](#classUNTimelineGameInstance_1a621b37e844575551fc13863e32106cb0) | Collection of timelines instanciated by [InstanciateTimelinesFromConfig()](#classUNTimelineGameInstance_1a32162d7c7503f2d9365665676ed55df8)
`protected void `[`InstanciateTimelinesFromConfig`](#classUNTimelineGameInstance_1a32162d7c7503f2d9365665676ed55df8)`()` | This method allows to instanciate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).

## Members

#### `public  `[`UNTimelineGameInstance`](#classUNTimelineGameInstance_1a17798fb14e8987739ea8ed59c7280ed3)`()` <a id="classUNTimelineGameInstance_1a17798fb14e8987739ea8ed59c7280ed3"></a>

#### `public virtual void `[`Init`](#classUNTimelineGameInstance_1a018b557362d4743c76f702f098d5c9db)`()` <a id="classUNTimelineGameInstance_1a018b557362d4743c76f702f098d5c9db"></a>

#### `public `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * `[`GetTimeline`](#classUNTimelineGameInstance_1afb3e6a9414f1690c7620811b0d81be53)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` <a id="classUNTimelineGameInstance_1afb3e6a9414f1690c7620811b0d81be53"></a>

A blueprint pass-through for GetTimeline(FName Name).

#### Parameters
* `Config` - To allow having a combobox of configured timeline

#### `public `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * `[`GetTimeline`](#classUNTimelineGameInstance_1a66c32d7df097c894dc3e23ec2c6a3aaf)`(FName Name) const` <a id="classUNTimelineGameInstance_1a66c32d7df097c894dc3e23ec2c6a3aaf"></a>

Get the timeline from TimelinesCollection by its name.

#### Parameters
* `Name` - The name of the timeline

#### `public virtual void `[`Serialize`](#classUNTimelineGameInstance_1a391fee3c32abfabece1aea48370f3474)`(FArchive & Ar)` <a id="classUNTimelineGameInstance_1a391fee3c32abfabece1aea48370f3474"></a>

It used to save all timelines in the EventStore, and reload them correctly.

#### Parameters
* `Ar` - Archive for save and load

#### `protected TMap< FName, `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * > `[`TimelinesCollection`](#classUNTimelineGameInstance_1a621b37e844575551fc13863e32106cb0) <a id="classUNTimelineGameInstance_1a621b37e844575551fc13863e32106cb0"></a>

Collection of timelines instanciated by [InstanciateTimelinesFromConfig()](#classUNTimelineGameInstance_1a32162d7c7503f2d9365665676ed55df8)

#### `protected void `[`InstanciateTimelinesFromConfig`](#classUNTimelineGameInstance_1a32162d7c7503f2d9365665676ed55df8)`()` <a id="classUNTimelineGameInstance_1a32162d7c7503f2d9365665676ed55df8"></a>

This method allows to instanciate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).

**See also**: [FConfiguredTimeline](#structFConfiguredTimeline)

# class `UNTimelineManagerBaseAdapter` <a id="classUNTimelineManagerBaseAdapter"></a>

```
class UNTimelineManagerBaseAdapter
  : public UObject
  : public NTimelineManagerBase
```  

This is the abstract adapter that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or c++.

As the close relation between [NTimelineManagerBase](#classNTimelineManagerBase) and [NTimeline](#classNTimeline) classes (core lib), This class is coupled with [UNTimelineAdapter](#classUNTimelineAdapter). 
**See also**: [UNTimelineAdapter](#classUNTimelineAdapter)

To ease blueprint usages, most of the [UNTimelineAdapter](#classUNTimelineAdapter) public functionnalities are accessible here. This class works as a pass-through too for [UNTimelineAdapter](#classUNTimelineAdapter).

**See also**: [AddEvent()](#classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b), [CreateNewEvent()](#classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090), [CreateAndAddNewEvent()](#classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`GetTimelineTime`](#classUNTimelineManagerBaseAdapter_1aabf4d6fde13157e6a077a38924e71fa3)`()` | 
`public virtual void `[`Pause`](#classUNTimelineManagerBaseAdapter_1a2e0332fa1d87dd748c1cabc95eeac57c)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classUNTimelineManagerBaseAdapter_1aef1c9e06835c27dd5b6c1e560e86400c)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classUNTimelineManagerBaseAdapter_1a2b8a8572ced774ff4620b3618f9fb1f7)`()` | This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0
`public virtual void `[`Init`](#classUNTimelineManagerBaseAdapter_1a9f65529724871fbcff2cd2661c666ef2)`(FName _Label)` | The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerBaseAdapter_1a1c4949fa6318f2099b7f7b0c7ad6fa87)`()` | 
`public virtual void `[`Serialize`](#classUNTimelineManagerBaseAdapter_1af1e0474d3149d21daae82845e20b1538)`(FArchive & Ar)` | It's the starting link of serialization chain for all embeded adapters. This calls [UNTimelineAdapter::Serialize()](#classUNTimelineAdapter_1aad49188cf7383fb6bf6cf9cf9a26700f).
`public virtual void `[`BeginDestroy`](#classUNTimelineManagerBaseAdapter_1addc22251c326e4749a1556f570fc152f)`()` | This call the [UNTimelineAdapter::BeginDestroy()](#classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483) too.
`public FName `[`GetLabel`](#classUNTimelineManagerBaseAdapter_1a892ced4f4e11f8ac1c76c48c96fe2631)`() const` | A pass-through for the embeded [UNTimelineAdapter::GetLabel()](#classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495)
`public virtual void `[`Clear`](#classUNTimelineManagerBaseAdapter_1a8a395d8909138fc37508920dd50a80d0)`()` | It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor
`public virtual void `[`AddEvent`](#classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` | Adds an event to the timeline object, it works as a pass-through for [UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)](#classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f)
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateNewEvent`](#classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` | A pass-through for [UNTimelineAdapter::CreateNewEvent()](#classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f): Creates a new Event and use this timeline as the outer for this new object.
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` | Attaches the event to the timeline stream + A pass-through for [UNTimelineAdapter::CreateNewEvent()](#classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f): Creates a new Event and use this timeline as the outer for this new object.
`protected `[`UNTimelineAdapter`](#classUNTimelineAdapter)` * `[`MyTimeline`](#classUNTimelineManagerBaseAdapter_1aac02c9c645fca4bc75afccc4c7946239) | the timeline associated to this manager.
`protected  `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2)`()` | Protected ctor to force instanciation with [CreateObject()](#classUNTimelineManagerBaseAdapter_1a1179cbca2e3f193f1db66b0a53c9c6c0) methods (factory methods).

## Members

#### `public float `[`GetTimelineTime`](#classUNTimelineManagerBaseAdapter_1aabf4d6fde13157e6a077a38924e71fa3)`()` <a id="classUNTimelineManagerBaseAdapter_1aabf4d6fde13157e6a077a38924e71fa3"></a>

#### `public virtual void `[`Pause`](#classUNTimelineManagerBaseAdapter_1a2e0332fa1d87dd748c1cabc95eeac57c)`()` <a id="classUNTimelineManagerBaseAdapter_1a2e0332fa1d87dd748c1cabc95eeac57c"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classUNTimelineManagerBaseAdapter_1aef1c9e06835c27dd5b6c1e560e86400c)`()` <a id="classUNTimelineManagerBaseAdapter_1aef1c9e06835c27dd5b6c1e560e86400c"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classUNTimelineManagerBaseAdapter_1a2b8a8572ced774ff4620b3618f9fb1f7)`()` <a id="classUNTimelineManagerBaseAdapter_1a2b8a8572ced774ff4620b3618f9fb1f7"></a>

This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0

#### `public virtual void `[`Init`](#classUNTimelineManagerBaseAdapter_1a9f65529724871fbcff2cd2661c666ef2)`(FName _Label)` <a id="classUNTimelineManagerBaseAdapter_1a9f65529724871fbcff2cd2661c666ef2"></a>

The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerBaseAdapter()](#classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2)

#### Parameters
* `_Label` - Name of the Timeline.

#### `public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerBaseAdapter_1a1c4949fa6318f2099b7f7b0c7ad6fa87)`()` <a id="classUNTimelineManagerBaseAdapter_1a1c4949fa6318f2099b7f7b0c7ad6fa87"></a>

#### `public virtual void `[`Serialize`](#classUNTimelineManagerBaseAdapter_1af1e0474d3149d21daae82845e20b1538)`(FArchive & Ar)` <a id="classUNTimelineManagerBaseAdapter_1af1e0474d3149d21daae82845e20b1538"></a>

It's the starting link of serialization chain for all embeded adapters. This calls [UNTimelineAdapter::Serialize()](#classUNTimelineAdapter_1aad49188cf7383fb6bf6cf9cf9a26700f).

#### Parameters
* `Ar` - the FArchive used for serialization as usual.

#### `public virtual void `[`BeginDestroy`](#classUNTimelineManagerBaseAdapter_1addc22251c326e4749a1556f570fc152f)`()` <a id="classUNTimelineManagerBaseAdapter_1addc22251c326e4749a1556f570fc152f"></a>

This call the [UNTimelineAdapter::BeginDestroy()](#classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483) too.

#### `public FName `[`GetLabel`](#classUNTimelineManagerBaseAdapter_1a892ced4f4e11f8ac1c76c48c96fe2631)`() const` <a id="classUNTimelineManagerBaseAdapter_1a892ced4f4e11f8ac1c76c48c96fe2631"></a>

A pass-through for the embeded [UNTimelineAdapter::GetLabel()](#classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495)

#### `public virtual void `[`Clear`](#classUNTimelineManagerBaseAdapter_1a8a395d8909138fc37508920dd50a80d0)`()` <a id="classUNTimelineManagerBaseAdapter_1a8a395d8909138fc37508920dd50a80d0"></a>

It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor

#### `public virtual void `[`AddEvent`](#classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` <a id="classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b"></a>

Adds an event to the timeline object, it works as a pass-through for [UNTimelineAdapter::Attached(UNTimelineEventAdapter* Event)](#classUNTimelineAdapter_1a4722e92203b76813619f2f406cfd303f)

#### Parameters
* `Event` - An Event object you want to saved to the associated timeline.

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateNewEvent`](#classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090"></a>

A pass-through for [UNTimelineAdapter::CreateNewEvent()](#classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f): Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee"></a>

Attaches the event to the timeline stream + A pass-through for [UNTimelineAdapter::CreateNewEvent()](#classUNTimelineAdapter_1acba2a168a61528541570ed3b28f37d2f): Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected `[`UNTimelineAdapter`](#classUNTimelineAdapter)` * `[`MyTimeline`](#classUNTimelineManagerBaseAdapter_1aac02c9c645fca4bc75afccc4c7946239) <a id="classUNTimelineManagerBaseAdapter_1aac02c9c645fca4bc75afccc4c7946239"></a>

the timeline associated to this manager.

#### `protected  `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2)`()` <a id="classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2"></a>

Protected ctor to force instanciation with [CreateObject()](#classUNTimelineManagerBaseAdapter_1a1179cbca2e3f193f1db66b0a53c9c6c0) methods (factory methods).

It instanciates the embeded timeline with CreateDefaultSubobject().

# struct `FConfiguredTimeline` <a id="structFConfiguredTimeline"></a>

This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) | This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.
`public TSubclassOf< `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` > `[`TimelineClass`](#structFConfiguredTimeline_1a9906cfb09dd5d0c48f9ea8cbe1cb18c5) | The Configured Timeline class

## Members

#### `public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) <a id="structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6"></a>

This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.

#### `public TSubclassOf< `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` > `[`TimelineClass`](#structFConfiguredTimeline_1a9906cfb09dd5d0c48f9ea8cbe1cb18c5) <a id="structFConfiguredTimeline_1a9906cfb09dd5d0c48f9ea8cbe1cb18c5"></a>

The Configured Timeline class

# struct `FNEventRecord` <a id="structFNEventRecord"></a>

This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) and a record object used for savegame.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`Event`](#structFNEventRecord_1abf41bbc0f564bb53be473f13c9e28f86) | The [UNTimelineEventAdapter](#classUNTimelineEventAdapter) object
`public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) | The time it as been attached to the timeline in secs (differ to [UNTimelineEventAdapter::StartedAt](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903))
`public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) | The delay before starting in secs
`public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) | The duration this event lives in secs (0 means inderterminate)
`public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) | The name of the event
`public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) | Expiration time of this event in secs (0 means can't expired))
`public FString `[`EventClassName`](#structFNEventRecord_1a5ebb6654bd18ffe427e104f74fd9ba93) | This is used only for serialization, it allow to re-instance the object on load
`public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` | 
`public inline  `[`FNEventRecord`](#structFNEventRecord_1ac73fc2cb4bd8bb046b456a04337112fb)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` | 
`public void `[`Serialize`](#structFNEventRecord_1a0205d63d21092bc352c8836d29a51d23)`(FArchive & Ar,`[`UNTimelineAdapter`](#classUNTimelineAdapter)` * Timeline)` | It manages Event object saving and loading

## Members

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`Event`](#structFNEventRecord_1abf41bbc0f564bb53be473f13c9e28f86) <a id="structFNEventRecord_1abf41bbc0f564bb53be473f13c9e28f86"></a>

The [UNTimelineEventAdapter](#classUNTimelineEventAdapter) object

#### `public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) <a id="structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d"></a>

The time it as been attached to the timeline in secs (differ to [UNTimelineEventAdapter::StartedAt](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903))

#### `public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) <a id="structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc"></a>

The delay before starting in secs

#### `public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) <a id="structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe"></a>

The duration this event lives in secs (0 means inderterminate)

#### `public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) <a id="structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5"></a>

The name of the event

#### `public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) <a id="structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d"></a>

Expiration time of this event in secs (0 means can't expired))

#### `public FString `[`EventClassName`](#structFNEventRecord_1a5ebb6654bd18ffe427e104f74fd9ba93) <a id="structFNEventRecord_1a5ebb6654bd18ffe427e104f74fd9ba93"></a>

This is used only for serialization, it allow to re-instance the object on load

#### `public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` <a id="structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d"></a>

#### `public inline  `[`FNEventRecord`](#structFNEventRecord_1ac73fc2cb4bd8bb046b456a04337112fb)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` <a id="structFNEventRecord_1ac73fc2cb4bd8bb046b456a04337112fb"></a>

#### `public void `[`Serialize`](#structFNEventRecord_1a0205d63d21092bc352c8836d29a51d23)`(FArchive & Ar,`[`UNTimelineAdapter`](#classUNTimelineAdapter)` * Timeline)` <a id="structFNEventRecord_1a0205d63d21092bc352c8836d29a51d23"></a>

It manages Event object saving and loading

Generated by [Moxygen](https://sourcey.com/moxygen)