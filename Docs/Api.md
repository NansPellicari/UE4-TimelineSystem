# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | 
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | 
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NTimeline`](#classNTimeline) | Its goal is to saved events and place them in time. It works as a Time & Event container. On the Engine side, it should be dedicated to be serialized & save data. The [NTimelineManagerAbstract](#classNTimelineManagerAbstract) class is dedicated to handle it. 
`class `[`NTimelineEventBase`](#classNTimelineEventBase) | An absctract class to manage events which can be attached to a timeline.
`class `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract) | This is class is the
`class `[`NTimelineManagerFake`](#classNTimelineManagerFake) | This class is used for tests only
`class `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake) | This class is used for tests only
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | 
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | 
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | 
`class `[`UNTimelineAdapter`](#classUNTimelineAdapter) | The adapter for [NTimeline](#classNTimeline) object.
`class `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter) | Base abstract class to create [NTimelineEventBase](#classNTimelineEventBase) adapters (Blueprint or c++).
`class `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter) | TODO Add Save user stats
`class `[`UTimelineFactory`](#classUTimelineFactory) | A simple Blueprint Library class to manage Timeline creation.
`struct `[`FNEventRecord`](#structFNEventRecord) | 

# class `FNansTimelineSystemCoreModule` <a id="classFNansTimelineSystemCoreModule"></a>

```
class FNansTimelineSystemCoreModule
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansTimelineSystemCoreModule_1a0367b574b1dfb4034956f94a7f06757d)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansTimelineSystemCoreModule_1a88a4f19c78774708a5e017da20c80e6e)`()` | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansTimelineSystemCoreModule_1a0367b574b1dfb4034956f94a7f06757d)`()` <a id="classFNansTimelineSystemCoreModule_1a0367b574b1dfb4034956f94a7f06757d"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansTimelineSystemCoreModule_1a88a4f19c78774708a5e017da20c80e6e)`()` <a id="classFNansTimelineSystemCoreModule_1a88a4f19c78774708a5e017da20c80e6e"></a>

# class `FNansTimelineSystemUE4Module` <a id="classFNansTimelineSystemUE4Module"></a>

```
class FNansTimelineSystemUE4Module
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansTimelineSystemUE4Module_1a8b5df09796b8c28fb25faea9f05d9363)`()` | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235)`()` <a id="classFNansTimelineSystemUE4Module_1adc3a6e71ae3b124d441fc4f75effd235"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansTimelineSystemUE4Module_1a8b5df09796b8c28fb25faea9f05d9363)`()` <a id="classFNansTimelineSystemUE4Module_1a8b5df09796b8c28fb25faea9f05d9363"></a>

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

Its goal is to saved events and place them in time. It works as a Time & Event container. On the Engine side, it should be dedicated to be serialized & save data. The [NTimelineManagerAbstract](#classNTimelineManagerAbstract) class is dedicated to handle it. 
**See also**: ./TimelineManagerAbstract.h

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NTimeline`](#classNTimeline_1a7156f89321feaf27918d8860de1e28bc)`(`[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract)` * TimerManager)` | A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.
`public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` | 
`public virtual void `[`Attached`](#classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` | 
`public virtual void `[`Attached`](#classNTimeline_1a404dbb01b58fff5746568ceac1226a0c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` | 
`public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` | 
`public virtual float `[`GetCurrentTime`](#classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1)`()` | 
`public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` | 
`public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` | 
`public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` | 
`public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` Tuple)` | This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b) methods to set data during runtime.
`public virtual void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`NotifyTick`](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.
`protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) | The name of this timeline
`protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) | It is computed internally in the [NotifyTick()](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) return.
`protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` | This to allow inherited adapters to have a default constructor
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | In case of specialisation needs to avoid the attach process in some cases
`protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | If needed to make some stats, analytics, trigger error,...
`protected inline virtual const float & `[`GetTickInterval`](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3)`() const` | This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.
`protected inline virtual void `[`OnExpired`](#classNTimeline_1abed3baa8327f67401459bcc1997f3a0d)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference
`typedef `[`FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) | An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time

## Members

#### `public  `[`NTimeline`](#classNTimeline_1a7156f89321feaf27918d8860de1e28bc)`(`[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract)` * TimerManager)` <a id="classNTimeline_1a7156f89321feaf27918d8860de1e28bc"></a>

A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.

#### Parameters
* `TimerManager` - Timer which manage all time behavior (tick, pause, stop, play,...)

#### `public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` <a id="classNTimeline_1adffcefb7fc7f2768021994f8730eb356"></a>

#### `public virtual void `[`Attached`](#classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` <a id="classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b"></a>

#### `public virtual void `[`Attached`](#classNTimeline_1a404dbb01b58fff5746568ceac1226a0c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` <a id="classNTimeline_1a404dbb01b58fff5746568ceac1226a0c"></a>

#### `public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` <a id="classNTimeline_1a0411bf651e453dd5446074b11829654d"></a>

#### `public virtual float `[`GetCurrentTime`](#classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1)`()` <a id="classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1"></a>

#### `public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` <a id="classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6"></a>

#### `public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` <a id="classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153"></a>

#### `public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` <a id="classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25"></a>

#### `public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` Tuple)` <a id="classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec"></a>

This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b) methods to set data during runtime.

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

#### `protected inline virtual void `[`OnExpired`](#classNTimeline_1abed3baa8327f67401459bcc1997f3a0d)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1abed3baa8327f67401459bcc1997f3a0d"></a>

Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference

#### `typedef `[`FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) <a id="classNTimeline_1a632c8756e47d7e95507296250c40e6db"></a>

An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time

# class `NTimelineEventBase` <a id="classNTimelineEventBase"></a>

An absctract class to manage events which can be attached to a timeline.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Label`](#classNTimelineEventBase_1a35bb1df5489f8efaebfd9f36dfae42fe) | 
`public float `[`LocalTime`](#classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306) | 
`public float `[`StartedAt`](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903) | 
`public float `[`Duration`](#classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394) | 
`public float `[`Delay`](#classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78) | 
`public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a216c1203c83023a2549f1ae3276f6e41)`()` | 
`public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a046e029f6b108f7bf43fac60386a7031)`(FName _Label)` | 
`public virtual bool `[`IsExpired`](#classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7)`() const` | 
`public virtual const float `[`GetLocalTime`](#classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1)`() const` | Should be great to have a doc
`public virtual const float `[`GetStartedAt`](#classNTimelineEventBase_1a602096932bdacf10e984d52516a84486)`() const` | 
`public virtual float `[`GetDuration`](#classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f)`() const` | 
`public virtual void `[`Start`](#classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7)`(float StartTime)` | 
`public virtual void `[`NotifyAddTime`](#classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871)`(float NewTime)` | 
`public virtual float `[`GetDelay`](#classNTimelineEventBase_1a376d56329b872474913fa39487d97a69)`() const` | 
`public virtual const FName `[`GetEventLabel`](#classNTimelineEventBase_1a4b274830671935a296d22df0b2f91b3a)`() const` | 
`public virtual void `[`Clear`](#classNTimelineEventBase_1a589cb9a517e7cc59d1d95c7342d3156e)`()` | 

## Members

#### `public FName `[`Label`](#classNTimelineEventBase_1a35bb1df5489f8efaebfd9f36dfae42fe) <a id="classNTimelineEventBase_1a35bb1df5489f8efaebfd9f36dfae42fe"></a>

#### `public float `[`LocalTime`](#classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306) <a id="classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306"></a>

#### `public float `[`StartedAt`](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903) <a id="classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903"></a>

#### `public float `[`Duration`](#classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394) <a id="classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394"></a>

#### `public float `[`Delay`](#classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78) <a id="classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78"></a>

#### `public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a216c1203c83023a2549f1ae3276f6e41)`()` <a id="classNTimelineEventBase_1a216c1203c83023a2549f1ae3276f6e41"></a>

#### `public inline  `[`NTimelineEventBase`](#classNTimelineEventBase_1a046e029f6b108f7bf43fac60386a7031)`(FName _Label)` <a id="classNTimelineEventBase_1a046e029f6b108f7bf43fac60386a7031"></a>

#### `public virtual bool `[`IsExpired`](#classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7)`() const` <a id="classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7"></a>

#### `public virtual const float `[`GetLocalTime`](#classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1)`() const` <a id="classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1"></a>

Should be great to have a doc

#### `public virtual const float `[`GetStartedAt`](#classNTimelineEventBase_1a602096932bdacf10e984d52516a84486)`() const` <a id="classNTimelineEventBase_1a602096932bdacf10e984d52516a84486"></a>

#### `public virtual float `[`GetDuration`](#classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f)`() const` <a id="classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f"></a>

#### `public virtual void `[`Start`](#classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7)`(float StartTime)` <a id="classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7"></a>

#### `public virtual void `[`NotifyAddTime`](#classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871)`(float NewTime)` <a id="classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871"></a>

#### `public virtual float `[`GetDelay`](#classNTimelineEventBase_1a376d56329b872474913fa39487d97a69)`() const` <a id="classNTimelineEventBase_1a376d56329b872474913fa39487d97a69"></a>

#### `public virtual const FName `[`GetEventLabel`](#classNTimelineEventBase_1a4b274830671935a296d22df0b2f91b3a)`() const` <a id="classNTimelineEventBase_1a4b274830671935a296d22df0b2f91b3a"></a>

#### `public virtual void `[`Clear`](#classNTimelineEventBase_1a589cb9a517e7cc59d1d95c7342d3156e)`()` <a id="classNTimelineEventBase_1a589cb9a517e7cc59d1d95c7342d3156e"></a>

# class `NTimelineManagerAbstract` <a id="classNTimelineManagerAbstract"></a>

This is class is the

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract_1a30f8dd6940ac9d737459b6350af66c18)`()` | 
`public virtual  `[`~NTimelineManagerAbstract`](#classNTimelineManagerAbstract_1abb0862056cfa1a64bcd1b5c578999759)`()` | 
`public virtual void `[`Pause`](#classNTimelineManagerAbstract_1a34805f4276d9822523da52d9024f289e)`()` | 
`public virtual void `[`Play`](#classNTimelineManagerAbstract_1abdaf296d2ceb763d849f6eb105e4b8ee)`()` | 
`public virtual void `[`Stop`](#classNTimelineManagerAbstract_1aefac2b98cdfef661b3cae1f23307340a)`()` | 
`public virtual void `[`TimerTick`](#classNTimelineManagerAbstract_1a54c4169699a7b352e151d42e72205312)`()` | 
`public `[`ENTimelineTimerState`](#TimelineManagerAbstract_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManagerAbstract_1adffd4b5802191a53b1ec56ba805452fa)`()` | 
`public float `[`GetTickInterval`](#classNTimelineManagerAbstract_1a7731bb76e0d825549aa2de4e0c5a7134)`()` | 
`public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classNTimelineManagerAbstract_1a84214201973cab98e133771cefae4a79)`()` | 
`protected float `[`TickInterval`](#classNTimelineManagerAbstract_1a87ce2db0bdebeb720e225e108e03e834) | The interval retrieve from the timeline.
`protected `[`ENTimelineTimerState`](#TimelineManagerAbstract_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManagerAbstract_1a392fd7b1cfa2912371319654696fcf3b) | ENTimelineTimerState
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classNTimelineManagerAbstract_1aac08a37523d483d332b29c719eca8f7f) | 
`protected virtual void `[`CreateTimeline`](#classNTimelineManagerAbstract_1a8c19a9c44e86fffe979463aa255b5d0d)`()` | 
`protected void `[`SetTimeline`](#classNTimelineManagerAbstract_1a67fda2495716374b0b77d47f2652df76)`(`[`NTimeline`](#classNTimeline)` * _Timeline)` | Only accept friend to use it. This to force their connection in derived class of [NTimeline](#classNTimeline).
`protected virtual void `[`Clear`](#classNTimelineManagerAbstract_1ab323e4f8010cd069c2f552c3090a6c22)`()` | 
`protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManagerAbstract_1a422e418461055365e453bd2658b9bf02)`()` | 
`protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerAbstract_1aab5134d2f7a3085a03fe953aeed63c2f)`()` | 
`protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManagerAbstract_1a20f494c68375c29f8af7b904bf7f0e8c)`()` | 
`protected void `[`SetTickInterval`](#classNTimelineManagerAbstract_1aa6779de08ab323b5e3db96ffee6e983d)`(const float _TickInterval)` | 

## Members

#### `public  `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract_1a30f8dd6940ac9d737459b6350af66c18)`()` <a id="classNTimelineManagerAbstract_1a30f8dd6940ac9d737459b6350af66c18"></a>

#### `public virtual  `[`~NTimelineManagerAbstract`](#classNTimelineManagerAbstract_1abb0862056cfa1a64bcd1b5c578999759)`()` <a id="classNTimelineManagerAbstract_1abb0862056cfa1a64bcd1b5c578999759"></a>

#### `public virtual void `[`Pause`](#classNTimelineManagerAbstract_1a34805f4276d9822523da52d9024f289e)`()` <a id="classNTimelineManagerAbstract_1a34805f4276d9822523da52d9024f289e"></a>

#### `public virtual void `[`Play`](#classNTimelineManagerAbstract_1abdaf296d2ceb763d849f6eb105e4b8ee)`()` <a id="classNTimelineManagerAbstract_1abdaf296d2ceb763d849f6eb105e4b8ee"></a>

#### `public virtual void `[`Stop`](#classNTimelineManagerAbstract_1aefac2b98cdfef661b3cae1f23307340a)`()` <a id="classNTimelineManagerAbstract_1aefac2b98cdfef661b3cae1f23307340a"></a>

#### `public virtual void `[`TimerTick`](#classNTimelineManagerAbstract_1a54c4169699a7b352e151d42e72205312)`()` <a id="classNTimelineManagerAbstract_1a54c4169699a7b352e151d42e72205312"></a>

#### `public `[`ENTimelineTimerState`](#TimelineManagerAbstract_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManagerAbstract_1adffd4b5802191a53b1ec56ba805452fa)`()` <a id="classNTimelineManagerAbstract_1adffd4b5802191a53b1ec56ba805452fa"></a>

#### `public float `[`GetTickInterval`](#classNTimelineManagerAbstract_1a7731bb76e0d825549aa2de4e0c5a7134)`()` <a id="classNTimelineManagerAbstract_1a7731bb76e0d825549aa2de4e0c5a7134"></a>

#### `public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classNTimelineManagerAbstract_1a84214201973cab98e133771cefae4a79)`()` <a id="classNTimelineManagerAbstract_1a84214201973cab98e133771cefae4a79"></a>

#### `protected float `[`TickInterval`](#classNTimelineManagerAbstract_1a87ce2db0bdebeb720e225e108e03e834) <a id="classNTimelineManagerAbstract_1a87ce2db0bdebeb720e225e108e03e834"></a>

The interval retrieve from the timeline.

#### `protected `[`ENTimelineTimerState`](#TimelineManagerAbstract_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManagerAbstract_1a392fd7b1cfa2912371319654696fcf3b) <a id="classNTimelineManagerAbstract_1a392fd7b1cfa2912371319654696fcf3b"></a>

ENTimelineTimerState

#### `protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classNTimelineManagerAbstract_1aac08a37523d483d332b29c719eca8f7f) <a id="classNTimelineManagerAbstract_1aac08a37523d483d332b29c719eca8f7f"></a>

#### `protected virtual void `[`CreateTimeline`](#classNTimelineManagerAbstract_1a8c19a9c44e86fffe979463aa255b5d0d)`()` <a id="classNTimelineManagerAbstract_1a8c19a9c44e86fffe979463aa255b5d0d"></a>

#### `protected void `[`SetTimeline`](#classNTimelineManagerAbstract_1a67fda2495716374b0b77d47f2652df76)`(`[`NTimeline`](#classNTimeline)` * _Timeline)` <a id="classNTimelineManagerAbstract_1a67fda2495716374b0b77d47f2652df76"></a>

Only accept friend to use it. This to force their connection in derived class of [NTimeline](#classNTimeline).

#### `protected virtual void `[`Clear`](#classNTimelineManagerAbstract_1ab323e4f8010cd069c2f552c3090a6c22)`()` <a id="classNTimelineManagerAbstract_1ab323e4f8010cd069c2f552c3090a6c22"></a>

#### `protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManagerAbstract_1a422e418461055365e453bd2658b9bf02)`()` <a id="classNTimelineManagerAbstract_1a422e418461055365e453bd2658b9bf02"></a>

#### `protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerAbstract_1aab5134d2f7a3085a03fe953aeed63c2f)`()` <a id="classNTimelineManagerAbstract_1aab5134d2f7a3085a03fe953aeed63c2f"></a>

#### `protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManagerAbstract_1a20f494c68375c29f8af7b904bf7f0e8c)`()` <a id="classNTimelineManagerAbstract_1a20f494c68375c29f8af7b904bf7f0e8c"></a>

#### `protected void `[`SetTickInterval`](#classNTimelineManagerAbstract_1aa6779de08ab323b5e3db96ffee6e983d)`(const float _TickInterval)` <a id="classNTimelineManagerAbstract_1aa6779de08ab323b5e3db96ffee6e983d"></a>

# class `NTimelineManagerFake` <a id="classNTimelineManagerFake"></a>

```
class NTimelineManagerFake
  : public NTimelineManagerAbstract
```  

This class is used for tests only

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classNTimelineManagerFake_1ab98da0cd865c83d9efae36fffeb3d945) | 
`public FTimerDelegate `[`TimerDelegate`](#classNTimelineManagerFake_1af3aaef867edeed4bc74dcc7a395b22e5) | 
`public float `[`Counter`](#classNTimelineManagerFake_1a306140c2405b462aa14888d0c7f24d7b) | 
`public inline  `[`NTimelineManagerFake`](#classNTimelineManagerFake_1a08eefe10a89eeb974cfdcd125226fa9b)`()` | 
`public inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerFake_1a8e72a51addddb286486168ec28280705)`()` | 
`public inline virtual void `[`Clear`](#classNTimelineManagerFake_1a2d2f36ba2e92f7568093868d184e3ef6)`()` | 

## Members

#### `public FTimerHandle `[`TimerHandle`](#classNTimelineManagerFake_1ab98da0cd865c83d9efae36fffeb3d945) <a id="classNTimelineManagerFake_1ab98da0cd865c83d9efae36fffeb3d945"></a>

#### `public FTimerDelegate `[`TimerDelegate`](#classNTimelineManagerFake_1af3aaef867edeed4bc74dcc7a395b22e5) <a id="classNTimelineManagerFake_1af3aaef867edeed4bc74dcc7a395b22e5"></a>

#### `public float `[`Counter`](#classNTimelineManagerFake_1a306140c2405b462aa14888d0c7f24d7b) <a id="classNTimelineManagerFake_1a306140c2405b462aa14888d0c7f24d7b"></a>

#### `public inline  `[`NTimelineManagerFake`](#classNTimelineManagerFake_1a08eefe10a89eeb974cfdcd125226fa9b)`()` <a id="classNTimelineManagerFake_1a08eefe10a89eeb974cfdcd125226fa9b"></a>

#### `public inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerFake_1a8e72a51addddb286486168ec28280705)`()` <a id="classNTimelineManagerFake_1a8e72a51addddb286486168ec28280705"></a>

#### `public inline virtual void `[`Clear`](#classNTimelineManagerFake_1a2d2f36ba2e92f7568093868d184e3ef6)`()` <a id="classNTimelineManagerFake_1a2d2f36ba2e92f7568093868d184e3ef6"></a>

# class `TimelineManagerTickableOnPauseFake` <a id="classTimelineManagerTickableOnPauseFake"></a>

```
class TimelineManagerTickableOnPauseFake
  : public NTimelineManagerAbstract
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
`public inline virtual void `[`onNotifyTimelineTickBefore`](#classTimelineManagerTickableOnPauseFake_1aaa08cfaf9f42b2d3b22307ccc02ff816)`()` | 
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

#### `public inline virtual TStatId `[`GetStatId`](#classTimelineManagerTickableOnPauseFake_1a9aa901ddef7820bf99e367cc410f1a27)`() const` <a id="classTimelineManagerTickableOnPauseFake_1a9aa901ddef7820bf99e367cc410f1a27"></a>

#### `public inline virtual UWorld * `[`GetTickableGameObjectWorld`](#classTimelineManagerTickableOnPauseFake_1a6d9c0af3f6a3aada468e32ae01f5ec4c)`() const` <a id="classTimelineManagerTickableOnPauseFake_1a6d9c0af3f6a3aada468e32ae01f5ec4c"></a>

# class `UNGameLifeTimelineManager` <a id="classUNGameLifeTimelineManager"></a>

```
class UNGameLifeTimelineManager
  : public UNTimelineManagerBaseAdapter
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) | 
`public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) | 
`public virtual void `[`Init`](#classUNGameLifeTimelineManager_1a1e1e7b8a5622a5afbdadb6f02e655bb4)`()` | 
`public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` | It is called by the parent [NTimelineManagerAbstract](#classNTimelineManagerAbstract) on dtor
`protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) | 
`protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` | 

## Members

#### `public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) <a id="classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab"></a>

#### `public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) <a id="classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61"></a>

#### `public virtual void `[`Init`](#classUNGameLifeTimelineManager_1a1e1e7b8a5622a5afbdadb6f02e655bb4)`()` <a id="classUNGameLifeTimelineManager_1a1e1e7b8a5622a5afbdadb6f02e655bb4"></a>

#### `public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` <a id="classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8"></a>

It is called by the parent [NTimelineManagerAbstract](#classNTimelineManagerAbstract) on dtor

#### `protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) <a id="classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4"></a>

#### `protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` <a id="classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b"></a>

# class `UNLevelLifeTimelineManager` <a id="classUNLevelLifeTimelineManager"></a>

```
class UNLevelLifeTimelineManager
  : public UNGameLifeTimelineManager
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1a8a56cb750c6d9160d07d2366b51fe79b)`()` | 
`public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` | 
`public void `[`OnLevelAdded`](#classUNLevelLifeTimelineManager_1a377ebe035faf84250cb3ac5416ae1fb7)`(ULevel * Level,UWorld * World)` | 
`public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75)`()` | 
`public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a70e011d04240628de2a1941f5c715dbc)`()` | It is called by the parent [NTimelineManagerAbstract](#classNTimelineManagerAbstract) on dtor
`protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` | 
`protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` | 

## Members

#### `public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1a8a56cb750c6d9160d07d2366b51fe79b)`()` <a id="classUNLevelLifeTimelineManager_1a8a56cb750c6d9160d07d2366b51fe79b"></a>

#### `public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` <a id="classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632"></a>

#### `public void `[`OnLevelAdded`](#classUNLevelLifeTimelineManager_1a377ebe035faf84250cb3ac5416ae1fb7)`(ULevel * Level,UWorld * World)` <a id="classUNLevelLifeTimelineManager_1a377ebe035faf84250cb3ac5416ae1fb7"></a>

#### `public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75)`()` <a id="classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75"></a>

#### `public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a70e011d04240628de2a1941f5c715dbc)`()` <a id="classUNLevelLifeTimelineManager_1a70e011d04240628de2a1941f5c715dbc"></a>

It is called by the parent [NTimelineManagerAbstract](#classNTimelineManagerAbstract) on dtor

#### `protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` <a id="classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839"></a>

#### `protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` <a id="classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb"></a>

# class `UNRealLifeTimelineManager` <a id="classUNRealLifeTimelineManager"></a>

```
class UNRealLifeTimelineManager
  : public UNTimelineManagerBaseAdapter
  : public FTickableGameObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FDateTime `[`CreationTime`](#classUNRealLifeTimelineManager_1a48e60566f34f0807ea0aebba3c648294) | 
`public virtual void `[`Pause`](#classUNRealLifeTimelineManager_1a13a4709cd4d450817cdc5a71409baa40)`()` | 
`public virtual void `[`Play`](#classUNRealLifeTimelineManager_1a677c7cd4d46758617a3437af87758c41)`()` | 
`public virtual void `[`Stop`](#classUNRealLifeTimelineManager_1a0f9418b797de8c34a4608197b65856ca)`()` | 
`public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a6c0a0e3ce90e19ea24bc7bdd174e36f8)`()` | 
`public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` | 
`public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` | 
`public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` | 
`public inline virtual TStatId `[`GetStatId`](#classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25)`() const` | 
`public virtual UWorld * `[`GetTickableGameObjectWorld`](#classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060)`() const` | 
`public virtual void `[`Serialize`](#classUNRealLifeTimelineManager_1a530e89eb20a2a984e5d532c7532aae76)`(FArchive & Ar)` | 
`protected float `[`TotalLifeTime`](#classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584) | 
`protected FDateTime `[`LastPlayTime`](#classUNRealLifeTimelineManager_1a083676a7926f5f527f000b3b4f3a1b89) | 
`protected float `[`LastTimeTick`](#classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08) | 
`protected  `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52)`()` | 

## Members

#### `public FDateTime `[`CreationTime`](#classUNRealLifeTimelineManager_1a48e60566f34f0807ea0aebba3c648294) <a id="classUNRealLifeTimelineManager_1a48e60566f34f0807ea0aebba3c648294"></a>

#### `public virtual void `[`Pause`](#classUNRealLifeTimelineManager_1a13a4709cd4d450817cdc5a71409baa40)`()` <a id="classUNRealLifeTimelineManager_1a13a4709cd4d450817cdc5a71409baa40"></a>

#### `public virtual void `[`Play`](#classUNRealLifeTimelineManager_1a677c7cd4d46758617a3437af87758c41)`()` <a id="classUNRealLifeTimelineManager_1a677c7cd4d46758617a3437af87758c41"></a>

#### `public virtual void `[`Stop`](#classUNRealLifeTimelineManager_1a0f9418b797de8c34a4608197b65856ca)`()` <a id="classUNRealLifeTimelineManager_1a0f9418b797de8c34a4608197b65856ca"></a>

#### `public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a6c0a0e3ce90e19ea24bc7bdd174e36f8)`()` <a id="classUNRealLifeTimelineManager_1a6c0a0e3ce90e19ea24bc7bdd174e36f8"></a>

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` <a id="classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1"></a>

#### `public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` <a id="classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e"></a>

#### `public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` <a id="classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65"></a>

#### `public inline virtual TStatId `[`GetStatId`](#classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25)`() const` <a id="classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25"></a>

#### `public virtual UWorld * `[`GetTickableGameObjectWorld`](#classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060)`() const` <a id="classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060"></a>

#### `public virtual void `[`Serialize`](#classUNRealLifeTimelineManager_1a530e89eb20a2a984e5d532c7532aae76)`(FArchive & Ar)` <a id="classUNRealLifeTimelineManager_1a530e89eb20a2a984e5d532c7532aae76"></a>

#### `protected float `[`TotalLifeTime`](#classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584) <a id="classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584"></a>

#### `protected FDateTime `[`LastPlayTime`](#classUNRealLifeTimelineManager_1a083676a7926f5f527f000b3b4f3a1b89) <a id="classUNRealLifeTimelineManager_1a083676a7926f5f527f000b3b4f3a1b89"></a>

#### `protected float `[`LastTimeTick`](#classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08) <a id="classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08"></a>

#### `protected  `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52)`()` <a id="classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52"></a>

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

*

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UNTimelineAdapter`](#classUNTimelineAdapter_1a7ed83ce3cc2a1eb21347bc4ed675f9e4)`()` | 
`public virtual void `[`Init`](#classUNTimelineAdapter_1a4502accc87509721306b351902e7cf50)`(`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * TimelineManager)` | this method is used to instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Clear`](#classUNTimelineAdapter_1af2a938dd80ceb1bda0d7bdf024438ad0)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`SetCurrentTime`](#classUNTimelineAdapter_1adf7ba90b6d70265258de964f7647e56e)`(float _CurrentTime)` | 
`public virtual void `[`SetLabel`](#classUNTimelineAdapter_1ae62c5aacf2cd5abdc52d7bb3448b2b61)`(FName _Label)` | 
`public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classUNTimelineAdapter_1a99ff82b5d7046ecb96880bd9f5bc2174)`() const` | 
`public inline virtual void `[`Attached`](#classUNTimelineAdapter_1a3394f659f3fdcd046c9045f5272752c8)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` | 
`public inline virtual void `[`Attached`](#classUNTimelineAdapter_1a491f5f752b4f22cf2d9642ba9755986c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` | 
`public virtual void `[`Attached`](#classUNTimelineAdapter_1af5992ce7fd611d4d1f9bc206759b27dc)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` | 
`public virtual void `[`NotifyTick`](#classUNTimelineAdapter_1a30f47f32c8382b94541f96938e592009)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.
`public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineAdapter_1a82e3c75c4a8da9468aeb760c7949dea9)`() const` | 
`public virtual float `[`GetCurrentTime`](#classUNTimelineAdapter_1aeba89667659cdecc3f52ff7db923116c)`()` | 
`public virtual FName `[`GetLabel`](#classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495)`() const` | 
`public virtual void `[`SerializeWithManager`](#classUNTimelineAdapter_1ae7e1ade720e3f47c757434e0e2737224)`(FArchive & Ar,`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * Manager)` | 
`public virtual void `[`BeginDestroy`](#classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483)`()` | 
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineAdapter_1a8d571050be62d2ece357c4997bbbd9a3) | 

## Members

#### `public  `[`UNTimelineAdapter`](#classUNTimelineAdapter_1a7ed83ce3cc2a1eb21347bc4ed675f9e4)`()` <a id="classUNTimelineAdapter_1a7ed83ce3cc2a1eb21347bc4ed675f9e4"></a>

#### `public virtual void `[`Init`](#classUNTimelineAdapter_1a4502accc87509721306b351902e7cf50)`(`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * TimelineManager)` <a id="classUNTimelineAdapter_1a4502accc87509721306b351902e7cf50"></a>

this method is used to instanciate the embeded [NTimeline](#classNTimeline)
#### Parameters
* `TimelineManager` - The Adapter which provide the [NTimelineManagerAbstract](#classNTimelineManagerAbstract) object.

#### `public virtual void `[`Clear`](#classUNTimelineAdapter_1af2a938dd80ceb1bda0d7bdf024438ad0)`()` <a id="classUNTimelineAdapter_1af2a938dd80ceb1bda0d7bdf024438ad0"></a>

This completely reset every events. It should be used with caution.

#### `public virtual void `[`SetCurrentTime`](#classUNTimelineAdapter_1adf7ba90b6d70265258de964f7647e56e)`(float _CurrentTime)` <a id="classUNTimelineAdapter_1adf7ba90b6d70265258de964f7647e56e"></a>

#### `public virtual void `[`SetLabel`](#classUNTimelineAdapter_1ae62c5aacf2cd5abdc52d7bb3448b2b61)`(FName _Label)` <a id="classUNTimelineAdapter_1ae62c5aacf2cd5abdc52d7bb3448b2b61"></a>

#### `public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classUNTimelineAdapter_1a99ff82b5d7046ecb96880bd9f5bc2174)`() const` <a id="classUNTimelineAdapter_1a99ff82b5d7046ecb96880bd9f5bc2174"></a>

#### `public inline virtual void `[`Attached`](#classUNTimelineAdapter_1a3394f659f3fdcd046c9045f5272752c8)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` <a id="classUNTimelineAdapter_1a3394f659f3fdcd046c9045f5272752c8"></a>

#### `public inline virtual void `[`Attached`](#classUNTimelineAdapter_1a491f5f752b4f22cf2d9642ba9755986c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` <a id="classUNTimelineAdapter_1a491f5f752b4f22cf2d9642ba9755986c"></a>

#### `public virtual void `[`Attached`](#classUNTimelineAdapter_1af5992ce7fd611d4d1f9bc206759b27dc)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` <a id="classUNTimelineAdapter_1af5992ce7fd611d4d1f9bc206759b27dc"></a>

#### `public virtual void `[`NotifyTick`](#classUNTimelineAdapter_1a30f47f32c8382b94541f96938e592009)`()` <a id="classUNTimelineAdapter_1a30f47f32c8382b94541f96938e592009"></a>

This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3) to increment time.

#### `public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineAdapter_1a82e3c75c4a8da9468aeb760c7949dea9)`() const` <a id="classUNTimelineAdapter_1a82e3c75c4a8da9468aeb760c7949dea9"></a>

#### `public virtual float `[`GetCurrentTime`](#classUNTimelineAdapter_1aeba89667659cdecc3f52ff7db923116c)`()` <a id="classUNTimelineAdapter_1aeba89667659cdecc3f52ff7db923116c"></a>

#### `public virtual FName `[`GetLabel`](#classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495)`() const` <a id="classUNTimelineAdapter_1afd1f915332e3df9c3aafdae4e3300495"></a>

#### `public virtual void `[`SerializeWithManager`](#classUNTimelineAdapter_1ae7e1ade720e3f47c757434e0e2737224)`(FArchive & Ar,`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * Manager)` <a id="classUNTimelineAdapter_1ae7e1ade720e3f47c757434e0e2737224"></a>

#### `public virtual void `[`BeginDestroy`](#classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483)`()` <a id="classUNTimelineAdapter_1ad17b756d4b6c52c999cf91cb1a473483"></a>

#### `protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineAdapter_1a8d571050be62d2ece357c4997bbbd9a3) <a id="classUNTimelineAdapter_1a8d571050be62d2ece357c4997bbbd9a3"></a>

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
`public inline  `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter_1a40a87f0b1504ff4eb90fc97ced767d2f)`()` | 
`public virtual bool `[`IsExpired`](#classUNTimelineEventAdapter_1a28740a23b48d5e5bb506741d38cdc863)`() const` | 
`public virtual const float `[`GetLocalTime`](#classUNTimelineEventAdapter_1a2edf2ce0df1c79f1df430c30b26b5074)`() const` | Should be great to have a doc
`public virtual const float `[`GetStartedAt`](#classUNTimelineEventAdapter_1abcecdb2fb024edfe779d1481a6cd383b)`() const` | 
`public virtual float `[`GetDuration`](#classUNTimelineEventAdapter_1a5d748f27c66c9b529ecf49f7f568b0c7)`() const` | 
`public virtual void `[`Start`](#classUNTimelineEventAdapter_1a35d26f8b38840360f13bcfac5830b391)`(float StartTime)` | 
`public virtual void `[`NotifyAddTime`](#classUNTimelineEventAdapter_1a6d59680a996c8dd837fd7e2fce248cf3)`(float NewTime)` | 
`public virtual float `[`GetDelay`](#classUNTimelineEventAdapter_1a0594d2318fe3c9ab3e965d9bda437292)`() const` | 
`public virtual const FName `[`GetEventLabel`](#classUNTimelineEventAdapter_1a30ef331e61d220bcac0e1995cd78a26c)`() const` | 
`public virtual void `[`BeginDestroy`](#classUNTimelineEventAdapter_1a8cf301901a7d6a6e0bd2aa107e7f85fd)`()` | 
`public virtual void `[`Serialize`](#classUNTimelineEventAdapter_1ab523da9edf384ad0bd7829806db63b53)`(FArchive & Ar)` | 
`public void `[`SetDelay`](#classUNTimelineEventAdapter_1ac377c3c48141d6c44bfa459c5d148d31)`(float _Delay)` | 
`public void `[`SetDuration`](#classUNTimelineEventAdapter_1aa90a54d717511260c722ce87f3a31ec7)`(float _Duration)` | 
`public virtual void `[`Init`](#classUNTimelineEventAdapter_1a8bb42c0d06a213c57128b2ec9e447e8a)`(FName _Label)` | This is where the Core object is instanciated. You should override this to instanciate your derived core object.
`public TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`GetEvent`](#classUNTimelineEventAdapter_1a973ca8f2607f42407d87316786061000)`()` | This is used by other adapters which need to pass the core object to their own. 
`protected TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`Event`](#classUNTimelineEventAdapter_1a9308593395993b79ad1ecb8bbe5ec446) | The actual adapter is for this object. It shoulds be instanciate on a ctor or a dedicated init function

## Members

#### `public inline  `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter_1a40a87f0b1504ff4eb90fc97ced767d2f)`()` <a id="classUNTimelineEventAdapter_1a40a87f0b1504ff4eb90fc97ced767d2f"></a>

#### `public virtual bool `[`IsExpired`](#classUNTimelineEventAdapter_1a28740a23b48d5e5bb506741d38cdc863)`() const` <a id="classUNTimelineEventAdapter_1a28740a23b48d5e5bb506741d38cdc863"></a>

#### `public virtual const float `[`GetLocalTime`](#classUNTimelineEventAdapter_1a2edf2ce0df1c79f1df430c30b26b5074)`() const` <a id="classUNTimelineEventAdapter_1a2edf2ce0df1c79f1df430c30b26b5074"></a>

Should be great to have a doc

#### `public virtual const float `[`GetStartedAt`](#classUNTimelineEventAdapter_1abcecdb2fb024edfe779d1481a6cd383b)`() const` <a id="classUNTimelineEventAdapter_1abcecdb2fb024edfe779d1481a6cd383b"></a>

#### `public virtual float `[`GetDuration`](#classUNTimelineEventAdapter_1a5d748f27c66c9b529ecf49f7f568b0c7)`() const` <a id="classUNTimelineEventAdapter_1a5d748f27c66c9b529ecf49f7f568b0c7"></a>

#### `public virtual void `[`Start`](#classUNTimelineEventAdapter_1a35d26f8b38840360f13bcfac5830b391)`(float StartTime)` <a id="classUNTimelineEventAdapter_1a35d26f8b38840360f13bcfac5830b391"></a>

#### `public virtual void `[`NotifyAddTime`](#classUNTimelineEventAdapter_1a6d59680a996c8dd837fd7e2fce248cf3)`(float NewTime)` <a id="classUNTimelineEventAdapter_1a6d59680a996c8dd837fd7e2fce248cf3"></a>

#### `public virtual float `[`GetDelay`](#classUNTimelineEventAdapter_1a0594d2318fe3c9ab3e965d9bda437292)`() const` <a id="classUNTimelineEventAdapter_1a0594d2318fe3c9ab3e965d9bda437292"></a>

#### `public virtual const FName `[`GetEventLabel`](#classUNTimelineEventAdapter_1a30ef331e61d220bcac0e1995cd78a26c)`() const` <a id="classUNTimelineEventAdapter_1a30ef331e61d220bcac0e1995cd78a26c"></a>

#### `public virtual void `[`BeginDestroy`](#classUNTimelineEventAdapter_1a8cf301901a7d6a6e0bd2aa107e7f85fd)`()` <a id="classUNTimelineEventAdapter_1a8cf301901a7d6a6e0bd2aa107e7f85fd"></a>

#### `public virtual void `[`Serialize`](#classUNTimelineEventAdapter_1ab523da9edf384ad0bd7829806db63b53)`(FArchive & Ar)` <a id="classUNTimelineEventAdapter_1ab523da9edf384ad0bd7829806db63b53"></a>

#### `public void `[`SetDelay`](#classUNTimelineEventAdapter_1ac377c3c48141d6c44bfa459c5d148d31)`(float _Delay)` <a id="classUNTimelineEventAdapter_1ac377c3c48141d6c44bfa459c5d148d31"></a>

#### `public void `[`SetDuration`](#classUNTimelineEventAdapter_1aa90a54d717511260c722ce87f3a31ec7)`(float _Duration)` <a id="classUNTimelineEventAdapter_1aa90a54d717511260c722ce87f3a31ec7"></a>

#### `public virtual void `[`Init`](#classUNTimelineEventAdapter_1a8bb42c0d06a213c57128b2ec9e447e8a)`(FName _Label)` <a id="classUNTimelineEventAdapter_1a8bb42c0d06a213c57128b2ec9e447e8a"></a>

This is where the Core object is instanciated. You should override this to instanciate your derived core object.

#### `public TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`GetEvent`](#classUNTimelineEventAdapter_1a973ca8f2607f42407d87316786061000)`()` <a id="classUNTimelineEventAdapter_1a973ca8f2607f42407d87316786061000"></a>

This is used by other adapters which need to pass the core object to their own. 
**See also**: [UNTimelineAdapter::Attached()](#classUNTimelineAdapter_1a3394f659f3fdcd046c9045f5272752c8)

#### `protected TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`Event`](#classUNTimelineEventAdapter_1a9308593395993b79ad1ecb8bbe5ec446) <a id="classUNTimelineEventAdapter_1a9308593395993b79ad1ecb8bbe5ec446"></a>

The actual adapter is for this object. It shoulds be instanciate on a ctor or a dedicated init function

# class `UNTimelineManagerBaseAdapter` <a id="classUNTimelineManagerBaseAdapter"></a>

```
class UNTimelineManagerBaseAdapter
  : public UObject
  : public NTimelineManagerAbstract
```  

TODO Add Save user stats

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > `[`DefaultClassForEvent`](#classUNTimelineManagerBaseAdapter_1a81798b1c2272af8bc0a5996f65519c63) | 
`public float `[`GetTimelineTime`](#classUNTimelineManagerBaseAdapter_1aabf4d6fde13157e6a077a38924e71fa3)`()` | 
`public virtual void `[`Pause`](#classUNTimelineManagerBaseAdapter_1a2e0332fa1d87dd748c1cabc95eeac57c)`()` | 
`public virtual void `[`Play`](#classUNTimelineManagerBaseAdapter_1aef1c9e06835c27dd5b6c1e560e86400c)`()` | 
`public virtual void `[`Stop`](#classUNTimelineManagerBaseAdapter_1a2b8a8572ced774ff4620b3618f9fb1f7)`()` | 
`public FName `[`GetLabel`](#classUNTimelineManagerBaseAdapter_1a892ced4f4e11f8ac1c76c48c96fe2631)`() const` | 
`public virtual void `[`CreateTimeline`](#classUNTimelineManagerBaseAdapter_1a14e843e8650ab1768c85b59d585f500a)`()` | 
`public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerBaseAdapter_1a1c4949fa6318f2099b7f7b0c7ad6fa87)`()` | 
`public virtual void `[`Serialize`](#classUNTimelineManagerBaseAdapter_1af1e0474d3149d21daae82845e20b1538)`(FArchive & Ar)` | 
`public inline virtual void `[`Init`](#classUNTimelineManagerBaseAdapter_1a5de9f378a58a9f9550edba4208e4ffa6)`()` | 
`public virtual void `[`Clear`](#classUNTimelineManagerBaseAdapter_1a8a395d8909138fc37508920dd50a80d0)`()` | It is called by the parent [NTimelineManagerAbstract](#classNTimelineManagerAbstract) on dtor
`public virtual void `[`BeginDestroy`](#classUNTimelineManagerBaseAdapter_1addc22251c326e4749a1556f570fc152f)`()` | 
`public virtual void `[`AddEvent`](#classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` | Add an event to the timeline object 
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateNewEvent`](#classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` | Create a new Event and use the actual timeline as the outer for this new object.
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` | Create a new Event and add it to the actual embeded timeline
`protected `[`UNTimelineAdapter`](#classUNTimelineAdapter)` * `[`MyTimeline`](#classUNTimelineManagerBaseAdapter_1aac02c9c645fca4bc75afccc4c7946239) | 
`protected  `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2)`()` | 

## Members

#### `public TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > `[`DefaultClassForEvent`](#classUNTimelineManagerBaseAdapter_1a81798b1c2272af8bc0a5996f65519c63) <a id="classUNTimelineManagerBaseAdapter_1a81798b1c2272af8bc0a5996f65519c63"></a>

#### `public float `[`GetTimelineTime`](#classUNTimelineManagerBaseAdapter_1aabf4d6fde13157e6a077a38924e71fa3)`()` <a id="classUNTimelineManagerBaseAdapter_1aabf4d6fde13157e6a077a38924e71fa3"></a>

#### `public virtual void `[`Pause`](#classUNTimelineManagerBaseAdapter_1a2e0332fa1d87dd748c1cabc95eeac57c)`()` <a id="classUNTimelineManagerBaseAdapter_1a2e0332fa1d87dd748c1cabc95eeac57c"></a>

#### `public virtual void `[`Play`](#classUNTimelineManagerBaseAdapter_1aef1c9e06835c27dd5b6c1e560e86400c)`()` <a id="classUNTimelineManagerBaseAdapter_1aef1c9e06835c27dd5b6c1e560e86400c"></a>

#### `public virtual void `[`Stop`](#classUNTimelineManagerBaseAdapter_1a2b8a8572ced774ff4620b3618f9fb1f7)`()` <a id="classUNTimelineManagerBaseAdapter_1a2b8a8572ced774ff4620b3618f9fb1f7"></a>

#### `public FName `[`GetLabel`](#classUNTimelineManagerBaseAdapter_1a892ced4f4e11f8ac1c76c48c96fe2631)`() const` <a id="classUNTimelineManagerBaseAdapter_1a892ced4f4e11f8ac1c76c48c96fe2631"></a>

#### `public virtual void `[`CreateTimeline`](#classUNTimelineManagerBaseAdapter_1a14e843e8650ab1768c85b59d585f500a)`()` <a id="classUNTimelineManagerBaseAdapter_1a14e843e8650ab1768c85b59d585f500a"></a>

#### `public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerBaseAdapter_1a1c4949fa6318f2099b7f7b0c7ad6fa87)`()` <a id="classUNTimelineManagerBaseAdapter_1a1c4949fa6318f2099b7f7b0c7ad6fa87"></a>

#### `public virtual void `[`Serialize`](#classUNTimelineManagerBaseAdapter_1af1e0474d3149d21daae82845e20b1538)`(FArchive & Ar)` <a id="classUNTimelineManagerBaseAdapter_1af1e0474d3149d21daae82845e20b1538"></a>

#### `public inline virtual void `[`Init`](#classUNTimelineManagerBaseAdapter_1a5de9f378a58a9f9550edba4208e4ffa6)`()` <a id="classUNTimelineManagerBaseAdapter_1a5de9f378a58a9f9550edba4208e4ffa6"></a>

#### `public virtual void `[`Clear`](#classUNTimelineManagerBaseAdapter_1a8a395d8909138fc37508920dd50a80d0)`()` <a id="classUNTimelineManagerBaseAdapter_1a8a395d8909138fc37508920dd50a80d0"></a>

It is called by the parent [NTimelineManagerAbstract](#classNTimelineManagerAbstract) on dtor

#### `public virtual void `[`BeginDestroy`](#classUNTimelineManagerBaseAdapter_1addc22251c326e4749a1556f570fc152f)`()` <a id="classUNTimelineManagerBaseAdapter_1addc22251c326e4749a1556f570fc152f"></a>

#### `public virtual void `[`AddEvent`](#classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * Event)` <a id="classUNTimelineManagerBaseAdapter_1a3d58277f64f267d26d5aa6d063b8e18b"></a>

Add an event to the timeline object 
#### Parameters
* `Event` - An object you want to saved to the associated timeline.

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateNewEvent`](#classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerBaseAdapter_1a0b423106760f004651ce2683dcd84090"></a>

Create a new Event and use the actual timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee)`(TSubclassOf< `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerBaseAdapter_1accf8cc57c0dc5247c60b87729649b6ee"></a>

Create a new Event and add it to the actual embeded timeline

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected `[`UNTimelineAdapter`](#classUNTimelineAdapter)` * `[`MyTimeline`](#classUNTimelineManagerBaseAdapter_1aac02c9c645fca4bc75afccc4c7946239) <a id="classUNTimelineManagerBaseAdapter_1aac02c9c645fca4bc75afccc4c7946239"></a>

#### `protected  `[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2)`()` <a id="classUNTimelineManagerBaseAdapter_1a00edb5d8365de02e93c875d7e4a492c2"></a>

# class `UTimelineFactory` <a id="classUTimelineFactory"></a>

```
class UTimelineFactory
  : public UBlueprintFunctionLibrary
```  

A simple Blueprint Library class to manage Timeline creation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `FNEventRecord` <a id="structFNEventRecord"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`Event`](#structFNEventRecord_1abf41bbc0f564bb53be473f13c9e28f86) | 
`public UClass * `[`EventClass`](#structFNEventRecord_1a4b079bc35a6e2bf9da811d1fe9426683) | 
`public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) | 
`public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) | 
`public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) | 
`public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) | 
`public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) | 
`public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` | 
`public inline  `[`FNEventRecord`](#structFNEventRecord_1ac73fc2cb4bd8bb046b456a04337112fb)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` | 
`public void `[`Serialize`](#structFNEventRecord_1a63835687a5ee5f5f7af550fd700c719d)`(FArchive & Ar,`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * Manager)` | 

## Members

#### `public `[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * `[`Event`](#structFNEventRecord_1abf41bbc0f564bb53be473f13c9e28f86) <a id="structFNEventRecord_1abf41bbc0f564bb53be473f13c9e28f86"></a>

#### `public UClass * `[`EventClass`](#structFNEventRecord_1a4b079bc35a6e2bf9da811d1fe9426683) <a id="structFNEventRecord_1a4b079bc35a6e2bf9da811d1fe9426683"></a>

#### `public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) <a id="structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d"></a>

#### `public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) <a id="structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc"></a>

#### `public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) <a id="structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe"></a>

#### `public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) <a id="structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5"></a>

#### `public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) <a id="structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d"></a>

#### `public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` <a id="structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d"></a>

#### `public inline  `[`FNEventRecord`](#structFNEventRecord_1ac73fc2cb4bd8bb046b456a04337112fb)`(`[`UNTimelineEventAdapter`](#classUNTimelineEventAdapter)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` <a id="structFNEventRecord_1ac73fc2cb4bd8bb046b456a04337112fb"></a>

#### `public void `[`Serialize`](#structFNEventRecord_1a63835687a5ee5f5f7af550fd700c719d)`(FArchive & Ar,`[`UNTimelineManagerBaseAdapter`](#classUNTimelineManagerBaseAdapter)` * Manager)` <a id="structFNEventRecord_1a63835687a5ee5f5f7af550fd700c719d"></a>

Generated by [Moxygen](https://sourcey.com/moxygen)