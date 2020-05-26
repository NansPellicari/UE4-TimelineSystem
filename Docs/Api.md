# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | Required to create a UE4 module
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | Required to create a UE4 module
`class `[`FTimelinePinFactory`](#classFTimelinePinFactory) | It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.
`class `[`INTimelineGameInstance`](#classINTimelineGameInstance) | This interface should be implemented by your GameInstance class or blueprint object. See README.md in step by step guide to see how to implements it.
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NTimeline`](#classNTimeline) | Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManagerBase](#classNTimelineManagerBase) class is dedicated to handle it.
`class `[`NTimelineEventBase`](#classNTimelineEventBase) | An abstract class to manage events which can be attached to a timeline.
`class `[`NTimelineManagerBase`](#classNTimelineManagerBase) | This class is the client for the [NTimeline](#classNTimeline) object. Its goal is to decoupled client interface with timeline management.
`class `[`NTimelineManagerFake`](#classNTimelineManagerFake) | This class is used for tests only
`class `[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin) | This class allows to create a dedicated pin to get names from [UNTimelineConfig](#classUNTimelineConfig).
`class `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake) | This class is used for tests only
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | This decorator is fitted to track time when player plays since the game is launched.
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | It tracks game session but refreshes when level changed.
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | It tracks realtime, it is not altered by pause or slowmo.
`class `[`UNTimelineBlueprintHelpers`](#classUNTimelineBlueprintHelpers) | A simple Blueprint Library class to manage Timeline creation.
`class `[`UNTimelineClient`](#classUNTimelineClient) | This class should be used by your GameInstance object. This object is the glue for all the timeline configuration and blueprint helpers.
`class `[`UNTimelineConfig`](#classUNTimelineConfig) | A simple configuration to ease timeline instanciation for developpers.
`class `[`UNTimelineDecorator`](#classUNTimelineDecorator) | The decorator for [NTimeline](#classNTimeline) object.
`class `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator) | Base abstract class to create [NTimelineEventBase](#classNTimelineEventBase) decorators (Blueprint or c++).
`class `[`UNTimelineEventDecoratorFake`](#classUNTimelineEventDecoratorFake) | This class is used for tests only
`class `[`UNTimelineGameInstance`](#classUNTimelineGameInstance) | **See also**: [INTimelineGameInstance](#classINTimelineGameInstance)
`class `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator) | This is the abstract decorator that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or c++.
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

# class `INTimelineGameInstance` <a id="classINTimelineGameInstance"></a>

This interface should be implemented by your GameInstance class or blueprint object. See README.md in step by step guide to see how to implements it.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * `[`GetTimeline`](#classINTimelineGameInstance_1af7a387e593548557ebe60ae30b643924)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Timeline) const` | A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).
`public virtual `[`UNTimelineClient`](#classUNTimelineClient)` * `[`GetClient`](#classINTimelineGameInstance_1a927298bbbf2a61d86765e08eb2765aad)`() const` | 

## Members

#### `public `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * `[`GetTimeline`](#classINTimelineGameInstance_1af7a387e593548557ebe60ae30b643924)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Timeline) const` <a id="classINTimelineGameInstance_1af7a387e593548557ebe60ae30b643924"></a>

A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).

#### Parameters
* `Timeline` - To allow having a combobox of configured timelines

#### `public virtual `[`UNTimelineClient`](#classUNTimelineClient)` * `[`GetClient`](#classINTimelineGameInstance_1a927298bbbf2a61d86765e08eb2765aad)`() const` <a id="classINTimelineGameInstance_1a927298bbbf2a61d86765e08eb2765aad"></a>

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
`public virtual void `[`SetTickInterval`](#classNTimeline_1af4782d4a0bb4b13d2bce2684e9bdf539)`(float _TickInterval)` | This should be called only by its friend [NTimelineManagerBase](#classNTimelineManagerBase) or a decorator to maintain consistency with its manager.
`public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` | This method is mainly used for savegame serialization
`public virtual float `[`GetCurrentTime`](#classNTimeline_1af27e09d598d6d5b47980983040142ee9)`() const` | Get CurrentTime
`public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` | Returns the FEventTuple collection
`public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` | Give a name to this timeline 
`public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` | Return the actual name
`public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a632c8756e47d7e95507296250c40e6db)` Tuple)` | This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a8fd63d2d49b9970c9ed43f3dc21f66a6) methods to set data during runtime.
`public virtual void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`NotifyTick`](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.
`protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) | The name of this timeline
`protected float `[`TickInterval`](#classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421) | Tick interval, should be set by its manager
`protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) | It is computed internally in the [NotifyTick()](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) return.
`protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` | This to allow inherited adapters to have a default constructor
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | In case of specialisation needs to avoid the attach process in some cases
`protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` | If needed to make some stats, analytics, trigger error,...
`protected virtual const float `[`GetTickInterval`](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417)`() const` | This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.
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

#### `public virtual void `[`SetTickInterval`](#classNTimeline_1af4782d4a0bb4b13d2bce2684e9bdf539)`(float _TickInterval)` <a id="classNTimeline_1af4782d4a0bb4b13d2bce2684e9bdf539"></a>

This should be called only by its friend [NTimelineManagerBase](#classNTimelineManagerBase) or a decorator to maintain consistency with its manager.

#### `public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` <a id="classNTimeline_1a0411bf651e453dd5446074b11829654d"></a>

This method is mainly used for savegame serialization

#### `public virtual float `[`GetCurrentTime`](#classNTimeline_1af27e09d598d6d5b47980983040142ee9)`() const` <a id="classNTimeline_1af27e09d598d6d5b47980983040142ee9"></a>

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

This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.

#### `protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) <a id="classNTimeline_1a008f3afba683e14f05887e4df108c260"></a>

The name of this timeline

#### `protected float `[`TickInterval`](#classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421) <a id="classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421"></a>

Tick interval, should be set by its manager

#### `protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) <a id="classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740"></a>

It is computed internally in the [NotifyTick()](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) return.

#### `protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` <a id="classNTimeline_1a6143741ff06add02f22ee82e5f1b6147"></a>

This to allow inherited adapters to have a default constructor

#### `protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1ab6eecf3faf16b14e4748d7c32a204ee1"></a>

In case of specialisation needs to avoid the attach process in some cases

#### `protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a427fef6206ba24c609a56884de4167e5)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float AttachedTime)` <a id="classNTimeline_1a427fef6206ba24c609a56884de4167e5"></a>

If needed to make some stats, analytics, trigger error,...

#### `protected virtual const float `[`GetTickInterval`](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417)`() const` <a id="classNTimeline_1a7c0dc7947a2f271fe68020d322fca417"></a>

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
`public  `[`NTimelineManagerBase`](#classNTimelineManagerBase_1a13e377bcc309051ae1ee3c5bfb15676d)`()` | Calls the [Init()](#classNTimelineManagerBase_1a14e62840b3a719d76f1a02eee611d8b2) method.
`public virtual  `[`~NTimelineManagerBase`](#classNTimelineManagerBase_1aa0c078bc089e24f179512a91d2219a32)`()` | Calls [Clear()](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054) and release Timeline TSharedPtr
`public virtual void `[`Init`](#classNTimelineManagerBase_1a14e62840b3a719d76f1a02eee611d8b2)`(float _TickInterval,FName _Label)` | Instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Pause`](#classNTimelineManagerBase_1a101a281c4e161a206b1677ce410464ab)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classNTimelineManagerBase_1a460e6b974a885f32e75c39c5d8fd2f50)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classNTimelineManagerBase_1a996371baf5dc0e51a32c14325c1c1091)`()` | This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0
`public virtual void `[`TimerTick`](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)`()` | This checks the actual play state (ENTimelineTimerState) and tick the [NTimeline](#classNTimeline) accordingly.
`public `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManagerBase_1a8b820e0df999f49192073398cc751adf)`() const` | Get the actual state.
`public float `[`GetTickInterval`](#classNTimelineManagerBase_1a85cbb4210b418a6fbda376d6fdd8fe5a)`() const` | Get the tick interval which a timermanager should use to process
`public virtual void `[`SetTickInterval`](#classNTimelineManagerBase_1a45252280e724ebca7b1971e16bdfcb61)`(float _TickInterval)` | Defined the desired ticking interval
`public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classNTimelineManagerBase_1a2e0fb25eed415b60006a5b853d78c9b6)`() const` | Get the coupled [NTimeline](#classNTimeline)
`protected float `[`TickInterval`](#classNTimelineManagerBase_1a194b51bd0c7ac34786bc256b77218f8d) | The interval retrieved from the timeline.
`protected `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManagerBase_1aea2bb1bd9437ff032c686389a7734c1a) | The actual state
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classNTimelineManagerBase_1a1edf40f8bb3b300a8f3d6cb14e539c74) | The coupled timeline
`protected virtual void `[`Clear`](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054)`()` | Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
`protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManagerBase_1a14d64e5d6ed18abaf85d24f8c5f1a598)`()` | This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.
`protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManagerBase_1a34257aba82c08f245f2e2465a24d2071)`()` | This method is call immediately before ticking
`protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManagerBase_1aab9090f586908b3f53ab7938dda511c7)`()` | This method is call immediately after ticking

## Members

#### `public  `[`NTimelineManagerBase`](#classNTimelineManagerBase_1a13e377bcc309051ae1ee3c5bfb15676d)`()` <a id="classNTimelineManagerBase_1a13e377bcc309051ae1ee3c5bfb15676d"></a>

Calls the [Init()](#classNTimelineManagerBase_1a14e62840b3a719d76f1a02eee611d8b2) method.

#### `public virtual  `[`~NTimelineManagerBase`](#classNTimelineManagerBase_1aa0c078bc089e24f179512a91d2219a32)`()` <a id="classNTimelineManagerBase_1aa0c078bc089e24f179512a91d2219a32"></a>

Calls [Clear()](#classNTimelineManagerBase_1a97ba6d8c1ce7e2f7162ddfafbed98054) and release Timeline TSharedPtr

#### `public virtual void `[`Init`](#classNTimelineManagerBase_1a14e62840b3a719d76f1a02eee611d8b2)`(float _TickInterval,FName _Label)` <a id="classNTimelineManagerBase_1a14e62840b3a719d76f1a02eee611d8b2"></a>

Instanciate the embeded [NTimeline](#classNTimeline)

#### Parameters
* `_TickInterval` - Interval time between tick in sec 

* `_Label` - Name of the Timeline.

#### `public virtual void `[`Pause`](#classNTimelineManagerBase_1a101a281c4e161a206b1677ce410464ab)`()` <a id="classNTimelineManagerBase_1a101a281c4e161a206b1677ce410464ab"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classNTimelineManagerBase_1a460e6b974a885f32e75c39c5d8fd2f50)`()` <a id="classNTimelineManagerBase_1a460e6b974a885f32e75c39c5d8fd2f50"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classNTimelineManagerBase_1a996371baf5dc0e51a32c14325c1c1091)`()` <a id="classNTimelineManagerBase_1a996371baf5dc0e51a32c14325c1c1091"></a>

This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0

#### `public virtual void `[`TimerTick`](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)`()` <a id="classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865"></a>

This checks the actual play state (ENTimelineTimerState) and tick the [NTimeline](#classNTimeline) accordingly.

#### `public `[`ENTimelineTimerState`](#TimelineManagerBase_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManagerBase_1a8b820e0df999f49192073398cc751adf)`() const` <a id="classNTimelineManagerBase_1a8b820e0df999f49192073398cc751adf"></a>

Get the actual state.

#### `public float `[`GetTickInterval`](#classNTimelineManagerBase_1a85cbb4210b418a6fbda376d6fdd8fe5a)`() const` <a id="classNTimelineManagerBase_1a85cbb4210b418a6fbda376d6fdd8fe5a"></a>

Get the tick interval which a timermanager should use to process

#### `public virtual void `[`SetTickInterval`](#classNTimelineManagerBase_1a45252280e724ebca7b1971e16bdfcb61)`(float _TickInterval)` <a id="classNTimelineManagerBase_1a45252280e724ebca7b1971e16bdfcb61"></a>

Defined the desired ticking interval

#### `public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classNTimelineManagerBase_1a2e0fb25eed415b60006a5b853d78c9b6)`() const` <a id="classNTimelineManagerBase_1a2e0fb25eed415b60006a5b853d78c9b6"></a>

Get the coupled [NTimeline](#classNTimeline)

#### `protected float `[`TickInterval`](#classNTimelineManagerBase_1a194b51bd0c7ac34786bc256b77218f8d) <a id="classNTimelineManagerBase_1a194b51bd0c7ac34786bc256b77218f8d"></a>

The interval retrieved from the timeline.

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
  : public UNTimelineManagerBaseDecorator
```  

This decorator is fitted to track time when player plays since the game is launched.

It used internally an FTimerManager to tick and to works accordingly with all time alterations (game pause, slowmo, ...). It could be usefull for bonus/malus attribution which works during the full game session.

For example: Player makes a very benevolent actions which gives him a health bonus for 10 minutes in game.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) | Created by the FTimerManager
`public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) | Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)
`public virtual void `[`Init`](#classUNGameLifeTimelineManager_1ab2c4380eca466bf77534b3bfa05f4bb7)`(float _TickInterval,FName _Label)` | It creates the timer with a FTimerManager and attached TimerDelegate to it. 
`public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` | clears timer + unbind delegate + invalidate handle. It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor
`protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) | This is only used for savegame to keep time between sessions
`protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` | A default ctor for engine system

## Members

#### `public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) <a id="classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab"></a>

Created by the FTimerManager

#### `public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) <a id="classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61"></a>

Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865)

#### `public virtual void `[`Init`](#classUNGameLifeTimelineManager_1ab2c4380eca466bf77534b3bfa05f4bb7)`(float _TickInterval,FName _Label)` <a id="classUNGameLifeTimelineManager_1ab2c4380eca466bf77534b3bfa05f4bb7"></a>

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
`public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1aa964eabb3a251ff897114469ac55d60b)`(float _TickInterval,FName _Label)` | Attaches event on level changes It creates the timer with a FTimerManager and attached TimerDelegate to it. 
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

#### `public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1aa964eabb3a251ff897114469ac55d60b)`(float _TickInterval,FName _Label)` <a id="classUNLevelLifeTimelineManager_1aa964eabb3a251ff897114469ac55d60b"></a>

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
  : public UNTimelineManagerBaseDecorator
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
`public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a85eb6e42817fc2d3b4d4aaeab745f7f8)`(float _TickInterval,FName _Label)` | This just init State to "Play" and time variables. The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` | Always returns true 'cause it can be paused or stopped
`public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` | Always returns true 'cause it can be paused or stopped
`public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` | This override methods allows to tick [UNTimelineManagerBaseDecorator::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865) and to increment times vars.
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

#### `public virtual void `[`Init`](#classUNRealLifeTimelineManager_1a85eb6e42817fc2d3b4d4aaeab745f7f8)`(float _TickInterval,FName _Label)` <a id="classUNRealLifeTimelineManager_1a85eb6e42817fc2d3b4d4aaeab745f7f8"></a>

This just init State to "Play" and time variables. The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerBaseDecorator()](#classUNTimelineManagerBaseDecorator_1a6e909ad9b0121e777f066c9a67a7fcd0)

#### Parameters
* `_TickInterval` - Interval time between tick in sec 

* `_Label` - Name of the Timeline.

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` <a id="classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` <a id="classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` <a id="classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e"></a>

This override methods allows to tick [UNTimelineManagerBaseDecorator::TimerTick()](#classNTimelineManagerBase_1af842046499d2023a90ed2d46d0424865) and to increment times vars.

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

# class `UNTimelineClient` <a id="classUNTimelineClient"></a>

```
class UNTimelineClient
  : public UObject
```  

This class should be used by your GameInstance object. This object is the glue for all the timeline configuration and blueprint helpers.

This is the main client which instances timelines from your settings (using [UNTimelineConfig](#classUNTimelineConfig)) and uses by blueprint helpers lib [UNTimelineBlueprintHelpers](#classUNTimelineBlueprintHelpers).

**See also**: [INTimelineGameInstance](#classINTimelineGameInstance). 

**See also**: [UNTimelineConfig](#classUNTimelineConfig) to get more details on the configuration. 

**See also**: [FConfiguredTimeline](#structFConfiguredTimeline) to see how to use Configured Timeline as blueprint pins.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UNTimelineClient`](#classUNTimelineClient_1a5681002cd61186d942306798fd0140fa)`()` | 
`public virtual void `[`Init`](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)`()` | This method allows to instanciate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).
`public `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1a105a6c22f912366f331690d368b4b92f)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` | A blueprint pass-through for GetTimeline(FName Name).
`public `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1ac1bb7f33b8359066db9ea0c9d249776b)`(FName Name) const` | Get the timeline from TimelinesCollection by its name.
`public virtual void `[`Serialize`](#classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27)`(FArchive & Ar)` | It used to save all timelines in the EventStore, and reload them correctly.
`protected TMap< FName, `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * > `[`TimelinesCollection`](#classUNTimelineClient_1a0e9b8211804b16c9832684fac8947943) | Collection of timelines instanciated by [InstanciateTimelinesFromConfig()](#classUNTimelineClient_1a975de7e3dace38650ce072a999f21866)
`protected void `[`InstanciateTimelinesFromConfig`](#classUNTimelineClient_1a975de7e3dace38650ce072a999f21866)`()` | 

## Members

#### `public  `[`UNTimelineClient`](#classUNTimelineClient_1a5681002cd61186d942306798fd0140fa)`()` <a id="classUNTimelineClient_1a5681002cd61186d942306798fd0140fa"></a>

#### `public virtual void `[`Init`](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)`()` <a id="classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615"></a>

This method allows to instanciate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).

**See also**: [FConfiguredTimeline](#structFConfiguredTimeline)

#### `public `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1a105a6c22f912366f331690d368b4b92f)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` <a id="classUNTimelineClient_1a105a6c22f912366f331690d368b4b92f"></a>

A blueprint pass-through for GetTimeline(FName Name).

#### Parameters
* `Config` - To allow having a combobox of configured timeline

#### `public `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1ac1bb7f33b8359066db9ea0c9d249776b)`(FName Name) const` <a id="classUNTimelineClient_1ac1bb7f33b8359066db9ea0c9d249776b"></a>

Get the timeline from TimelinesCollection by its name.

#### Parameters
* `Name` - The name of the timeline

#### `public virtual void `[`Serialize`](#classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27)`(FArchive & Ar)` <a id="classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27"></a>

It used to save all timelines in the EventStore, and reload them correctly.

#### Parameters
* `Ar` - Archive for save and load

#### `protected TMap< FName, `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * > `[`TimelinesCollection`](#classUNTimelineClient_1a0e9b8211804b16c9832684fac8947943) <a id="classUNTimelineClient_1a0e9b8211804b16c9832684fac8947943"></a>

Collection of timelines instanciated by [InstanciateTimelinesFromConfig()](#classUNTimelineClient_1a975de7e3dace38650ce072a999f21866)

#### `protected void `[`InstanciateTimelinesFromConfig`](#classUNTimelineClient_1a975de7e3dace38650ce072a999f21866)`()` <a id="classUNTimelineClient_1a975de7e3dace38650ce072a999f21866"></a>

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

# class `UNTimelineDecorator` <a id="classUNTimelineDecorator"></a>

```
class UNTimelineDecorator
  : public UObject
  : public NTimeline
```  

The decorator for [NTimeline](#classNTimeline) object.

It manages:

* serialization

* attachment of [UNTimelineEventDecorator](#classUNTimelineEventDecorator) object to the embeded [NTimeline](#classNTimeline)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNTimelineDecorator`](#classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0)`()` | Just a default ctor for UObject paradigme
`public virtual void `[`Init`](#classUNTimelineDecorator_1a0c34d54decdfcac0381b442d4b8ef149)`(`[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * TimelineManager,FName _Label)` | this method is used to instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Clear`](#classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`SetTickInterval`](#classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d)`(float _TickInterval)` | This should be called only by its friend [NTimelineManagerBase](#classNTimelineManagerBase) or a decorator to maintain consistency with its manager.
`public virtual void `[`SetCurrentTime`](#classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce)`(float _CurrentTime)` | This method is mainly used for savegame serialization
`public virtual float `[`GetCurrentTime`](#classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2)`() const` | Get CurrentTime
`public virtual void `[`SetLabel`](#classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763)`(FName _Label)` | Give a name to this timeline 
`public virtual FName `[`GetLabel`](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)`() const` | Return the actual name
`public virtual void `[`NotifyTick`](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.
`public inline virtual bool `[`Attached`](#classUNTimelineDecorator_1af3cb0bb3aa22bf7565ed71f1c017f257)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` | This object should works only with Decorators. This method is reserved for core objects. 
`public inline virtual void `[`Attached`](#classUNTimelineDecorator_1a2738256232901e69e74486646800a863)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` | This object should works only with Decorators. This method is reserved for core objects. 
`public virtual void `[`BeginDestroy`](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3)`()` | 
`public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classUNTimelineDecorator_1a9a6bbca89ea46144620ad58c789e149b)`() const` | 
`public virtual bool `[`Attached`](#classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9)`(`[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * Event)` | This method is made to work with decorators object. It will save data in the EventStore array for serialization and save game. 
`public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71)`() const` | This retrieve the EventStore
`public void `[`OnEventExpired`](#classUNTimelineDecorator_1a0b6e397563659c991c733996e2ea753e)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float & ExpiredTime,const int32 & Index)` | A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a7eca090412c8d34e3c598d7769173040). It controls the EventStore data refreshing.
`public virtual void `[`Serialize`](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9)`(FArchive & Ar)` | It used to save all events state in the EventStore, and reload them correclty.
`public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a)`(TSubclassOf< `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` > Class,FName Name,float Duration,float Delay)` | Creates a new Event and use this timeline as the outer for this new object.
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76) | The embeded object
`protected virtual void `[`RefreshRecordData`](#classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a)`(const int32 & Index)` | This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

## Members

#### `public inline  `[`UNTimelineDecorator`](#classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0)`()` <a id="classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0"></a>

Just a default ctor for UObject paradigme

#### `public virtual void `[`Init`](#classUNTimelineDecorator_1a0c34d54decdfcac0381b442d4b8ef149)`(`[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` * TimelineManager,FName _Label)` <a id="classUNTimelineDecorator_1a0c34d54decdfcac0381b442d4b8ef149"></a>

this method is used to instanciate the embeded [NTimeline](#classNTimeline)
#### Parameters
* `TimelineManager` - The Decorator which provide the [NTimelineManagerBase](#classNTimelineManagerBase) object.

#### `public virtual void `[`Clear`](#classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305)`()` <a id="classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305"></a>

This completely reset every events. It should be used with caution.

#### `public virtual void `[`SetTickInterval`](#classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d)`(float _TickInterval)` <a id="classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d"></a>

This should be called only by its friend [NTimelineManagerBase](#classNTimelineManagerBase) or a decorator to maintain consistency with its manager.

#### `public virtual void `[`SetCurrentTime`](#classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce)`(float _CurrentTime)` <a id="classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce"></a>

This method is mainly used for savegame serialization

#### `public virtual float `[`GetCurrentTime`](#classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2)`() const` <a id="classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2"></a>

Get CurrentTime

#### `public virtual void `[`SetLabel`](#classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763)`(FName _Label)` <a id="classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763"></a>

Give a name to this timeline 
#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)`() const` <a id="classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04"></a>

Return the actual name

#### `public virtual void `[`NotifyTick`](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)`()` <a id="classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414"></a>

This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.

#### `public inline virtual bool `[`Attached`](#classUNTimelineDecorator_1af3cb0bb3aa22bf7565ed71f1c017f257)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event)` <a id="classUNTimelineDecorator_1af3cb0bb3aa22bf7565ed71f1c017f257"></a>

This object should works only with Decorators. This method is reserved for core objects. 
**See also**: [UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)](#classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9)

#### `public inline virtual void `[`Attached`](#classUNTimelineDecorator_1a2738256232901e69e74486646800a863)`(TArray< TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` >> EventsCollection)` <a id="classUNTimelineDecorator_1a2738256232901e69e74486646800a863"></a>

This object should works only with Decorators. This method is reserved for core objects. 
**See also**: [UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)](#classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9)

#### `public virtual void `[`BeginDestroy`](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3)`()` <a id="classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3"></a>

#### `public TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`GetTimeline`](#classUNTimelineDecorator_1a9a6bbca89ea46144620ad58c789e149b)`() const` <a id="classUNTimelineDecorator_1a9a6bbca89ea46144620ad58c789e149b"></a>

#### `public virtual bool `[`Attached`](#classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9)`(`[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * Event)` <a id="classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9"></a>

This method is made to work with decorators object. It will save data in the EventStore array for serialization and save game. 
#### Parameters
* `Event` - The decorator event

#### `public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71)`() const` <a id="classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71"></a>

This retrieve the EventStore

#### `public void `[`OnEventExpired`](#classUNTimelineDecorator_1a0b6e397563659c991c733996e2ea753e)`(TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classUNTimelineDecorator_1a0b6e397563659c991c733996e2ea753e"></a>

A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a7eca090412c8d34e3c598d7769173040). It controls the EventStore data refreshing.

#### Parameters
* `Event` - The native Event which will be killed 

* `ExpiredTime` - The time when this event expires 

* `Index` - The index of the NTimeline::Events array

#### `public virtual void `[`Serialize`](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9)`(FArchive & Ar)` <a id="classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9"></a>

It used to save all events state in the EventStore, and reload them correclty.

#### Parameters
* `Ar` - Archive for save and load

#### `public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a)`(TSubclassOf< `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a"></a>

Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76) <a id="classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76"></a>

The embeded object

#### `protected virtual void `[`RefreshRecordData`](#classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a)`(const int32 & Index)` <a id="classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a"></a>

This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

#### Parameters
* `Index` - The index of the NTimeline::Events array 

* `Record` - The record you want to synchronize.

# class `UNTimelineEventDecorator` <a id="classUNTimelineEventDecorator"></a>

```
class UNTimelineEventDecorator
  : public UObject
  : public NTimelineEventBase
```  

Base abstract class to create [NTimelineEventBase](#classNTimelineEventBase) decorators (Blueprint or c++).

For a simple usage with blueprint: you can derived blueprint base on this. This way the [NTimelineEventBase](#classNTimelineEventBase) instance should only manage timeline behavior.

For a more complex usage in c++: You should derive this and [NTimelineEventBase](#classNTimelineEventBase) too to fit on your needs.

* This class should only manage specifics behaviors related to the engine (serialization, blueprint's specifics functionnalities, etc...)

* [NTimelineEventBase](#classNTimelineEventBase)'s derivation: all your core functionnalities

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual bool `[`IsExpired`](#classUNTimelineEventDecorator_1ac11dd7e6de7a67eb356a1825a91eec1e)`() const` | It computes with Duration and LocalTime
`public virtual const float `[`GetLocalTime`](#classUNTimelineEventDecorator_1a0ecd57e2c1f178872a7e00609de5af96)`() const` | Getter for LocalTime
`public virtual const float `[`GetStartedAt`](#classUNTimelineEventDecorator_1acce6926764453b2ecfe60fb403ee5560)`() const` | Getter for StartedAt
`public virtual float `[`GetDuration`](#classUNTimelineEventDecorator_1a1d892fb0ad8efa79a1ddf9ba0015e839)`() const` | Getter for Duration
`public virtual void `[`Start`](#classUNTimelineEventDecorator_1aee8fc5e9081296932f04949aa6e58d50)`(float StartTime)` | A setter for StartedAt
`public virtual void `[`NotifyAddTime`](#classUNTimelineEventDecorator_1ac9c3fdd62c4d547c5909f10d2ccf3b1e)`(float NewTime)` | Increments LocalTime 
`public virtual float `[`GetDelay`](#classUNTimelineEventDecorator_1a0ba4d9f852532ad06644bf55f3088031)`() const` | Increments LocalTime
`public virtual const FName `[`GetEventLabel`](#classUNTimelineEventDecorator_1a1dcd9d2632b0265d56598e932e6e7aa5)`() const` | Getter for Label
`public virtual void `[`BeginDestroy`](#classUNTimelineEventDecorator_1a3fc7b4e7b505a3001fc5c4d2ae11e8d7)`()` | 
`public virtual void `[`Serialize`](#classUNTimelineEventDecorator_1acb4464b908a3b2aa6bc60afe30437aca)`(FArchive & Ar)` | 
`public void `[`SetDelay`](#classUNTimelineEventDecorator_1a45d70a38cae52f44d655eb6c55d53264)`(float _Delay)` | 
`public void `[`SetDuration`](#classUNTimelineEventDecorator_1a4c966f3267548ce908de0cfb78c29422)`(float _Duration)` | 
`public virtual void `[`Init`](#classUNTimelineEventDecorator_1abe02f735cb2b2da92c3ea8ed32700e43)`(FName _Label)` | This is where the Core object is instanciated. You should override this to instanciate your derived core object.
`public TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`GetEvent`](#classUNTimelineEventDecorator_1ab6318b7cca1ec5f3a121196736be775e)`()` | This is used by other decorators which need to pass the core object to their own. 
`protected TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`Event`](#classUNTimelineEventDecorator_1ae554245067cc3f60cc7cf6f57f268129) | The actual decorator is for this object. It shoulds be instanciate on a ctor or a dedicated init function
`protected inline  `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator_1ade7acd676694c8d41304c42cb01ec4db)`()` | Default ctor for the engine

## Members

#### `public virtual bool `[`IsExpired`](#classUNTimelineEventDecorator_1ac11dd7e6de7a67eb356a1825a91eec1e)`() const` <a id="classUNTimelineEventDecorator_1ac11dd7e6de7a67eb356a1825a91eec1e"></a>

It computes with Duration and LocalTime

#### `public virtual const float `[`GetLocalTime`](#classUNTimelineEventDecorator_1a0ecd57e2c1f178872a7e00609de5af96)`() const` <a id="classUNTimelineEventDecorator_1a0ecd57e2c1f178872a7e00609de5af96"></a>

Getter for LocalTime

#### `public virtual const float `[`GetStartedAt`](#classUNTimelineEventDecorator_1acce6926764453b2ecfe60fb403ee5560)`() const` <a id="classUNTimelineEventDecorator_1acce6926764453b2ecfe60fb403ee5560"></a>

Getter for StartedAt

#### `public virtual float `[`GetDuration`](#classUNTimelineEventDecorator_1a1d892fb0ad8efa79a1ddf9ba0015e839)`() const` <a id="classUNTimelineEventDecorator_1a1d892fb0ad8efa79a1ddf9ba0015e839"></a>

Getter for Duration

#### `public virtual void `[`Start`](#classUNTimelineEventDecorator_1aee8fc5e9081296932f04949aa6e58d50)`(float StartTime)` <a id="classUNTimelineEventDecorator_1aee8fc5e9081296932f04949aa6e58d50"></a>

A setter for StartedAt

#### `public virtual void `[`NotifyAddTime`](#classUNTimelineEventDecorator_1ac9c3fdd62c4d547c5909f10d2ccf3b1e)`(float NewTime)` <a id="classUNTimelineEventDecorator_1ac9c3fdd62c4d547c5909f10d2ccf3b1e"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual float `[`GetDelay`](#classUNTimelineEventDecorator_1a0ba4d9f852532ad06644bf55f3088031)`() const` <a id="classUNTimelineEventDecorator_1a0ba4d9f852532ad06644bf55f3088031"></a>

Increments LocalTime

#### `public virtual const FName `[`GetEventLabel`](#classUNTimelineEventDecorator_1a1dcd9d2632b0265d56598e932e6e7aa5)`() const` <a id="classUNTimelineEventDecorator_1a1dcd9d2632b0265d56598e932e6e7aa5"></a>

Getter for Label

#### `public virtual void `[`BeginDestroy`](#classUNTimelineEventDecorator_1a3fc7b4e7b505a3001fc5c4d2ae11e8d7)`()` <a id="classUNTimelineEventDecorator_1a3fc7b4e7b505a3001fc5c4d2ae11e8d7"></a>

#### `public virtual void `[`Serialize`](#classUNTimelineEventDecorator_1acb4464b908a3b2aa6bc60afe30437aca)`(FArchive & Ar)` <a id="classUNTimelineEventDecorator_1acb4464b908a3b2aa6bc60afe30437aca"></a>

#### `public void `[`SetDelay`](#classUNTimelineEventDecorator_1a45d70a38cae52f44d655eb6c55d53264)`(float _Delay)` <a id="classUNTimelineEventDecorator_1a45d70a38cae52f44d655eb6c55d53264"></a>

#### `public void `[`SetDuration`](#classUNTimelineEventDecorator_1a4c966f3267548ce908de0cfb78c29422)`(float _Duration)` <a id="classUNTimelineEventDecorator_1a4c966f3267548ce908de0cfb78c29422"></a>

#### `public virtual void `[`Init`](#classUNTimelineEventDecorator_1abe02f735cb2b2da92c3ea8ed32700e43)`(FName _Label)` <a id="classUNTimelineEventDecorator_1abe02f735cb2b2da92c3ea8ed32700e43"></a>

This is where the Core object is instanciated. You should override this to instanciate your derived core object.

#### `public TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`GetEvent`](#classUNTimelineEventDecorator_1ab6318b7cca1ec5f3a121196736be775e)`()` <a id="classUNTimelineEventDecorator_1ab6318b7cca1ec5f3a121196736be775e"></a>

This is used by other decorators which need to pass the core object to their own. 
**See also**: [UNTimelineDecorator::Attached()](#classUNTimelineDecorator_1af3cb0bb3aa22bf7565ed71f1c017f257)

#### `protected TSharedPtr< `[`NTimelineEventBase`](#classNTimelineEventBase)` > `[`Event`](#classUNTimelineEventDecorator_1ae554245067cc3f60cc7cf6f57f268129) <a id="classUNTimelineEventDecorator_1ae554245067cc3f60cc7cf6f57f268129"></a>

The actual decorator is for this object. It shoulds be instanciate on a ctor or a dedicated init function

#### `protected inline  `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator_1ade7acd676694c8d41304c42cb01ec4db)`()` <a id="classUNTimelineEventDecorator_1ade7acd676694c8d41304c42cb01ec4db"></a>

Default ctor for the engine

# class `UNTimelineEventDecoratorFake` <a id="classUNTimelineEventDecoratorFake"></a>

```
class UNTimelineEventDecoratorFake
  : public UNTimelineEventDecorator
```  

This class is used for tests only

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNTimelineGameInstance` <a id="classUNTimelineGameInstance"></a>

```
class UNTimelineGameInstance
  : public UInterface
```  

**See also**: [INTimelineGameInstance](#classINTimelineGameInstance)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNTimelineManagerBaseDecorator` <a id="classUNTimelineManagerBaseDecorator"></a>

```
class UNTimelineManagerBaseDecorator
  : public UObject
  : public NTimelineManagerBase
```  

This is the abstract decorator that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or c++.

As the close relation between [NTimelineManagerBase](#classNTimelineManagerBase) and [NTimeline](#classNTimeline) classes (core lib), This class is coupled with [UNTimelineDecorator](#classUNTimelineDecorator). 
**See also**: [UNTimelineDecorator](#classUNTimelineDecorator)

To ease blueprint usages, most of the [UNTimelineDecorator](#classUNTimelineDecorator) public functionnalities are accessible here. This class works as a pass-through too for [UNTimelineDecorator](#classUNTimelineDecorator).

**See also**: [AddEvent()](#classUNTimelineManagerBaseDecorator_1ae02c91bae037a13209ac0d434567bf99), [CreateNewEvent()](#classUNTimelineManagerBaseDecorator_1a67a63b68e9e6bac3824e0e1baab31313), [CreateAndAddNewEvent()](#classUNTimelineManagerBaseDecorator_1adeb6a64d741a09925443d7cfd559214c)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Pause`](#classUNTimelineManagerBaseDecorator_1a9abb209019d5b48f98b25eb9781168c2)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classUNTimelineManagerBaseDecorator_1a2f2f9aa7c7dd2d4bf67ce27495b0c6b2)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classUNTimelineManagerBaseDecorator_1adbf456c7877d96747d3587aba50cf7a6)`()` | This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0
`public virtual void `[`SetTickInterval`](#classUNTimelineManagerBaseDecorator_1aa20e8e3fc7d873671f34f19c04a58683)`(float _TickInterval)` | Defined the desired ticking interval
`public virtual void `[`Init`](#classUNTimelineManagerBaseDecorator_1a8bdbcd3c7057202ca64f3066432b64a9)`(float _TickInterval,FName _Label)` | The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public virtual void `[`Clear`](#classUNTimelineManagerBaseDecorator_1a6cf119d232cc8eca846516602c370bf1)`()` | It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor
`public virtual void `[`Serialize`](#classUNTimelineManagerBaseDecorator_1a2157f4309709b2f3cb3aa145cce7624b)`(FArchive & Ar)` | It's the starting link of serialization chain for all embeded decorators. This calls [UNTimelineDecorator::Serialize()](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9).
`public virtual void `[`BeginDestroy`](#classUNTimelineManagerBaseDecorator_1a969904b7e92bc8252ef540e5bb97909b)`()` | This call the [UNTimelineDecorator::BeginDestroy()](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3) too.
`public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerBaseDecorator_1a22f5c3b5d0b9e4f3dc099098a03aabdc)`() const` | Get the events list. TODO should be great to have a type filter possibility with a TSubclassOf<UNTimelineEventDecorator> parameter
`public float `[`GetCurrentTime`](#classUNTimelineManagerBaseDecorator_1a72af9f0d56fd516331eea4b260746c8b)`() const` | 
`public FName `[`GetLabel`](#classUNTimelineManagerBaseDecorator_1aa0e8960938aa54e96aef73b3780486b8)`() const` | A pass-through for the embeded [UNTimelineDecorator::GetLabel()](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)
`public virtual void `[`AddEvent`](#classUNTimelineManagerBaseDecorator_1ae02c91bae037a13209ac0d434567bf99)`(`[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * Event)` | Adds an event to the timeline object, it works as a pass-through for [UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)](#classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9)
`public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineManagerBaseDecorator_1a67a63b68e9e6bac3824e0e1baab31313)`(TSubclassOf< `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` > Class,FName Name,float Duration,float Delay)` | A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a): Creates a new Event and use this timeline as the outer for this new object.
`public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerBaseDecorator_1adeb6a64d741a09925443d7cfd559214c)`(TSubclassOf< `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` > Class,FName Name,float Duration,float Delay)` | Attaches the event to the timeline stream + A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a): Creates a new Event and use this timeline as the outer for this new object.
`protected `[`UNTimelineDecorator`](#classUNTimelineDecorator)` * `[`MyTimeline`](#classUNTimelineManagerBaseDecorator_1ad57c59a935c911cdde1f3f6419f12d09) | the timeline associated to this manager.
`protected  `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator_1a6e909ad9b0121e777f066c9a67a7fcd0)`()` | Protected ctor to force instanciation with [CreateObject()](#classUNTimelineManagerBaseDecorator_1acf2950242fb5298502597500305686e3) methods (factory methods).

## Members

#### `public virtual void `[`Pause`](#classUNTimelineManagerBaseDecorator_1a9abb209019d5b48f98b25eb9781168c2)`()` <a id="classUNTimelineManagerBaseDecorator_1a9abb209019d5b48f98b25eb9781168c2"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classUNTimelineManagerBaseDecorator_1a2f2f9aa7c7dd2d4bf67ce27495b0c6b2)`()` <a id="classUNTimelineManagerBaseDecorator_1a2f2f9aa7c7dd2d4bf67ce27495b0c6b2"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classUNTimelineManagerBaseDecorator_1adbf456c7877d96747d3587aba50cf7a6)`()` <a id="classUNTimelineManagerBaseDecorator_1adbf456c7877d96747d3587aba50cf7a6"></a>

This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0

#### `public virtual void `[`SetTickInterval`](#classUNTimelineManagerBaseDecorator_1aa20e8e3fc7d873671f34f19c04a58683)`(float _TickInterval)` <a id="classUNTimelineManagerBaseDecorator_1aa20e8e3fc7d873671f34f19c04a58683"></a>

Defined the desired ticking interval

#### `public virtual void `[`Init`](#classUNTimelineManagerBaseDecorator_1a8bdbcd3c7057202ca64f3066432b64a9)`(float _TickInterval,FName _Label)` <a id="classUNTimelineManagerBaseDecorator_1a8bdbcd3c7057202ca64f3066432b64a9"></a>

The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerBaseDecorator()](#classUNTimelineManagerBaseDecorator_1a6e909ad9b0121e777f066c9a67a7fcd0)

#### Parameters
* `_TickInterval` - Interval time between tick in sec 

* `_Label` - Name of the Timeline.

#### `public virtual void `[`Clear`](#classUNTimelineManagerBaseDecorator_1a6cf119d232cc8eca846516602c370bf1)`()` <a id="classUNTimelineManagerBaseDecorator_1a6cf119d232cc8eca846516602c370bf1"></a>

It is called by the parent [NTimelineManagerBase](#classNTimelineManagerBase) on dtor

#### `public virtual void `[`Serialize`](#classUNTimelineManagerBaseDecorator_1a2157f4309709b2f3cb3aa145cce7624b)`(FArchive & Ar)` <a id="classUNTimelineManagerBaseDecorator_1a2157f4309709b2f3cb3aa145cce7624b"></a>

It's the starting link of serialization chain for all embeded decorators. This calls [UNTimelineDecorator::Serialize()](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9).

#### Parameters
* `Ar` - the FArchive used for serialization as usual.

#### `public virtual void `[`BeginDestroy`](#classUNTimelineManagerBaseDecorator_1a969904b7e92bc8252ef540e5bb97909b)`()` <a id="classUNTimelineManagerBaseDecorator_1a969904b7e92bc8252ef540e5bb97909b"></a>

This call the [UNTimelineDecorator::BeginDestroy()](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3) too.

#### `public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerBaseDecorator_1a22f5c3b5d0b9e4f3dc099098a03aabdc)`() const` <a id="classUNTimelineManagerBaseDecorator_1a22f5c3b5d0b9e4f3dc099098a03aabdc"></a>

Get the events list. TODO should be great to have a type filter possibility with a TSubclassOf<UNTimelineEventDecorator> parameter

#### `public float `[`GetCurrentTime`](#classUNTimelineManagerBaseDecorator_1a72af9f0d56fd516331eea4b260746c8b)`() const` <a id="classUNTimelineManagerBaseDecorator_1a72af9f0d56fd516331eea4b260746c8b"></a>

#### `public FName `[`GetLabel`](#classUNTimelineManagerBaseDecorator_1aa0e8960938aa54e96aef73b3780486b8)`() const` <a id="classUNTimelineManagerBaseDecorator_1aa0e8960938aa54e96aef73b3780486b8"></a>

A pass-through for the embeded [UNTimelineDecorator::GetLabel()](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)

#### `public virtual void `[`AddEvent`](#classUNTimelineManagerBaseDecorator_1ae02c91bae037a13209ac0d434567bf99)`(`[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * Event)` <a id="classUNTimelineManagerBaseDecorator_1ae02c91bae037a13209ac0d434567bf99"></a>

Adds an event to the timeline object, it works as a pass-through for [UNTimelineDecorator::Attached(UNTimelineEventDecorator* Event)](#classUNTimelineDecorator_1ad75f00d59b60404ae053f15dc9db8db9)

#### Parameters
* `Event` - An Event object you want to saved to the associated timeline.

#### `public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineManagerBaseDecorator_1a67a63b68e9e6bac3824e0e1baab31313)`(TSubclassOf< `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerBaseDecorator_1a67a63b68e9e6bac3824e0e1baab31313"></a>

A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a): Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerBaseDecorator_1adeb6a64d741a09925443d7cfd559214c)`(TSubclassOf< `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerBaseDecorator_1adeb6a64d741a09925443d7cfd559214c"></a>

Attaches the event to the timeline stream + A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1a60e54308538c299ed44bbabe46a9f54a): Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected `[`UNTimelineDecorator`](#classUNTimelineDecorator)` * `[`MyTimeline`](#classUNTimelineManagerBaseDecorator_1ad57c59a935c911cdde1f3f6419f12d09) <a id="classUNTimelineManagerBaseDecorator_1ad57c59a935c911cdde1f3f6419f12d09"></a>

the timeline associated to this manager.

#### `protected  `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator_1a6e909ad9b0121e777f066c9a67a7fcd0)`()` <a id="classUNTimelineManagerBaseDecorator_1a6e909ad9b0121e777f066c9a67a7fcd0"></a>

Protected ctor to force instanciation with [CreateObject()](#classUNTimelineManagerBaseDecorator_1acf2950242fb5298502597500305686e3) methods (factory methods).

It instanciates the embeded timeline with CreateDefaultSubobject().

# struct `FConfiguredTimeline` <a id="structFConfiguredTimeline"></a>

This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) | This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.
`public TSubclassOf< `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` > `[`TimelineClass`](#structFConfiguredTimeline_1a22929f5a3baa5bd80d4cee8388e46c58) | The Configured Timeline class
`public float `[`TickInterval`](#structFConfiguredTimeline_1a8b27824729746bb4b3bf22502bad83a5) | You can use this to add more or less frequency between each tick.

## Members

#### `public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) <a id="structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6"></a>

This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.

#### `public TSubclassOf< `[`UNTimelineManagerBaseDecorator`](#classUNTimelineManagerBaseDecorator)` > `[`TimelineClass`](#structFConfiguredTimeline_1a22929f5a3baa5bd80d4cee8388e46c58) <a id="structFConfiguredTimeline_1a22929f5a3baa5bd80d4cee8388e46c58"></a>

The Configured Timeline class

#### `public float `[`TickInterval`](#structFConfiguredTimeline_1a8b27824729746bb4b3bf22502bad83a5) <a id="structFConfiguredTimeline_1a8b27824729746bb4b3bf22502bad83a5"></a>

You can use this to add more or less frequency between each tick.

# struct `FNEventRecord` <a id="structFNEventRecord"></a>

This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a632c8756e47d7e95507296250c40e6db) and a record object used for savegame.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`Event`](#structFNEventRecord_1afb0048f17e06e5940567c8d44a70e0e4) | The [UNTimelineEventDecorator](#classUNTimelineEventDecorator) object
`public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) | The time it as been attached to the timeline in secs (differ to [UNTimelineEventDecorator::StartedAt](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903))
`public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) | The delay before starting in secs
`public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) | The duration this event lives in secs (0 means inderterminate)
`public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) | The name of the event
`public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) | Expiration time of this event in secs (0 means can't expired))
`public FString `[`EventClassName`](#structFNEventRecord_1a5ebb6654bd18ffe427e104f74fd9ba93) | This is used only for serialization, it allow to re-instance the object on load
`public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` | 
`public inline  `[`FNEventRecord`](#structFNEventRecord_1aa3c4071415ba82c502a7b2773146d277)`(`[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` | 
`public void `[`Serialize`](#structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4)`(FArchive & Ar,`[`UNTimelineDecorator`](#classUNTimelineDecorator)` * Timeline)` | It manages Event object saving and loading

## Members

#### `public `[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * `[`Event`](#structFNEventRecord_1afb0048f17e06e5940567c8d44a70e0e4) <a id="structFNEventRecord_1afb0048f17e06e5940567c8d44a70e0e4"></a>

The [UNTimelineEventDecorator](#classUNTimelineEventDecorator) object

#### `public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) <a id="structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d"></a>

The time it as been attached to the timeline in secs (differ to [UNTimelineEventDecorator::StartedAt](#classNTimelineEventBase_1a0d9a9e42434db48807788d71a67a9903))

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

#### `public inline  `[`FNEventRecord`](#structFNEventRecord_1aa3c4071415ba82c502a7b2773146d277)`(`[`UNTimelineEventDecorator`](#classUNTimelineEventDecorator)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` <a id="structFNEventRecord_1aa3c4071415ba82c502a7b2773146d277"></a>

#### `public void `[`Serialize`](#structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4)`(FArchive & Ar,`[`UNTimelineDecorator`](#classUNTimelineDecorator)` * Timeline)` <a id="structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4"></a>

It manages Event object saving and loading

Generated by [Moxygen](https://sourcey.com/moxygen)