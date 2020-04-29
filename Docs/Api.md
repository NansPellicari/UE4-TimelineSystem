# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | 
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | 
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NTimeline`](#classNTimeline) | Its goal is to saved events and place them in time.
`class `[`NTimelineEventBase`](#classNTimelineEventBase) | An absctract class to manage events which can be attached to a timeline.
`class `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract) | 
`class `[`NTimelineManagerFake`](#classNTimelineManagerFake) | 
`class `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake) | 
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | 
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | 
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | 
`class `[`UNTimelineManagerBase`](#classUNTimelineManagerBase) | TODO Add Serialisation (FArchive) + Save user stats

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

Its goal is to saved events and place them in time.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` | 
`public void `[`Attached`](#classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` | 
`public void `[`Attached`](#classNTimeline_1a404dbb01b58fff5746568ceac1226a0c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` | 
`public float `[`GetCurrentTime`](#classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1)`()` | 
`protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) | The name of this timeline
`protected TSharedPtr< `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract)` > `[`TimerManager`](#classNTimeline_1a093623a8a6347201ecff67e01686f5eb) | This is by this object we can control time behavior (play, stop, etc,..). But it also garanty to tick the timeline when itself is ticked.
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | 
`protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | 
`protected inline virtual const float & `[`GetTickInterval`](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3)`() const` | This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.
`protected inline virtual void `[`OnExpired`](#classNTimeline_1abed3baa8327f67401459bcc1997f3a0d)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference
`protected const TArray< NTimeline::FEventTuple > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` | 
`protected void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` | This completely reset every events. Is should be used internally, a timeline should manage its duration itself.

## Members

#### `public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` <a id="classNTimeline_1adffcefb7fc7f2768021994f8730eb356"></a>

#### `public void `[`Attached`](#classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` <a id="classNTimeline_1ab10f9963ad4c5f8fea38f4be5b37428b"></a>

#### `public void `[`Attached`](#classNTimeline_1a404dbb01b58fff5746568ceac1226a0c)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` <a id="classNTimeline_1a404dbb01b58fff5746568ceac1226a0c"></a>

#### `public float `[`GetCurrentTime`](#classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1)`()` <a id="classNTimeline_1acd18d17b5b93782aaebdf03a0a94daf1"></a>

#### `protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) <a id="classNTimeline_1a008f3afba683e14f05887e4df108c260"></a>

The name of this timeline

#### `protected TSharedPtr< `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract)` > `[`TimerManager`](#classNTimeline_1a093623a8a6347201ecff67e01686f5eb) <a id="classNTimeline_1a093623a8a6347201ecff67e01686f5eb"></a>

This is by this object we can control time behavior (play, stop, etc,..). But it also garanty to tick the timeline when itself is ticked.

#### `protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1"></a>

#### `protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1a427fef6206ba24c609a56884de4167e5"></a>

#### `protected inline virtual const float & `[`GetTickInterval`](#classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3)`() const` <a id="classNTimeline_1a3b72d2abe1c75bcca48473a74bc842a3"></a>

This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.

#### `protected inline virtual void `[`OnExpired`](#classNTimeline_1abed3baa8327f67401459bcc1997f3a0d)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1abed3baa8327f67401459bcc1997f3a0d"></a>

Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference

#### `protected const TArray< NTimeline::FEventTuple > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` <a id="classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6"></a>

#### `protected void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` <a id="classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8"></a>

This completely reset every events. Is should be used internally, a timeline should manage its duration itself.

# class `NTimelineEventBase` <a id="classNTimelineEventBase"></a>

An absctract class to manage events which can be attached to a timeline.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`LocalTime`](#classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306) | 
`public float `[`StartedAt`](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903) | 
`public float `[`Duration`](#classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394) | 
`public float `[`Delay`](#classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78) | 
`public virtual bool `[`IsExpired`](#classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7)`() const` | 
`public virtual const float `[`GetLocalTime`](#classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1)`() const` | Should be great to have a doc
`public virtual const float `[`GetStartedAt`](#classNTimelineEventBase_1a602096932bdacf10e984d52516a84486)`() const` | 
`public virtual float `[`GetDuration`](#classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f)`() const` | 
`public virtual void `[`Start`](#classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7)`(float StartTime)` | 
`public virtual void `[`NotifyAddTime`](#classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871)`(float NewTime)` | 
`public virtual float `[`GetDelay`](#classNTimelineEventBase_1a376d56329b872474913fa39487d97a69)`() const` | 
`public const FName `[`GetEventLabel`](#classNTimelineEventBase_1a73f9fbc22b2b0149ab37abb766eef979)`() const` | 

## Members

#### `public float `[`LocalTime`](#classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306) <a id="classNTimelineEventBase_1a589236541a844dc26cf62dac6082b306"></a>

#### `public float `[`StartedAt`](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903) <a id="classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903"></a>

#### `public float `[`Duration`](#classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394) <a id="classNTimelineEventBase_1a367fdd2bb5a3369333a144c8d1151394"></a>

#### `public float `[`Delay`](#classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78) <a id="classNTimelineEventBase_1ab3d4b7ae2ca525d12499fc5689d20c78"></a>

#### `public virtual bool `[`IsExpired`](#classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7)`() const` <a id="classNTimelineEventBase_1a6e0d9ae58bb147f88aac3c91ab34b8d7"></a>

#### `public virtual const float `[`GetLocalTime`](#classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1)`() const` <a id="classNTimelineEventBase_1a12510c88a6d40cab4d5177bbeebfb3d1"></a>

Should be great to have a doc

#### `public virtual const float `[`GetStartedAt`](#classNTimelineEventBase_1a602096932bdacf10e984d52516a84486)`() const` <a id="classNTimelineEventBase_1a602096932bdacf10e984d52516a84486"></a>

#### `public virtual float `[`GetDuration`](#classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f)`() const` <a id="classNTimelineEventBase_1a6923dee32d3b658c6736ca0853988f1f"></a>

#### `public virtual void `[`Start`](#classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7)`(float StartTime)` <a id="classNTimelineEventBase_1a5383c08d8cb57784fc0370b2451019e7"></a>

#### `public virtual void `[`NotifyAddTime`](#classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871)`(float NewTime)` <a id="classNTimelineEventBase_1a028b57f967756af7dad5599eff7d5871"></a>

#### `public virtual float `[`GetDelay`](#classNTimelineEventBase_1a376d56329b872474913fa39487d97a69)`() const` <a id="classNTimelineEventBase_1a376d56329b872474913fa39487d97a69"></a>

#### `public const FName `[`GetEventLabel`](#classNTimelineEventBase_1a73f9fbc22b2b0149ab37abb766eef979)`() const` <a id="classNTimelineEventBase_1a73f9fbc22b2b0149ab37abb766eef979"></a>

# class `NTimelineManagerAbstract` <a id="classNTimelineManagerAbstract"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NTimelineManagerAbstract`](#classNTimelineManagerAbstract_1a30f8dd6940ac9d737459b6350af66c18)`()` | 
`public virtual  `[`~NTimelineManagerAbstract`](#classNTimelineManagerAbstract_1abb0862056cfa1a64bcd1b5c578999759)`()` | 
`public virtual void `[`Pause`](#classNTimelineManagerAbstract_1a34805f4276d9822523da52d9024f289e)`()` | 
`public virtual void `[`Play`](#classNTimelineManagerAbstract_1abdaf296d2ceb763d849f6eb105e4b8ee)`()` | 
`public virtual void `[`Stop`](#classNTimelineManagerAbstract_1aefac2b98cdfef661b3cae1f23307340a)`()` | 
`public void `[`TimerTick`](#classNTimelineManagerAbstract_1a54c4169699a7b352e151d42e72205312)`()` | 
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

#### `public void `[`TimerTick`](#classNTimelineManagerAbstract_1a54c4169699a7b352e151d42e72205312)`()` <a id="classNTimelineManagerAbstract_1a54c4169699a7b352e151d42e72205312"></a>

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
  : public UNTimelineManagerBase
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) | 
`public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) | 
`public virtual void `[`Init`](#classUNGameLifeTimelineManager_1a1e1e7b8a5622a5afbdadb6f02e655bb4)`()` | 
`public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` | 
`protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` | 

## Members

#### `public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) <a id="classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab"></a>

#### `public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) <a id="classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61"></a>

#### `public virtual void `[`Init`](#classUNGameLifeTimelineManager_1a1e1e7b8a5622a5afbdadb6f02e655bb4)`()` <a id="classUNGameLifeTimelineManager_1a1e1e7b8a5622a5afbdadb6f02e655bb4"></a>

#### `public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` <a id="classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8"></a>

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
`public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75)`()` | 
`public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a70e011d04240628de2a1941f5c715dbc)`()` | 
`protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` | 
`protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` | 

## Members

#### `public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1a8a56cb750c6d9160d07d2366b51fe79b)`()` <a id="classUNLevelLifeTimelineManager_1a8a56cb750c6d9160d07d2366b51fe79b"></a>

#### `public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` <a id="classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632"></a>

#### `public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75)`()` <a id="classUNLevelLifeTimelineManager_1a5f3077625f452d2d0d0c58f436a36c75"></a>

#### `public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a70e011d04240628de2a1941f5c715dbc)`()` <a id="classUNLevelLifeTimelineManager_1a70e011d04240628de2a1941f5c715dbc"></a>

#### `protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` <a id="classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839"></a>

#### `protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` <a id="classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb"></a>

# class `UNRealLifeTimelineManager` <a id="classUNRealLifeTimelineManager"></a>

```
class UNRealLifeTimelineManager
  : public UNTimelineManagerBase
  : public FTickableGameObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a6c0a0e3ce90e19ea24bc7bdd174e36f8)`()` | 
`public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` | 
`public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` | 
`public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` | 
`public inline virtual TStatId `[`GetStatId`](#classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25)`() const` | 
`public virtual UWorld * `[`GetTickableGameObjectWorld`](#classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060)`() const` | 
`protected float `[`TotalLifeTime`](#classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584) | 
`protected float `[`LastTimeTick`](#classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08) | 
`protected  `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52)`()` | 

## Members

#### `public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a6c0a0e3ce90e19ea24bc7bdd174e36f8)`()` <a id="classUNRealLifeTimelineManager_1a6c0a0e3ce90e19ea24bc7bdd174e36f8"></a>

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` <a id="classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1"></a>

#### `public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` <a id="classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e"></a>

#### `public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` <a id="classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65"></a>

#### `public inline virtual TStatId `[`GetStatId`](#classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25)`() const` <a id="classUNRealLifeTimelineManager_1aa1dff71195c394b61f7719770199ae25"></a>

#### `public virtual UWorld * `[`GetTickableGameObjectWorld`](#classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060)`() const` <a id="classUNRealLifeTimelineManager_1ac053af39134594df8788cd546952c060"></a>

#### `protected float `[`TotalLifeTime`](#classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584) <a id="classUNRealLifeTimelineManager_1ae959c1573f3f694d69f3b4257082c584"></a>

#### `protected float `[`LastTimeTick`](#classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08) <a id="classUNRealLifeTimelineManager_1a01e20fed935b3c8c54bc09e973a39f08"></a>

#### `protected  `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52)`()` <a id="classUNRealLifeTimelineManager_1a41ddb4d1ccec9fe79a80b9413fe3ed52"></a>

# class `UNTimelineManagerBase` <a id="classUNTimelineManagerBase"></a>

```
class UNTimelineManagerBase
  : public UObject
  : public NTimelineManagerAbstract
```  

TODO Add Serialisation (FArchive) + Save user stats

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`Counter`](#classUNTimelineManagerBase_1ab57ccb8572167f2193bfec0d157054ff) | 
`public inline virtual void `[`Init`](#classUNTimelineManagerBase_1a3203624f7a2bc1457b84c6b203ac05f2)`()` | 
`public virtual void `[`Clear`](#classUNTimelineManagerBase_1a2efdc81c448f4a372c2751af2144f768)`()` | 
`public virtual void `[`BeginDestroy`](#classUNTimelineManagerBase_1a23aae4915976118d41060c61772af1ea)`()` | 
`public virtual void `[`onNotifyTimelineTickBefore`](#classUNTimelineManagerBase_1ad7faf525fde7262271b108b8ab93bf8e)`()` | 
`protected  `[`UNTimelineManagerBase`](#classUNTimelineManagerBase_1a7e76be054c49f3ffbe9885623980b50d)`()` | 

## Members

#### `public float `[`Counter`](#classUNTimelineManagerBase_1ab57ccb8572167f2193bfec0d157054ff) <a id="classUNTimelineManagerBase_1ab57ccb8572167f2193bfec0d157054ff"></a>

#### `public inline virtual void `[`Init`](#classUNTimelineManagerBase_1a3203624f7a2bc1457b84c6b203ac05f2)`()` <a id="classUNTimelineManagerBase_1a3203624f7a2bc1457b84c6b203ac05f2"></a>

#### `public virtual void `[`Clear`](#classUNTimelineManagerBase_1a2efdc81c448f4a372c2751af2144f768)`()` <a id="classUNTimelineManagerBase_1a2efdc81c448f4a372c2751af2144f768"></a>

#### `public virtual void `[`BeginDestroy`](#classUNTimelineManagerBase_1a23aae4915976118d41060c61772af1ea)`()` <a id="classUNTimelineManagerBase_1a23aae4915976118d41060c61772af1ea"></a>

#### `public virtual void `[`onNotifyTimelineTickBefore`](#classUNTimelineManagerBase_1ad7faf525fde7262271b108b8ab93bf8e)`()` <a id="classUNTimelineManagerBase_1ad7faf525fde7262271b108b8ab93bf8e"></a>

#### `protected  `[`UNTimelineManagerBase`](#classUNTimelineManagerBase_1a7e76be054c49f3ffbe9885623980b50d)`()` <a id="classUNTimelineManagerBase_1a7e76be054c49f3ffbe9885623980b50d"></a>

Generated by [Moxygen](https://sourcey.com/moxygen)