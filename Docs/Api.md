# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`UNEventDecoratorFactory`](#namespaceUNEventDecoratorFactory) | Factory functions to help creating event decorators.
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | Required to create a UE4 module
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | Required to create a UE4 module
`class `[`FTimelinePinFactory`](#classFTimelinePinFactory) | It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.
`class `[`INTimelineGameInstance`](#classINTimelineGameInstance) | This interface should be implemented by your GameInstance class or blueprint object. See ../README.md in step by step guide to see how to implements it.
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NEvent`](#classNEvent) | **See also**: [NEventInterface](#classNEventInterface)
`class `[`NEventInterface`](#classNEventInterface) | An interface to manage events which can be attached to a timeline.
`class `[`NTimeline`](#classNTimeline) | **See also**: [NTimelineInterface](#classNTimelineInterface)
`class `[`NTimelineInterface`](#classNTimelineInterface) | Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManager](#classNTimelineManager) class is dedicated to handle it.
`class `[`NTimelineManager`](#classNTimelineManager) | This class is the client for the [NTimelineInterface](#classNTimelineInterface) object. Its goal is to decoupled client interface with timeline management.
`class `[`NUnrealEventProxy`](#classNUnrealEventProxy) | This class is just a pass-through to allows an [UNEventDecorator](#classUNEventDecorator) (a derived UObject) to be passed on the core system using TSharedPtr.
`class `[`NUnrealTimelineProxy`](#classNUnrealTimelineProxy) | This class is a pass-through to allows an [NUnrealTimelineProxy](#classNUnrealTimelineProxy) (a derived UObject) to be passed on the core system using TSharedPtr, and it manages [NUnrealEventProxy](#classNUnrealEventProxy) attachment .
`class `[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin) | This class allows to create a dedicated pin to get names from [UNTimelineConfig](#classUNTimelineConfig).
`class `[`UNEventDecorator`](#classUNEventDecorator) | Base abstract class to create [NEventInterface](#classNEventInterface) decorators (Blueprint or c++).
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | This decorator is fitted to track time when player plays since the game is launched.
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | It tracks game session but refreshes when level changed.
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | It tracks realtime, it is not altered by pause or slowmo.
`class `[`UNTimelineBlueprintHelpers`](#classUNTimelineBlueprintHelpers) | A simple Blueprint Library class to manage Timeline creation.
`class `[`UNTimelineClient`](#classUNTimelineClient) | This class should be used by your GameInstance object. This object is the glue for all the timeline configuration and blueprint helpers.
`class `[`UNTimelineConfig`](#classUNTimelineConfig) | A simple configuration to ease timeline instanciation for developpers.
`class `[`UNTimelineDecorator`](#classUNTimelineDecorator) | The decorator for [NTimelineInterface](#classNTimelineInterface) object.
`class `[`UNTimelineGameInstance`](#classUNTimelineGameInstance) | **See also**: [INTimelineGameInstance](#classINTimelineGameInstance)
`class `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator) | This is the abstract decorator that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or UE4 c++ paradigm.
`class `[`UNTimelineManagerDecoratorFactory`](#classUNTimelineManagerDecoratorFactory) | This class is a factory to managed properly [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) instanciation.
`struct `[`FConfiguredTimeline`](#structFConfiguredTimeline) | This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.
`struct `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf) | This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.
`struct `[`FNEventRecord`](#structFNEventRecord) | This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5) and a record object used for savegame.

# namespace `UNEventDecoratorFactory` <a id="namespaceUNEventDecoratorFactory"></a>

Factory functions to help creating event decorators.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`static T * `[`CreateObject`](#namespaceUNEventDecoratorFactory_1acc8cc41bc9714c3d5e9839fde6ee21f1)`(UObject * Outer,const TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,EObjectFlags Flags)`            | This will instanciate a new Event decorator based on class [UNEventDecorator](#classUNEventDecorator). It uses [UNEventDecorator::Init()](#classUNEventDecorator_1ad591c3d4e879b2423e5a61915599f562) function too to have a fully initialized object.

## Members

#### `public template<>`  <br/>`static T * `[`CreateObject`](#namespaceUNEventDecoratorFactory_1acc8cc41bc9714c3d5e9839fde6ee21f1)`(UObject * Outer,const TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,EObjectFlags Flags)` <a id="namespaceUNEventDecoratorFactory_1acc8cc41bc9714c3d5e9839fde6ee21f1"></a>

This will instanciate a new Event decorator based on class [UNEventDecorator](#classUNEventDecorator). It uses [UNEventDecorator::Init()](#classUNEventDecorator_1ad591c3d4e879b2423e5a61915599f562) function too to have a fully initialized object.

#### Parameters
* `Outer` - The UObject outer 

* `Class` - A subclass of [UNEventDecorator](#classUNEventDecorator)

* `Name` - (optionnal) the name you want this event is called, it gives a generated ones if not provided 

* `Flags` - Flag for GC management

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

This interface should be implemented by your GameInstance class or blueprint object. See ../README.md in step by step guide to see how to implements it.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classINTimelineGameInstance_1a8744c686532c01f502c3e2d452315597)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Timeline) const` | A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).
`public virtual `[`UNTimelineClient`](#classUNTimelineClient)` * `[`GetClient`](#classINTimelineGameInstance_1a927298bbbf2a61d86765e08eb2765aad)`() const` | 

## Members

#### `public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classINTimelineGameInstance_1a8744c686532c01f502c3e2d452315597)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Timeline) const` <a id="classINTimelineGameInstance_1a8744c686532c01f502c3e2d452315597"></a>

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

# class `NEvent` <a id="classNEvent"></a>

```
class NEvent
  : public NEventInterface
```  

**See also**: [NEventInterface](#classNEventInterface)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FNEventDelegate `[`EventStart`](#classNEvent_1a3363b57e254a8df6717d816804f0ced3) | 
`public  `[`NEvent`](#classNEvent_1aac75c1f215cd691c48e87495f2131686)`()` | Default ctor
`public  `[`NEvent`](#classNEvent_1a15c6d7063b5857607cfb0d91446d8241)`(FName _Label,FString _UId)` | Ctor to gives directly a name for this event and an Id (optionnal).
`public inline virtual  `[`~NEvent`](#classNEvent_1a179af95c5b72caf083dc7dbbda577244)`()` | Default dtor
`public virtual bool `[`IsExpired`](#classNEvent_1a035106bed5f526ecf68ae7b067e7beff)`() const` | It indicates if the event expired. It is computed with Duration and LocalTime
`public virtual const float `[`GetLocalTime`](#classNEvent_1a74e7fae4f40337ca18e115280d7ebf7f)`() const` | Returns the localTime since the events has been attached (- delay) to a timeline
`public virtual const float `[`GetStartedAt`](#classNEvent_1a65f998aadcef8a8036f977c5f5226eee)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public virtual float `[`GetDuration`](#classNEvent_1a27aa249bec02b2132fff7b521731ee81)`() const` | The duration this event should live
`public virtual void `[`Start`](#classNEvent_1a3ba279542a5aeddc86d924bbd4a12594)`(float StartTime)` | This should be used only by [NTimeline](#classNTimeline) or serialization.
`public virtual void `[`Stop`](#classNEvent_1a551b1bf590ad30bce1b3f0ce44b0c91a)`()` | This can stop the event and make it expires to its next tick.
`public virtual float `[`GetDelay`](#classNEvent_1afed25f6f7bbd624401803a76d530f18f)`() const` | The delay before this event starts
`public virtual const FString `[`GetUID`](#classNEvent_1a902e03f2e33fd2a39e7b113c0bdc0f5c)`() const` | Retrieve the unique ID generated or given in ctor
`public virtual void `[`SetUID`](#classNEvent_1aebeec7efe7cef04342d2b8e97ade8276)`(FString _UId)` | This should be used only on serialization process
`public virtual const FName `[`GetEventLabel`](#classNEvent_1adefb1f4297e5e4b1342249b666396d9a)`() const` | Getter for Label
`public virtual void `[`SetLocalTime`](#classNEvent_1a09ebad2d5cd8c97ec830b55f1c347c3b)`(float _LocalTime)` | This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classNEvent_1aef073190e18a886364a0ce8f41dda052).
`public virtual void `[`SetDuration`](#classNEvent_1aed6e1d3aed21e84fad370ab2d1734510)`(float _Duration)` | A setter for the duration.
`public virtual void `[`SetDelay`](#classNEvent_1ad6bc835e40776921b793b182af400d69)`(float _Delay)` | A setter for the delay.
`public virtual void `[`SetEventLabel`](#classNEvent_1ab5066c7e0d47be716f3d6b6e45a04298)`(FName _EventLabel)` | A setter for the label.
`public virtual void `[`NotifyAddTime`](#classNEvent_1aef073190e18a886364a0ce8f41dda052)`(float NewTime)` | Increments LocalTime 
`public virtual void `[`Clear`](#classNEvent_1a52fefc3a883f2db7366b96e24d8bfed2)`()` | This should reset all data
`public virtual FNEventDelegate & `[`OnStart`](#classNEvent_1a9e84e286966a430c2fc58d534dd10333)`()` | #### Returns
`protected FName `[`Label`](#classNEvent_1aca50001fe9723034e65be03e06d3f59e) | 
`protected float `[`LocalTime`](#classNEvent_1a79caff85e8c98d0422a1e11dd47e27bb) | 
`protected float `[`StartedAt`](#classNEvent_1ab7eaaeb61f9c50c2882acf67c8c80b40) | 
`protected float `[`Duration`](#classNEvent_1a67fd9c10419486d8c1fda1a9a7b5f971) | 
`protected float `[`Delay`](#classNEvent_1a7bfe0f1f00c6781d84c8398bc0dc780d) | 
`protected FString `[`UId`](#classNEvent_1ac660a2be16fdef80e7859f11a9324324) | 
`protected bool `[`bActivated`](#classNEvent_1a6901924138c98ca09258e4d610904d81) | 

## Members

#### `public FNEventDelegate `[`EventStart`](#classNEvent_1a3363b57e254a8df6717d816804f0ced3) <a id="classNEvent_1a3363b57e254a8df6717d816804f0ced3"></a>

#### `public  `[`NEvent`](#classNEvent_1aac75c1f215cd691c48e87495f2131686)`()` <a id="classNEvent_1aac75c1f215cd691c48e87495f2131686"></a>

Default ctor

#### `public  `[`NEvent`](#classNEvent_1a15c6d7063b5857607cfb0d91446d8241)`(FName _Label,FString _UId)` <a id="classNEvent_1a15c6d7063b5857607cfb0d91446d8241"></a>

Ctor to gives directly a name for this event and an Id (optionnal).

#### `public inline virtual  `[`~NEvent`](#classNEvent_1a179af95c5b72caf083dc7dbbda577244)`()` <a id="classNEvent_1a179af95c5b72caf083dc7dbbda577244"></a>

Default dtor

#### `public virtual bool `[`IsExpired`](#classNEvent_1a035106bed5f526ecf68ae7b067e7beff)`() const` <a id="classNEvent_1a035106bed5f526ecf68ae7b067e7beff"></a>

It indicates if the event expired. It is computed with Duration and LocalTime

#### `public virtual const float `[`GetLocalTime`](#classNEvent_1a74e7fae4f40337ca18e115280d7ebf7f)`() const` <a id="classNEvent_1a74e7fae4f40337ca18e115280d7ebf7f"></a>

Returns the localTime since the events has been attached (- delay) to a timeline

#### `public virtual const float `[`GetStartedAt`](#classNEvent_1a65f998aadcef8a8036f977c5f5226eee)`() const` <a id="classNEvent_1a65f998aadcef8a8036f977c5f5226eee"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public virtual float `[`GetDuration`](#classNEvent_1a27aa249bec02b2132fff7b521731ee81)`() const` <a id="classNEvent_1a27aa249bec02b2132fff7b521731ee81"></a>

The duration this event should live

#### `public virtual void `[`Start`](#classNEvent_1a3ba279542a5aeddc86d924bbd4a12594)`(float StartTime)` <a id="classNEvent_1a3ba279542a5aeddc86d924bbd4a12594"></a>

This should be used only by [NTimeline](#classNTimeline) or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public virtual void `[`Stop`](#classNEvent_1a551b1bf590ad30bce1b3f0ce44b0c91a)`()` <a id="classNEvent_1a551b1bf590ad30bce1b3f0ce44b0c91a"></a>

This can stop the event and make it expires to its next tick.

#### `public virtual float `[`GetDelay`](#classNEvent_1afed25f6f7bbd624401803a76d530f18f)`() const` <a id="classNEvent_1afed25f6f7bbd624401803a76d530f18f"></a>

The delay before this event starts

#### `public virtual const FString `[`GetUID`](#classNEvent_1a902e03f2e33fd2a39e7b113c0bdc0f5c)`() const` <a id="classNEvent_1a902e03f2e33fd2a39e7b113c0bdc0f5c"></a>

Retrieve the unique ID generated or given in ctor

#### `public virtual void `[`SetUID`](#classNEvent_1aebeec7efe7cef04342d2b8e97ade8276)`(FString _UId)` <a id="classNEvent_1aebeec7efe7cef04342d2b8e97ade8276"></a>

This should be used only on serialization process

#### Parameters
* `_UId` - Should be a unique FString, see ctor

#### `public virtual const FName `[`GetEventLabel`](#classNEvent_1adefb1f4297e5e4b1342249b666396d9a)`() const` <a id="classNEvent_1adefb1f4297e5e4b1342249b666396d9a"></a>

Getter for Label

#### `public virtual void `[`SetLocalTime`](#classNEvent_1a09ebad2d5cd8c97ec830b55f1c347c3b)`(float _LocalTime)` <a id="classNEvent_1a09ebad2d5cd8c97ec830b55f1c347c3b"></a>

This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classNEvent_1aef073190e18a886364a0ce8f41dda052).

#### Parameters
* `_LocalTime` - Time in secs

#### `public virtual void `[`SetDuration`](#classNEvent_1aed6e1d3aed21e84fad370ab2d1734510)`(float _Duration)` <a id="classNEvent_1aed6e1d3aed21e84fad370ab2d1734510"></a>

A setter for the duration.

#### Parameters
* `_Duration` - Time in secs

#### `public virtual void `[`SetDelay`](#classNEvent_1ad6bc835e40776921b793b182af400d69)`(float _Delay)` <a id="classNEvent_1ad6bc835e40776921b793b182af400d69"></a>

A setter for the delay.

#### Parameters
* `_Delay` - Time in secs

#### `public virtual void `[`SetEventLabel`](#classNEvent_1ab5066c7e0d47be716f3d6b6e45a04298)`(FName _EventLabel)` <a id="classNEvent_1ab5066c7e0d47be716f3d6b6e45a04298"></a>

A setter for the label.

#### Parameters
* `_EventLabel` - A name to identify easily the event

#### `public virtual void `[`NotifyAddTime`](#classNEvent_1aef073190e18a886364a0ce8f41dda052)`(float NewTime)` <a id="classNEvent_1aef073190e18a886364a0ce8f41dda052"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual void `[`Clear`](#classNEvent_1a52fefc3a883f2db7366b96e24d8bfed2)`()` <a id="classNEvent_1a52fefc3a883f2db7366b96e24d8bfed2"></a>

This should reset all data

#### `public virtual FNEventDelegate & `[`OnStart`](#classNEvent_1a9e84e286966a430c2fc58d534dd10333)`()` <a id="classNEvent_1a9e84e286966a430c2fc58d534dd10333"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

#### `protected FName `[`Label`](#classNEvent_1aca50001fe9723034e65be03e06d3f59e) <a id="classNEvent_1aca50001fe9723034e65be03e06d3f59e"></a>

#### `protected float `[`LocalTime`](#classNEvent_1a79caff85e8c98d0422a1e11dd47e27bb) <a id="classNEvent_1a79caff85e8c98d0422a1e11dd47e27bb"></a>

#### `protected float `[`StartedAt`](#classNEvent_1ab7eaaeb61f9c50c2882acf67c8c80b40) <a id="classNEvent_1ab7eaaeb61f9c50c2882acf67c8c80b40"></a>

#### `protected float `[`Duration`](#classNEvent_1a67fd9c10419486d8c1fda1a9a7b5f971) <a id="classNEvent_1a67fd9c10419486d8c1fda1a9a7b5f971"></a>

#### `protected float `[`Delay`](#classNEvent_1a7bfe0f1f00c6781d84c8398bc0dc780d) <a id="classNEvent_1a7bfe0f1f00c6781d84c8398bc0dc780d"></a>

#### `protected FString `[`UId`](#classNEvent_1ac660a2be16fdef80e7859f11a9324324) <a id="classNEvent_1ac660a2be16fdef80e7859f11a9324324"></a>

#### `protected bool `[`bActivated`](#classNEvent_1a6901924138c98ca09258e4d610904d81) <a id="classNEvent_1a6901924138c98ca09258e4d610904d81"></a>

# class `NEventInterface` <a id="classNEventInterface"></a>

An interface to manage events which can be attached to a timeline.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`IsExpired`](#classNEventInterface_1afd64986f323915c61ae5478764bde9de)`() const` | It indicates if the event expired.
`public const float `[`GetLocalTime`](#classNEventInterface_1a77fbebce451091c6d6dda61a74f090d7)`() const` | Returns the localTime since the events has been attached (- delay) to a timeline
`public const float `[`GetStartedAt`](#classNEventInterface_1a8452276ef3bb1621b5cd3b6eb38e2591)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public float `[`GetDuration`](#classNEventInterface_1abb1b6c05e352b2dd0d8ad07401868851)`() const` | The duration this event should live
`public float `[`GetDelay`](#classNEventInterface_1a05ad20b16c2c9a07c82821ba9424b086)`() const` | The delay before this event starts
`public const FString `[`GetUID`](#classNEventInterface_1ac3e7f334edceaff2915dfc2b2b7be20d)`() const` | Retrieve the unique ID generated or given in ctor
`public void `[`SetUID`](#classNEventInterface_1ab631d00f7a9b39b51a38520c2456e6e8)`(FString _UId)` | This should be used only on serialization process
`public const FName `[`GetEventLabel`](#classNEventInterface_1ade495738a17e98e110742533aa1752be)`() const` | Getter for Label
`public void `[`SetLocalTime`](#classNEventInterface_1ac716c3624cae2ced48465c794cdb1032)`(float _LocalTime)` | This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e).
`public void `[`SetDuration`](#classNEventInterface_1a58ca8d033bf9c8e21f0efb7b003fefd2)`(float _Duration)` | A setter for the duration.
`public void `[`SetDelay`](#classNEventInterface_1afbcb8c5728d4d4c9257e43f78684d8ea)`(float _Delay)` | A setter for the delay.
`public void `[`SetEventLabel`](#classNEventInterface_1ab2088d15c004fa01660411f87950cfa1)`(FName _EventLabel)` | A setter for the label.
`public void `[`Start`](#classNEventInterface_1ab1ab56c02ce79c35c0c3d0acdad4e95b)`(float StartTime)` | This should be used only by [NTimeline](#classNTimeline) or serialization.
`public void `[`Stop`](#classNEventInterface_1a6c83af198e905471876cb7c2e9fc1913)`()` | This can stop the event and make it expires to its next tick.
`public void `[`NotifyAddTime`](#classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e)`(float NewTime)` | Increments LocalTime 
`public void `[`Clear`](#classNEventInterface_1a868685845638769e355b105eeefae196)`()` | This should reset all data
`public FNEventDelegate & `[`OnStart`](#classNEventInterface_1a3dacc71ad39305135b406eec39a41444)`()` | #### Returns

## Members

#### `public bool `[`IsExpired`](#classNEventInterface_1afd64986f323915c61ae5478764bde9de)`() const` <a id="classNEventInterface_1afd64986f323915c61ae5478764bde9de"></a>

It indicates if the event expired.

#### `public const float `[`GetLocalTime`](#classNEventInterface_1a77fbebce451091c6d6dda61a74f090d7)`() const` <a id="classNEventInterface_1a77fbebce451091c6d6dda61a74f090d7"></a>

Returns the localTime since the events has been attached (- delay) to a timeline

#### `public const float `[`GetStartedAt`](#classNEventInterface_1a8452276ef3bb1621b5cd3b6eb38e2591)`() const` <a id="classNEventInterface_1a8452276ef3bb1621b5cd3b6eb38e2591"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public float `[`GetDuration`](#classNEventInterface_1abb1b6c05e352b2dd0d8ad07401868851)`() const` <a id="classNEventInterface_1abb1b6c05e352b2dd0d8ad07401868851"></a>

The duration this event should live

#### `public float `[`GetDelay`](#classNEventInterface_1a05ad20b16c2c9a07c82821ba9424b086)`() const` <a id="classNEventInterface_1a05ad20b16c2c9a07c82821ba9424b086"></a>

The delay before this event starts

#### `public const FString `[`GetUID`](#classNEventInterface_1ac3e7f334edceaff2915dfc2b2b7be20d)`() const` <a id="classNEventInterface_1ac3e7f334edceaff2915dfc2b2b7be20d"></a>

Retrieve the unique ID generated or given in ctor

#### `public void `[`SetUID`](#classNEventInterface_1ab631d00f7a9b39b51a38520c2456e6e8)`(FString _UId)` <a id="classNEventInterface_1ab631d00f7a9b39b51a38520c2456e6e8"></a>

This should be used only on serialization process

#### Parameters
* `_UId` - Should be a unique FString, see ctor

#### `public const FName `[`GetEventLabel`](#classNEventInterface_1ade495738a17e98e110742533aa1752be)`() const` <a id="classNEventInterface_1ade495738a17e98e110742533aa1752be"></a>

Getter for Label

#### `public void `[`SetLocalTime`](#classNEventInterface_1ac716c3624cae2ced48465c794cdb1032)`(float _LocalTime)` <a id="classNEventInterface_1ac716c3624cae2ced48465c794cdb1032"></a>

This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e).

#### Parameters
* `_LocalTime` - Time in secs

#### `public void `[`SetDuration`](#classNEventInterface_1a58ca8d033bf9c8e21f0efb7b003fefd2)`(float _Duration)` <a id="classNEventInterface_1a58ca8d033bf9c8e21f0efb7b003fefd2"></a>

A setter for the duration.

#### Parameters
* `_Duration` - Time in secs

#### `public void `[`SetDelay`](#classNEventInterface_1afbcb8c5728d4d4c9257e43f78684d8ea)`(float _Delay)` <a id="classNEventInterface_1afbcb8c5728d4d4c9257e43f78684d8ea"></a>

A setter for the delay.

#### Parameters
* `_Delay` - Time in secs

#### `public void `[`SetEventLabel`](#classNEventInterface_1ab2088d15c004fa01660411f87950cfa1)`(FName _EventLabel)` <a id="classNEventInterface_1ab2088d15c004fa01660411f87950cfa1"></a>

A setter for the label.

#### Parameters
* `_EventLabel` - A name to identify easily the event

#### `public void `[`Start`](#classNEventInterface_1ab1ab56c02ce79c35c0c3d0acdad4e95b)`(float StartTime)` <a id="classNEventInterface_1ab1ab56c02ce79c35c0c3d0acdad4e95b"></a>

This should be used only by [NTimeline](#classNTimeline) or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public void `[`Stop`](#classNEventInterface_1a6c83af198e905471876cb7c2e9fc1913)`()` <a id="classNEventInterface_1a6c83af198e905471876cb7c2e9fc1913"></a>

This can stop the event and make it expires to its next tick.

#### `public void `[`NotifyAddTime`](#classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e)`(float NewTime)` <a id="classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public void `[`Clear`](#classNEventInterface_1a868685845638769e355b105eeefae196)`()` <a id="classNEventInterface_1a868685845638769e355b105eeefae196"></a>

This should reset all data

#### `public FNEventDelegate & `[`OnStart`](#classNEventInterface_1a3dacc71ad39305135b406eec39a41444)`()` <a id="classNEventInterface_1a3dacc71ad39305135b406eec39a41444"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

# class `NTimeline` <a id="classNTimeline"></a>

```
class NTimeline
  : public NTimelineInterface
```  

**See also**: [NTimelineInterface](#classNTimelineInterface)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FNTimelineEventDelegate `[`EventExpired`](#classNTimeline_1a721aa7e672e1bf842cdfb2f9a64f01df) | **See also**: [OnExpired()](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)
`public  `[`NTimeline`](#classNTimeline_1a0b11124c2e2f3776869bf5231c3a8f42)`(`[`NTimelineManager`](#classNTimelineManager)` * TimerManager,FName _Label)` | A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.
`public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` | Empty events array
`public virtual FNTimelineEventDelegate & `[`OnEventExpired`](#classNTimeline_1ae3c7ff866ac29130894fb2e7ef3c3cc5)`()` | #### Returns
`public virtual bool `[`Attached`](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | It creates a FEventTuple and calls [BeforeOnAttached()](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b) to checks if it can be attached and [AfterOnAttached()](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b) for any custom usages
`public virtual void `[`Attached`](#classNTimeline_1a3d090a5488bc0821a51c470613b1a370)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | Same as [Attached(TSharedPtr<NEventInterface> Event)](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1) but for a collection of objects.
`public virtual void `[`SetTickInterval`](#classNTimeline_1a526040e6d6c3d70bf301ad9834b421f1)`(float _TickInterval)` | This should be called only by its friend [NTimelineManager](#classNTimelineManager) or a decorator to maintain consistency with its manager. Defined the tick interval for this timeline
`public virtual void `[`SetCurrentTime`](#classNTimeline_1af956ff99638d833707bd62f61e07983c)`(float _CurrentTime)` | Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247)
`public virtual float `[`GetCurrentTime`](#classNTimeline_1a717c02d02d052bec103fb8f11d12db33)`() const` | Retrieve the current time since this timeline exists and play
`public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` | Returns the FEventTuple collection
`public virtual void `[`SetLabel`](#classNTimeline_1aa7979e247830ee13a84ef539a811f854)`(FName _Label)` | Give a name to this timeline
`public virtual FName `[`GetLabel`](#classNTimeline_1a1d3eeddcb7b658d7c86f84eaa61d9069)`() const` | Return the actual name
`public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5)` Tuple)` | This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1) methods to set data during runtime.
`public virtual void `[`Clear`](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`NotifyTick`](#classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.
`protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) | The name of this timeline
`protected float `[`TickInterval`](#classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421) | Tick interval, should be set by its manager
`protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) | It is computed internally in the [NotifyTick()](#classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) return.
`protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` | This to allow inherited adapters to have a default constructor
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` | In case of specialisation needs to avoid the attach process in some cases
`protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` | If needed to make some stats, analytics, trigger error,...
`protected virtual const float `[`GetTickInterval`](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417)`() const` | This is the value required by a timer manager to know the tick frequency for this timeline (given by [NTimelineManager](#classNTimelineManager)). The NotifyTick use this method to add time on CurrentTime at each call.
`protected virtual void `[`OnExpired`](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` | Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference
`typedef `[`FEventTuple`](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5) | An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time 6: UId

## Members

#### `public FNTimelineEventDelegate `[`EventExpired`](#classNTimeline_1a721aa7e672e1bf842cdfb2f9a64f01df) <a id="classNTimeline_1a721aa7e672e1bf842cdfb2f9a64f01df"></a>

**See also**: [OnExpired()](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)

#### `public  `[`NTimeline`](#classNTimeline_1a0b11124c2e2f3776869bf5231c3a8f42)`(`[`NTimelineManager`](#classNTimelineManager)` * TimerManager,FName _Label)` <a id="classNTimeline_1a0b11124c2e2f3776869bf5231c3a8f42"></a>

A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.

#### Parameters
* `TimerManager` - Timer which manage all time behavior (tick, pause, stop, play,...) 

* `_Label` - (optionnal) The name of this timeline. If not provided it creates a name with a static incremented value.

#### `public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` <a id="classNTimeline_1adffcefb7fc7f2768021994f8730eb356"></a>

Empty events array

#### `public virtual FNTimelineEventDelegate & `[`OnEventExpired`](#classNTimeline_1ae3c7ff866ac29130894fb2e7ef3c3cc5)`()` <a id="classNTimeline_1ae3c7ff866ac29130894fb2e7ef3c3cc5"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

#### `public virtual bool `[`Attached`](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1"></a>

It creates a FEventTuple and calls [BeforeOnAttached()](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b) to checks if it can be attached and [AfterOnAttached()](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b) for any custom usages

#### Parameters
* `Event` - The event you want to put in the timeline stream

#### `public virtual void `[`Attached`](#classNTimeline_1a3d090a5488bc0821a51c470613b1a370)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classNTimeline_1a3d090a5488bc0821a51c470613b1a370"></a>

Same as [Attached(TSharedPtr<NEventInterface> Event)](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1) but for a collection of objects.

**See also**: [NTimeline::Attached(TSharedPtr<NEventInterface> Event)](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1)

#### `public virtual void `[`SetTickInterval`](#classNTimeline_1a526040e6d6c3d70bf301ad9834b421f1)`(float _TickInterval)` <a id="classNTimeline_1a526040e6d6c3d70bf301ad9834b421f1"></a>

This should be called only by its friend [NTimelineManager](#classNTimelineManager) or a decorator to maintain consistency with its manager. Defined the tick interval for this timeline

#### Parameters
* `_TickInterval` - Time in secs

#### `public virtual void `[`SetCurrentTime`](#classNTimeline_1af956ff99638d833707bd62f61e07983c)`(float _CurrentTime)` <a id="classNTimeline_1af956ff99638d833707bd62f61e07983c"></a>

Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247)

#### Parameters
* `_CurrentTime` - Time in secs

#### `public virtual float `[`GetCurrentTime`](#classNTimeline_1a717c02d02d052bec103fb8f11d12db33)`() const` <a id="classNTimeline_1a717c02d02d052bec103fb8f11d12db33"></a>

Retrieve the current time since this timeline exists and play

#### `public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` <a id="classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6"></a>

Returns the FEventTuple collection

#### `public virtual void `[`SetLabel`](#classNTimeline_1aa7979e247830ee13a84ef539a811f854)`(FName _Label)` <a id="classNTimeline_1aa7979e247830ee13a84ef539a811f854"></a>

Give a name to this timeline

#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classNTimeline_1a1d3eeddcb7b658d7c86f84eaa61d9069)`() const` <a id="classNTimeline_1a1d3eeddcb7b658d7c86f84eaa61d9069"></a>

Return the actual name

#### `public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5)` Tuple)` <a id="classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec"></a>

This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a06f9e912eb10269c9a1852fafac2dca1) methods to set data during runtime.

#### Parameters
* `Tuple` - Data which will be added to the Events TArray

#### `public virtual void `[`Clear`](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)`()` <a id="classNTimeline_1a54129c39bf3c4233007f203c5ae16728"></a>

This completely reset every events. It should be used with caution.

#### `public virtual void `[`NotifyTick`](#classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247)`()` <a id="classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247"></a>

This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.

#### `protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) <a id="classNTimeline_1a008f3afba683e14f05887e4df108c260"></a>

The name of this timeline

#### `protected float `[`TickInterval`](#classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421) <a id="classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421"></a>

Tick interval, should be set by its manager

#### `protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) <a id="classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740"></a>

It is computed internally in the [NotifyTick()](#classNTimeline_1ad35ffbc8dbe2252d9c7f39140fd08247) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) return.

#### `protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` <a id="classNTimeline_1a6143741ff06add02f22ee82e5f1b6147"></a>

This to allow inherited adapters to have a default constructor

#### `protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` <a id="classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b"></a>

In case of specialisation needs to avoid the attach process in some cases

#### `protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` <a id="classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b"></a>

If needed to make some stats, analytics, trigger error,...

#### `protected virtual const float `[`GetTickInterval`](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417)`() const` <a id="classNTimeline_1a7c0dc7947a2f271fe68020d322fca417"></a>

This is the value required by a timer manager to know the tick frequency for this timeline (given by [NTimelineManager](#classNTimelineManager)). The NotifyTick use this method to add time on CurrentTime at each call.

#### `protected virtual void `[`OnExpired`](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78"></a>

Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference

#### `typedef `[`FEventTuple`](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5) <a id="classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5"></a>

An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time 6: UId

# class `NTimelineInterface` <a id="classNTimelineInterface"></a>

Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManager](#classNTimelineManager) class is dedicated to handle it.

**See also**: ./TimelineManager.h

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`Attached`](#classNTimelineInterface_1ae3db05abf80375c1e458958331fea033)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | Attached an event to this timeline
`public void `[`Attached`](#classNTimelineInterface_1a3abcd5e2d2218a7269f6864aa8a7cb08)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | Attached a collection of events to this timeline
`public void `[`SetTickInterval`](#classNTimelineInterface_1ad894c4e8cacecfe46c861afbb4579f0a)`(float _TickInterval)` | Defined the tick interval for this timeline
`public void `[`SetCurrentTime`](#classNTimelineInterface_1ae3bcfd2792a53b0e254b32b857b9d404)`(float _CurrentTime)` | Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3)
`public float `[`GetCurrentTime`](#classNTimelineInterface_1a9a821c703f10f5b2865bd7c5302c8661)`() const` | Retrieve the current time since this timeline exists and play
`public void `[`SetLabel`](#classNTimelineInterface_1a88b958f47721634befa5a5118fa87a02)`(FName _Label)` | Give a name to this timeline
`public FName `[`GetLabel`](#classNTimelineInterface_1a78a95ae2a1104409553fe3ed30a56e10)`() const` | Return the actual name
`public void `[`Clear`](#classNTimelineInterface_1a5de152382b1e669f1a994e910c406643)`()` | Reset default data
`public void `[`NotifyTick`](#classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3)`()` | This manages to notify every events saved in this timeline with the new time added.
`public FNTimelineEventDelegate & `[`OnEventExpired`](#classNTimelineInterface_1a5ffe42c9a7d91381abdb0de4385523e3)`()` | #### Returns

## Members

#### `public bool `[`Attached`](#classNTimelineInterface_1ae3db05abf80375c1e458958331fea033)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classNTimelineInterface_1ae3db05abf80375c1e458958331fea033"></a>

Attached an event to this timeline

#### `public void `[`Attached`](#classNTimelineInterface_1a3abcd5e2d2218a7269f6864aa8a7cb08)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classNTimelineInterface_1a3abcd5e2d2218a7269f6864aa8a7cb08"></a>

Attached a collection of events to this timeline

#### `public void `[`SetTickInterval`](#classNTimelineInterface_1ad894c4e8cacecfe46c861afbb4579f0a)`(float _TickInterval)` <a id="classNTimelineInterface_1ad894c4e8cacecfe46c861afbb4579f0a"></a>

Defined the tick interval for this timeline

#### Parameters
* `_TickInterval` - Time in secs

#### `public void `[`SetCurrentTime`](#classNTimelineInterface_1ae3bcfd2792a53b0e254b32b857b9d404)`(float _CurrentTime)` <a id="classNTimelineInterface_1ae3bcfd2792a53b0e254b32b857b9d404"></a>

Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3)

#### Parameters
* `_CurrentTime` - Time in secs

#### `public float `[`GetCurrentTime`](#classNTimelineInterface_1a9a821c703f10f5b2865bd7c5302c8661)`() const` <a id="classNTimelineInterface_1a9a821c703f10f5b2865bd7c5302c8661"></a>

Retrieve the current time since this timeline exists and play

#### `public void `[`SetLabel`](#classNTimelineInterface_1a88b958f47721634befa5a5118fa87a02)`(FName _Label)` <a id="classNTimelineInterface_1a88b958f47721634befa5a5118fa87a02"></a>

Give a name to this timeline

#### Parameters
* `_Label` - The name

#### `public FName `[`GetLabel`](#classNTimelineInterface_1a78a95ae2a1104409553fe3ed30a56e10)`() const` <a id="classNTimelineInterface_1a78a95ae2a1104409553fe3ed30a56e10"></a>

Return the actual name

#### `public void `[`Clear`](#classNTimelineInterface_1a5de152382b1e669f1a994e910c406643)`()` <a id="classNTimelineInterface_1a5de152382b1e669f1a994e910c406643"></a>

Reset default data

#### `public void `[`NotifyTick`](#classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3)`()` <a id="classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3"></a>

This manages to notify every events saved in this timeline with the new time added.

#### `public FNTimelineEventDelegate & `[`OnEventExpired`](#classNTimelineInterface_1a5ffe42c9a7d91381abdb0de4385523e3)`()` <a id="classNTimelineInterface_1a5ffe42c9a7d91381abdb0de4385523e3"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

# class `NTimelineManager` <a id="classNTimelineManager"></a>

This class is the client for the [NTimelineInterface](#classNTimelineInterface) object. Its goal is to decoupled client interface with timeline management.

* [NTimelineInterface](#classNTimelineInterface) manages time computation, notify events accordingly and save all states

* [NTimelineManager](#classNTimelineManager) manages client controls.

**See also**: [NTimelineInterface](#classNTimelineInterface)

**See also**: [NTimeline](#classNTimeline)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NTimelineManager`](#classNTimelineManager_1a1b0c6dc4d6e281e5eb4d55f3ed88028c)`()` | Calls the [Init()](#classNTimelineManager_1abf6e226915c1234321491137ed3483dc) method.
`public virtual  `[`~NTimelineManager`](#classNTimelineManager_1a4acef51e20d351fc1061007f764508c7)`()` | Calls [Clear()](#classNTimelineManager_1a337d18b7bd76ecefe59441f29f2553ab) and release Timeline TSharedPtr
`public virtual void `[`Init`](#classNTimelineManager_1abf6e226915c1234321491137ed3483dc)`(float _TickInterval,FName _Label)` | Instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Pause`](#classNTimelineManager_1a8cb9ad0eb1b12858447cd044b9d409a4)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classNTimelineManager_1ade9c8d1c0cef24f017bf2ca718f23ffe)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classNTimelineManager_1ad62ca7c3db61f67d85673f92f72e16bd)`()` | This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0
`public virtual void `[`TimerTick`](#classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0)`()` | This checks the actual play state (ENTimelineTimerState) and tick the [NTimelineInterface](#classNTimelineInterface) accordingly.
`public `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManager_1a629aa6973b822f9184051626a75922e8)`() const` | Get the actual state.
`public float `[`GetTickInterval`](#classNTimelineManager_1a184b3479c2adfd6304b1106fc0a62c62)`() const` | Get the tick interval which a timermanager should use to process
`public virtual void `[`SetTickInterval`](#classNTimelineManager_1abd98f6183114297171f49ec48b7624b1)`(float _TickInterval)` | Defined the desired ticking interval
`public TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`GetTimeline`](#classNTimelineManager_1aded3b7d83a0789000027b3137439ab3a)`() const` | Get the coupled [NTimelineInterface](#classNTimelineInterface)
`protected float `[`TickInterval`](#classNTimelineManager_1a7cfb02706580bc6947974d896a2458bc) | The interval retrieved from the timeline.
`protected `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManager_1a061049bcb7424fcd2332081cb78b6e9e) | The actual state
`protected TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`Timeline`](#classNTimelineManager_1af6a5d2b1c6c7acdfb6510acf53ed042e) | The coupled timeline
`protected virtual void `[`Clear`](#classNTimelineManager_1a337d18b7bd76ecefe59441f29f2553ab)`()` | Calls [NTimeline::Clear()](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)
`protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManager_1a1f4e4f731583060d7d0f5750795b809a)`()` | This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.
`protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManager_1a4cfa006fae1385cce28cf61b674abe0d)`()` | This method is call immediately before ticking
`protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManager_1a499e7d4d685b91d3697bac9953e88268)`()` | This method is call immediately after ticking

## Members

#### `public  `[`NTimelineManager`](#classNTimelineManager_1a1b0c6dc4d6e281e5eb4d55f3ed88028c)`()` <a id="classNTimelineManager_1a1b0c6dc4d6e281e5eb4d55f3ed88028c"></a>

Calls the [Init()](#classNTimelineManager_1abf6e226915c1234321491137ed3483dc) method.

#### `public virtual  `[`~NTimelineManager`](#classNTimelineManager_1a4acef51e20d351fc1061007f764508c7)`()` <a id="classNTimelineManager_1a4acef51e20d351fc1061007f764508c7"></a>

Calls [Clear()](#classNTimelineManager_1a337d18b7bd76ecefe59441f29f2553ab) and release Timeline TSharedPtr

#### `public virtual void `[`Init`](#classNTimelineManager_1abf6e226915c1234321491137ed3483dc)`(float _TickInterval,FName _Label)` <a id="classNTimelineManager_1abf6e226915c1234321491137ed3483dc"></a>

Instanciate the embeded [NTimeline](#classNTimeline)

#### Parameters
* `_TickInterval` - Interval time between tick in sec 

* `_Label` - Name of the Timeline.

#### `public virtual void `[`Pause`](#classNTimelineManager_1a8cb9ad0eb1b12858447cd044b9d409a4)`()` <a id="classNTimelineManager_1a8cb9ad0eb1b12858447cd044b9d409a4"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classNTimelineManager_1ade9c8d1c0cef24f017bf2ca718f23ffe)`()` <a id="classNTimelineManager_1ade9c8d1c0cef24f017bf2ca718f23ffe"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classNTimelineManager_1ad62ca7c3db61f67d85673f92f72e16bd)`()` <a id="classNTimelineManager_1ad62ca7c3db61f67d85673f92f72e16bd"></a>

This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0

#### `public virtual void `[`TimerTick`](#classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0)`()` <a id="classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0"></a>

This checks the actual play state (ENTimelineTimerState) and tick the [NTimelineInterface](#classNTimelineInterface) accordingly.

#### `public `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classNTimelineManager_1a629aa6973b822f9184051626a75922e8)`() const` <a id="classNTimelineManager_1a629aa6973b822f9184051626a75922e8"></a>

Get the actual state.

#### `public float `[`GetTickInterval`](#classNTimelineManager_1a184b3479c2adfd6304b1106fc0a62c62)`() const` <a id="classNTimelineManager_1a184b3479c2adfd6304b1106fc0a62c62"></a>

Get the tick interval which a timermanager should use to process

#### `public virtual void `[`SetTickInterval`](#classNTimelineManager_1abd98f6183114297171f49ec48b7624b1)`(float _TickInterval)` <a id="classNTimelineManager_1abd98f6183114297171f49ec48b7624b1"></a>

Defined the desired ticking interval

#### `public TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`GetTimeline`](#classNTimelineManager_1aded3b7d83a0789000027b3137439ab3a)`() const` <a id="classNTimelineManager_1aded3b7d83a0789000027b3137439ab3a"></a>

Get the coupled [NTimelineInterface](#classNTimelineInterface)

#### `protected float `[`TickInterval`](#classNTimelineManager_1a7cfb02706580bc6947974d896a2458bc) <a id="classNTimelineManager_1a7cfb02706580bc6947974d896a2458bc"></a>

The interval retrieved from the timeline.

#### `protected `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classNTimelineManager_1a061049bcb7424fcd2332081cb78b6e9e) <a id="classNTimelineManager_1a061049bcb7424fcd2332081cb78b6e9e"></a>

The actual state

#### `protected TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`Timeline`](#classNTimelineManager_1af6a5d2b1c6c7acdfb6510acf53ed042e) <a id="classNTimelineManager_1af6a5d2b1c6c7acdfb6510acf53ed042e"></a>

The coupled timeline

#### `protected virtual void `[`Clear`](#classNTimelineManager_1a337d18b7bd76ecefe59441f29f2553ab)`()` <a id="classNTimelineManager_1a337d18b7bd76ecefe59441f29f2553ab"></a>

Calls [NTimeline::Clear()](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)

#### `protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManager_1a1f4e4f731583060d7d0f5750795b809a)`()` <a id="classNTimelineManager_1a1f4e4f731583060d7d0f5750795b809a"></a>

This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.

#### `protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManager_1a4cfa006fae1385cce28cf61b674abe0d)`()` <a id="classNTimelineManager_1a4cfa006fae1385cce28cf61b674abe0d"></a>

This method is call immediately before ticking

#### `protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManager_1a499e7d4d685b91d3697bac9953e88268)`()` <a id="classNTimelineManager_1a499e7d4d685b91d3697bac9953e88268"></a>

This method is call immediately after ticking

# class `NUnrealEventProxy` <a id="classNUnrealEventProxy"></a>

```
class NUnrealEventProxy
  : public NEventInterface
```  

This class is just a pass-through to allows an [UNEventDecorator](#classUNEventDecorator) (a derived UObject) to be passed on the core system using TSharedPtr.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNEventDecorator`](#classUNEventDecorator)` & `[`Event`](#classNUnrealEventProxy_1ae30cbb7423f945c8078b83cb47709532) | 
`public inline  `[`NUnrealEventProxy`](#classNUnrealEventProxy_1a7d30a9a2460faa07dda4237f18cbaee5)`(`[`UNEventDecorator`](#classUNEventDecorator)` & _Event)` | 
`public virtual bool `[`IsExpired`](#classNUnrealEventProxy_1a2ab770fdaf8a2e66adf4128be813d157)`() const` | It indicates if the event expired.
`public virtual const float `[`GetLocalTime`](#classNUnrealEventProxy_1aab01b11713feaadebf3b841254626e43)`() const` | Returns the localTime since the events has been attached (- delay) to a timeline
`public virtual const float `[`GetStartedAt`](#classNUnrealEventProxy_1ada79157425ac4d78d3bae4823357ce89)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public virtual float `[`GetDuration`](#classNUnrealEventProxy_1a7556392cdbdaf35ed0b09c9910b3a187)`() const` | The duration this event should live
`public virtual void `[`Start`](#classNUnrealEventProxy_1a03e4aa3c7b41f9d40d028215b25aa04d)`(float StartTime)` | This should be used only by [NTimeline](#classNTimeline) or serialization.
`public virtual void `[`Stop`](#classNUnrealEventProxy_1a8439075a6c628d1a6bc2ea322fddb5e3)`()` | This can stop the event and make it expires to its next tick.
`public virtual void `[`NotifyAddTime`](#classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345)`(float NewTime)` | Increments LocalTime 
`public virtual float `[`GetDelay`](#classNUnrealEventProxy_1a2677f3f63bc2282827a226d7c7a840ab)`() const` | The delay before this event starts
`public virtual const FName `[`GetEventLabel`](#classNUnrealEventProxy_1ac23e8b1279065e45016d8f5d6040a24b)`() const` | Getter for Label
`public virtual const FString `[`GetUID`](#classNUnrealEventProxy_1a6a405f4dfcc52bcb41b46c127214083a)`() const` | Retrieve the unique ID generated or given in ctor
`public virtual void `[`SetUID`](#classNUnrealEventProxy_1a6633160494c430bb3d9ef357c4945f9a)`(FString _UId)` | This should be used only on serialization process
`public virtual void `[`SetLocalTime`](#classNUnrealEventProxy_1a4592b1545ddc54090813287e78bf4259)`(float _LocalTime)` | This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345).
`public virtual void `[`SetDuration`](#classNUnrealEventProxy_1a2bf362638bc5bc1384e5d0c97a8ee360)`(float _Duration)` | A setter for the duration.
`public virtual void `[`SetDelay`](#classNUnrealEventProxy_1ab9f93904bc977d1ada3b5d4669857b85)`(float _Delay)` | A setter for the delay.
`public virtual void `[`SetEventLabel`](#classNUnrealEventProxy_1abce884ce83319b3d6c323e363fe0b7cd)`(FName _EventLabel)` | A setter for the label.
`public virtual void `[`Clear`](#classNUnrealEventProxy_1a9fa63a487060c3003355552552cb600a)`()` | This should reset all data
`public virtual FNEventDelegate & `[`OnStart`](#classNUnrealEventProxy_1abd5e15acc3ab330dcccc5b1021a0661a)`()` | #### Returns
`public `[`UNEventDecorator`](#classUNEventDecorator)` & `[`GetUnrealObject`](#classNUnrealEventProxy_1a195f7a860aceba0ae76c7866901b7e95)`()` | 

## Members

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` & `[`Event`](#classNUnrealEventProxy_1ae30cbb7423f945c8078b83cb47709532) <a id="classNUnrealEventProxy_1ae30cbb7423f945c8078b83cb47709532"></a>

#### `public inline  `[`NUnrealEventProxy`](#classNUnrealEventProxy_1a7d30a9a2460faa07dda4237f18cbaee5)`(`[`UNEventDecorator`](#classUNEventDecorator)` & _Event)` <a id="classNUnrealEventProxy_1a7d30a9a2460faa07dda4237f18cbaee5"></a>

#### `public virtual bool `[`IsExpired`](#classNUnrealEventProxy_1a2ab770fdaf8a2e66adf4128be813d157)`() const` <a id="classNUnrealEventProxy_1a2ab770fdaf8a2e66adf4128be813d157"></a>

It indicates if the event expired.

#### `public virtual const float `[`GetLocalTime`](#classNUnrealEventProxy_1aab01b11713feaadebf3b841254626e43)`() const` <a id="classNUnrealEventProxy_1aab01b11713feaadebf3b841254626e43"></a>

Returns the localTime since the events has been attached (- delay) to a timeline

#### `public virtual const float `[`GetStartedAt`](#classNUnrealEventProxy_1ada79157425ac4d78d3bae4823357ce89)`() const` <a id="classNUnrealEventProxy_1ada79157425ac4d78d3bae4823357ce89"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public virtual float `[`GetDuration`](#classNUnrealEventProxy_1a7556392cdbdaf35ed0b09c9910b3a187)`() const` <a id="classNUnrealEventProxy_1a7556392cdbdaf35ed0b09c9910b3a187"></a>

The duration this event should live

#### `public virtual void `[`Start`](#classNUnrealEventProxy_1a03e4aa3c7b41f9d40d028215b25aa04d)`(float StartTime)` <a id="classNUnrealEventProxy_1a03e4aa3c7b41f9d40d028215b25aa04d"></a>

This should be used only by [NTimeline](#classNTimeline) or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public virtual void `[`Stop`](#classNUnrealEventProxy_1a8439075a6c628d1a6bc2ea322fddb5e3)`()` <a id="classNUnrealEventProxy_1a8439075a6c628d1a6bc2ea322fddb5e3"></a>

This can stop the event and make it expires to its next tick.

#### `public virtual void `[`NotifyAddTime`](#classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345)`(float NewTime)` <a id="classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual float `[`GetDelay`](#classNUnrealEventProxy_1a2677f3f63bc2282827a226d7c7a840ab)`() const` <a id="classNUnrealEventProxy_1a2677f3f63bc2282827a226d7c7a840ab"></a>

The delay before this event starts

#### `public virtual const FName `[`GetEventLabel`](#classNUnrealEventProxy_1ac23e8b1279065e45016d8f5d6040a24b)`() const` <a id="classNUnrealEventProxy_1ac23e8b1279065e45016d8f5d6040a24b"></a>

Getter for Label

#### `public virtual const FString `[`GetUID`](#classNUnrealEventProxy_1a6a405f4dfcc52bcb41b46c127214083a)`() const` <a id="classNUnrealEventProxy_1a6a405f4dfcc52bcb41b46c127214083a"></a>

Retrieve the unique ID generated or given in ctor

#### `public virtual void `[`SetUID`](#classNUnrealEventProxy_1a6633160494c430bb3d9ef357c4945f9a)`(FString _UId)` <a id="classNUnrealEventProxy_1a6633160494c430bb3d9ef357c4945f9a"></a>

This should be used only on serialization process

#### Parameters
* `_UId` - Should be a unique FString, see ctor

#### `public virtual void `[`SetLocalTime`](#classNUnrealEventProxy_1a4592b1545ddc54090813287e78bf4259)`(float _LocalTime)` <a id="classNUnrealEventProxy_1a4592b1545ddc54090813287e78bf4259"></a>

This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345).

#### Parameters
* `_LocalTime` - Time in secs

#### `public virtual void `[`SetDuration`](#classNUnrealEventProxy_1a2bf362638bc5bc1384e5d0c97a8ee360)`(float _Duration)` <a id="classNUnrealEventProxy_1a2bf362638bc5bc1384e5d0c97a8ee360"></a>

A setter for the duration.

#### Parameters
* `_Duration` - Time in secs

#### `public virtual void `[`SetDelay`](#classNUnrealEventProxy_1ab9f93904bc977d1ada3b5d4669857b85)`(float _Delay)` <a id="classNUnrealEventProxy_1ab9f93904bc977d1ada3b5d4669857b85"></a>

A setter for the delay.

#### Parameters
* `_Delay` - Time in secs

#### `public virtual void `[`SetEventLabel`](#classNUnrealEventProxy_1abce884ce83319b3d6c323e363fe0b7cd)`(FName _EventLabel)` <a id="classNUnrealEventProxy_1abce884ce83319b3d6c323e363fe0b7cd"></a>

A setter for the label.

#### Parameters
* `_EventLabel` - A name to identify easily the event

#### `public virtual void `[`Clear`](#classNUnrealEventProxy_1a9fa63a487060c3003355552552cb600a)`()` <a id="classNUnrealEventProxy_1a9fa63a487060c3003355552552cb600a"></a>

This should reset all data

#### `public virtual FNEventDelegate & `[`OnStart`](#classNUnrealEventProxy_1abd5e15acc3ab330dcccc5b1021a0661a)`()` <a id="classNUnrealEventProxy_1abd5e15acc3ab330dcccc5b1021a0661a"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` & `[`GetUnrealObject`](#classNUnrealEventProxy_1a195f7a860aceba0ae76c7866901b7e95)`()` <a id="classNUnrealEventProxy_1a195f7a860aceba0ae76c7866901b7e95"></a>

# class `NUnrealTimelineProxy` <a id="classNUnrealTimelineProxy"></a>

```
class NUnrealTimelineProxy
  : public NTimelineInterface
```  

This class is a pass-through to allows an [NUnrealTimelineProxy](#classNUnrealTimelineProxy) (a derived UObject) to be passed on the core system using TSharedPtr, and it manages [NUnrealEventProxy](#classNUnrealEventProxy) attachment .

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNTimelineDecorator`](#classUNTimelineDecorator)` & `[`Timeline`](#classNUnrealTimelineProxy_1a40f55d7cc326c9e6b663f6bbb1648ced) | 
`public inline  `[`NUnrealTimelineProxy`](#classNUnrealTimelineProxy_1a7e885e1d821260b1da07b38ea5c2410b)`(`[`UNTimelineDecorator`](#classUNTimelineDecorator)` & _Timeline)` | 
`public virtual bool `[`Attached`](#classNUnrealTimelineProxy_1a5f87631c37cdcba6b8bdc359b5f1a6b5)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | Attached an event to this timeline
`public virtual void `[`Attached`](#classNUnrealTimelineProxy_1aedddc222f0aef97ce80df43d295c67a7)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | Attached a collection of events to this timeline
`public virtual void `[`SetTickInterval`](#classNUnrealTimelineProxy_1a34e36b80dbcdd43682447670c07df295)`(float _TickInterval)` | Defined the tick interval for this timeline
`public virtual void `[`SetCurrentTime`](#classNUnrealTimelineProxy_1ab2659e648dc0c4411bb3a4a389081ed3)`(float _CurrentTime)` | Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be)
`public virtual float `[`GetCurrentTime`](#classNUnrealTimelineProxy_1ad9f56c6070ccaa4958dd5ea3289dc210)`() const` | Retrieve the current time since this timeline exists and play
`public virtual void `[`SetLabel`](#classNUnrealTimelineProxy_1adf1c8d680d112638c45b0f3476ca19c1)`(FName _Label)` | Give a name to this timeline
`public virtual FName `[`GetLabel`](#classNUnrealTimelineProxy_1ae525709779b518b085a3dd77a0317617)`() const` | Return the actual name
`public virtual void `[`Clear`](#classNUnrealTimelineProxy_1a06aaedc689ba6d694900e7ee619b06be)`()` | Reset default data
`public virtual void `[`NotifyTick`](#classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be)`()` | This manages to notify every events saved in this timeline with the new time added.
`public virtual FNTimelineEventDelegate & `[`OnEventExpired`](#classNUnrealTimelineProxy_1a921d3f3649a0ac74c50d964de7d14d13)`()` | #### Returns
`public virtual `[`UNTimelineDecorator`](#classUNTimelineDecorator)` * `[`GetUnrealObject`](#classNUnrealTimelineProxy_1a0bc45d31e166453f65f8dc13ed206b42)`()` | 

## Members

#### `public `[`UNTimelineDecorator`](#classUNTimelineDecorator)` & `[`Timeline`](#classNUnrealTimelineProxy_1a40f55d7cc326c9e6b663f6bbb1648ced) <a id="classNUnrealTimelineProxy_1a40f55d7cc326c9e6b663f6bbb1648ced"></a>

#### `public inline  `[`NUnrealTimelineProxy`](#classNUnrealTimelineProxy_1a7e885e1d821260b1da07b38ea5c2410b)`(`[`UNTimelineDecorator`](#classUNTimelineDecorator)` & _Timeline)` <a id="classNUnrealTimelineProxy_1a7e885e1d821260b1da07b38ea5c2410b"></a>

#### `public virtual bool `[`Attached`](#classNUnrealTimelineProxy_1a5f87631c37cdcba6b8bdc359b5f1a6b5)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classNUnrealTimelineProxy_1a5f87631c37cdcba6b8bdc359b5f1a6b5"></a>

Attached an event to this timeline

#### `public virtual void `[`Attached`](#classNUnrealTimelineProxy_1aedddc222f0aef97ce80df43d295c67a7)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classNUnrealTimelineProxy_1aedddc222f0aef97ce80df43d295c67a7"></a>

Attached a collection of events to this timeline

#### `public virtual void `[`SetTickInterval`](#classNUnrealTimelineProxy_1a34e36b80dbcdd43682447670c07df295)`(float _TickInterval)` <a id="classNUnrealTimelineProxy_1a34e36b80dbcdd43682447670c07df295"></a>

Defined the tick interval for this timeline

#### Parameters
* `_TickInterval` - Time in secs

#### `public virtual void `[`SetCurrentTime`](#classNUnrealTimelineProxy_1ab2659e648dc0c4411bb3a4a389081ed3)`(float _CurrentTime)` <a id="classNUnrealTimelineProxy_1ab2659e648dc0c4411bb3a4a389081ed3"></a>

Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be)

#### Parameters
* `_CurrentTime` - Time in secs

#### `public virtual float `[`GetCurrentTime`](#classNUnrealTimelineProxy_1ad9f56c6070ccaa4958dd5ea3289dc210)`() const` <a id="classNUnrealTimelineProxy_1ad9f56c6070ccaa4958dd5ea3289dc210"></a>

Retrieve the current time since this timeline exists and play

#### `public virtual void `[`SetLabel`](#classNUnrealTimelineProxy_1adf1c8d680d112638c45b0f3476ca19c1)`(FName _Label)` <a id="classNUnrealTimelineProxy_1adf1c8d680d112638c45b0f3476ca19c1"></a>

Give a name to this timeline

#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classNUnrealTimelineProxy_1ae525709779b518b085a3dd77a0317617)`() const` <a id="classNUnrealTimelineProxy_1ae525709779b518b085a3dd77a0317617"></a>

Return the actual name

#### `public virtual void `[`Clear`](#classNUnrealTimelineProxy_1a06aaedc689ba6d694900e7ee619b06be)`()` <a id="classNUnrealTimelineProxy_1a06aaedc689ba6d694900e7ee619b06be"></a>

Reset default data

#### `public virtual void `[`NotifyTick`](#classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be)`()` <a id="classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be"></a>

This manages to notify every events saved in this timeline with the new time added.

#### `public virtual FNTimelineEventDelegate & `[`OnEventExpired`](#classNUnrealTimelineProxy_1a921d3f3649a0ac74c50d964de7d14d13)`()` <a id="classNUnrealTimelineProxy_1a921d3f3649a0ac74c50d964de7d14d13"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

#### `public virtual `[`UNTimelineDecorator`](#classUNTimelineDecorator)` * `[`GetUnrealObject`](#classNUnrealTimelineProxy_1a0bc45d31e166453f65f8dc13ed206b42)`()` <a id="classNUnrealTimelineProxy_1a0bc45d31e166453f65f8dc13ed206b42"></a>

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

# class `UNEventDecorator` <a id="classUNEventDecorator"></a>

```
class UNEventDecorator
  : public UObject
  : public NEventInterface
```  

Base abstract class to create [NEventInterface](#classNEventInterface) decorators (Blueprint or c++).

For a simple usage with blueprint: you can derived blueprint base on this. This way the [NEventInterface](#classNEventInterface) instance should only manage timeline behavior.

For a more complex usage in c++: You should derive this and [NEventInterface](#classNEventInterface) too to fit on your needs.

* This class should only manage specifics behaviors related to the engine (serialization, blueprint's specifics functionnalities, etc...)

* [NEventInterface](#classNEventInterface)'s derivation: all your core functionnalities

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNEventDecorator`](#classUNEventDecorator_1a863909d823063f8446d2dcf30fe8174c)`()` | 
`public virtual bool `[`IsExpired`](#classUNEventDecorator_1ae69c1d2dc0bd6bbe4381e0387d96ed1e)`() const` | It indicates if the event expired.
`public virtual const float `[`GetLocalTime`](#classUNEventDecorator_1aa20a4fea4a15bf4e2fa1a41f303fa52e)`() const` | Returns the localTime since the events has been attached (- delay) to a timeline
`public virtual const float `[`GetStartedAt`](#classUNEventDecorator_1a8cf74bd6fbadd256e499e4ef9094ba79)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public virtual float `[`GetDuration`](#classUNEventDecorator_1a678ba817c31779c5ae2d216995337078)`() const` | The duration this event should live
`public virtual void `[`Start`](#classUNEventDecorator_1a7137c38ec0511ca1beabe2e4f83b641e)`(float StartTime)` | This should be used only by [NTimeline](#classNTimeline) or serialization.
`public virtual void `[`Stop`](#classUNEventDecorator_1a9dcf17fc0df1d11e6e2f42225c4bf5ed)`()` | This can stop the event and make it expires to its next tick.
`public virtual void `[`NotifyAddTime`](#classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07)`(float NewTime)` | Increments LocalTime 
`public virtual float `[`GetDelay`](#classUNEventDecorator_1a33715665287b45121f2ff25514c41ef1)`() const` | The delay before this event starts
`public virtual const FName `[`GetEventLabel`](#classUNEventDecorator_1ad88e97e6031018c0f3de2ce245341dd6)`() const` | Getter for Label
`public virtual void `[`SetEventLabel`](#classUNEventDecorator_1a0780498b4c684dea9487841549335167)`(FName _EventLabel)` | A setter for the label.
`public virtual const FString `[`GetUID`](#classUNEventDecorator_1a4bddd3ceb943d396ee3d1b63e91fd08f)`() const` | Retrieve the unique ID generated or given in ctor
`public virtual void `[`SetUID`](#classUNEventDecorator_1aff38e8b516d0a030d2d3830023ab7447)`(FString _UId)` | This should be used only on serialization process
`public virtual void `[`SetLocalTime`](#classUNEventDecorator_1a1bd2690e366d7ad871e74007c15fe07b)`(float _LocalTime)` | This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07).
`public virtual void `[`SetDuration`](#classUNEventDecorator_1ade8dd2b05d490b5892aaf63991aa1e6d)`(float _Duration)` | A setter for the duration.
`public virtual void `[`SetDelay`](#classUNEventDecorator_1a59b38b2293b9e6ac91fd1161821b8600)`(float _Delay)` | A setter for the delay.
`public virtual void `[`Clear`](#classUNEventDecorator_1a6876f229d6f190d204abe89ba0847d1e)`()` | This should reset all data
`public virtual FNEventDelegate & `[`OnStart`](#classUNEventDecorator_1af13744ea49840bc9a01d60518c1b92b8)`()` | #### Returns
`public virtual void `[`BeginDestroy`](#classUNEventDecorator_1a75739f0f1ec3c9dcde05bddb93e00664)`()` | 
`public virtual void `[`Serialize`](#classUNEventDecorator_1ac1bbc6721835bf4aa992cc2e1e0ee9b7)`(FArchive & Ar)` | 
`public void `[`OnInit`](#classUNEventDecorator_1aa79688c15f32adc31cd1e930fd6434ff)`()` | 
`public virtual void `[`Init`](#classUNEventDecorator_1ad591c3d4e879b2423e5a61915599f562)`(FName _Label,FString UId)` | This is where the Core object is instanciated. You should override this to instanciate your derived core object.
`public virtual TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`GetEvent`](#classUNEventDecorator_1a289aa0372ca4512839143e84617dec47)`() const` | This is used by other decorators which need to pass the core object to their own. 
`protected TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`Event`](#classUNEventDecorator_1a0c2fe0db6d7d2eb0f837d3f5e79d875e) | The actual decorator is for this object. It shoulds be instanciate on a ctor or a dedicated init function

## Members

#### `public inline  `[`UNEventDecorator`](#classUNEventDecorator_1a863909d823063f8446d2dcf30fe8174c)`()` <a id="classUNEventDecorator_1a863909d823063f8446d2dcf30fe8174c"></a>

#### `public virtual bool `[`IsExpired`](#classUNEventDecorator_1ae69c1d2dc0bd6bbe4381e0387d96ed1e)`() const` <a id="classUNEventDecorator_1ae69c1d2dc0bd6bbe4381e0387d96ed1e"></a>

It indicates if the event expired.

#### `public virtual const float `[`GetLocalTime`](#classUNEventDecorator_1aa20a4fea4a15bf4e2fa1a41f303fa52e)`() const` <a id="classUNEventDecorator_1aa20a4fea4a15bf4e2fa1a41f303fa52e"></a>

Returns the localTime since the events has been attached (- delay) to a timeline

#### `public virtual const float `[`GetStartedAt`](#classUNEventDecorator_1a8cf74bd6fbadd256e499e4ef9094ba79)`() const` <a id="classUNEventDecorator_1a8cf74bd6fbadd256e499e4ef9094ba79"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public virtual float `[`GetDuration`](#classUNEventDecorator_1a678ba817c31779c5ae2d216995337078)`() const` <a id="classUNEventDecorator_1a678ba817c31779c5ae2d216995337078"></a>

The duration this event should live

#### `public virtual void `[`Start`](#classUNEventDecorator_1a7137c38ec0511ca1beabe2e4f83b641e)`(float StartTime)` <a id="classUNEventDecorator_1a7137c38ec0511ca1beabe2e4f83b641e"></a>

This should be used only by [NTimeline](#classNTimeline) or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public virtual void `[`Stop`](#classUNEventDecorator_1a9dcf17fc0df1d11e6e2f42225c4bf5ed)`()` <a id="classUNEventDecorator_1a9dcf17fc0df1d11e6e2f42225c4bf5ed"></a>

This can stop the event and make it expires to its next tick.

#### `public virtual void `[`NotifyAddTime`](#classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07)`(float NewTime)` <a id="classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual float `[`GetDelay`](#classUNEventDecorator_1a33715665287b45121f2ff25514c41ef1)`() const` <a id="classUNEventDecorator_1a33715665287b45121f2ff25514c41ef1"></a>

The delay before this event starts

#### `public virtual const FName `[`GetEventLabel`](#classUNEventDecorator_1ad88e97e6031018c0f3de2ce245341dd6)`() const` <a id="classUNEventDecorator_1ad88e97e6031018c0f3de2ce245341dd6"></a>

Getter for Label

#### `public virtual void `[`SetEventLabel`](#classUNEventDecorator_1a0780498b4c684dea9487841549335167)`(FName _EventLabel)` <a id="classUNEventDecorator_1a0780498b4c684dea9487841549335167"></a>

A setter for the label.

#### Parameters
* `_EventLabel` - A name to identify easily the event

#### `public virtual const FString `[`GetUID`](#classUNEventDecorator_1a4bddd3ceb943d396ee3d1b63e91fd08f)`() const` <a id="classUNEventDecorator_1a4bddd3ceb943d396ee3d1b63e91fd08f"></a>

Retrieve the unique ID generated or given in ctor

#### `public virtual void `[`SetUID`](#classUNEventDecorator_1aff38e8b516d0a030d2d3830023ab7447)`(FString _UId)` <a id="classUNEventDecorator_1aff38e8b516d0a030d2d3830023ab7447"></a>

This should be used only on serialization process

#### Parameters
* `_UId` - Should be a unique FString, see ctor

#### `public virtual void `[`SetLocalTime`](#classUNEventDecorator_1a1bd2690e366d7ad871e74007c15fe07b)`(float _LocalTime)` <a id="classUNEventDecorator_1a1bd2690e366d7ad871e74007c15fe07b"></a>

This setter should be carrefully used, all the computation time should be calculated internally with the [NotifyAddTime()](#classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07).

#### Parameters
* `_LocalTime` - Time in secs

#### `public virtual void `[`SetDuration`](#classUNEventDecorator_1ade8dd2b05d490b5892aaf63991aa1e6d)`(float _Duration)` <a id="classUNEventDecorator_1ade8dd2b05d490b5892aaf63991aa1e6d"></a>

A setter for the duration.

#### Parameters
* `_Duration` - Time in secs

#### `public virtual void `[`SetDelay`](#classUNEventDecorator_1a59b38b2293b9e6ac91fd1161821b8600)`(float _Delay)` <a id="classUNEventDecorator_1a59b38b2293b9e6ac91fd1161821b8600"></a>

A setter for the delay.

#### Parameters
* `_Delay` - Time in secs

#### `public virtual void `[`Clear`](#classUNEventDecorator_1a6876f229d6f190d204abe89ba0847d1e)`()` <a id="classUNEventDecorator_1a6876f229d6f190d204abe89ba0847d1e"></a>

This should reset all data

#### `public virtual FNEventDelegate & `[`OnStart`](#classUNEventDecorator_1af13744ea49840bc9a01d60518c1b92b8)`()` <a id="classUNEventDecorator_1af13744ea49840bc9a01d60518c1b92b8"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

#### `public virtual void `[`BeginDestroy`](#classUNEventDecorator_1a75739f0f1ec3c9dcde05bddb93e00664)`()` <a id="classUNEventDecorator_1a75739f0f1ec3c9dcde05bddb93e00664"></a>

#### `public virtual void `[`Serialize`](#classUNEventDecorator_1ac1bbc6721835bf4aa992cc2e1e0ee9b7)`(FArchive & Ar)` <a id="classUNEventDecorator_1ac1bbc6721835bf4aa992cc2e1e0ee9b7"></a>

#### `public void `[`OnInit`](#classUNEventDecorator_1aa79688c15f32adc31cd1e930fd6434ff)`()` <a id="classUNEventDecorator_1aa79688c15f32adc31cd1e930fd6434ff"></a>

#### `public virtual void `[`Init`](#classUNEventDecorator_1ad591c3d4e879b2423e5a61915599f562)`(FName _Label,FString UId)` <a id="classUNEventDecorator_1ad591c3d4e879b2423e5a61915599f562"></a>

This is where the Core object is instanciated. You should override this to instanciate your derived core object.

#### `public virtual TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`GetEvent`](#classUNEventDecorator_1a289aa0372ca4512839143e84617dec47)`() const` <a id="classUNEventDecorator_1a289aa0372ca4512839143e84617dec47"></a>

This is used by other decorators which need to pass the core object to their own. 
**See also**: [UNTimelineDecorator::Attached()](#classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e)

#### `protected TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`Event`](#classUNEventDecorator_1a0c2fe0db6d7d2eb0f837d3f5e79d875e) <a id="classUNEventDecorator_1a0c2fe0db6d7d2eb0f837d3f5e79d875e"></a>

The actual decorator is for this object. It shoulds be instanciate on a ctor or a dedicated init function

# class `UNGameLifeTimelineManager` <a id="classUNGameLifeTimelineManager"></a>

```
class UNGameLifeTimelineManager
  : public UNTimelineManagerDecorator
```  

This decorator is fitted to track time when player plays since the game is launched.

It used internally an FTimerManager to tick and to works accordingly with all time alterations (game pause, slowmo, ...). It could be usefull for bonus/malus attribution which works during the full game session.

For example: Player makes a very benevolent actions which gives him a health bonus for 10 minutes in game.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) | Created by the FTimerManager
`public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) | Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0)
`public virtual void `[`Init`](#classUNGameLifeTimelineManager_1ab2c4380eca466bf77534b3bfa05f4bb7)`(float _TickInterval,FName _Label)` | It creates the timer with a FTimerManager and attached TimerDelegate to it. 
`public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` | clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)
`protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) | This is only used for savegame to keep time between sessions
`protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` | A default ctor for engine system

## Members

#### `public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) <a id="classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab"></a>

Created by the FTimerManager

#### `public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) <a id="classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61"></a>

Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0)

#### `public virtual void `[`Init`](#classUNGameLifeTimelineManager_1ab2c4380eca466bf77534b3bfa05f4bb7)`(float _TickInterval,FName _Label)` <a id="classUNGameLifeTimelineManager_1ab2c4380eca466bf77534b3bfa05f4bb7"></a>

It creates the timer with a FTimerManager and attached TimerDelegate to it. 
#### Parameters
* `_Label` - Name of the timer

#### `public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` <a id="classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8"></a>

clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)

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
`public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a464dbe9bdc4bd9380268f5cd71e2b897)`()` | Removes all attached events clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)
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

Removes all attached events clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1a54129c39bf3c4233007f203c5ae16728)

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
  : public UNTimelineManagerDecorator
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
`public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` | This override methods allows to tick [UNTimelineManagerDecorator::TimerTick()](#classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0) and to increment times vars.
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
**See also**: [UNTimelineManagerDecorator()](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)

#### Parameters
* `_TickInterval` - Interval time between tick in sec 

* `_Label` - Name of the Timeline.

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1)`() const` <a id="classUNRealLifeTimelineManager_1ad7abddd3e05fd402eecd58210b17b1c1"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` <a id="classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` <a id="classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e"></a>

This override methods allows to tick [UNTimelineManagerDecorator::TimerTick()](#classNTimelineManager_1a50c800144ff6072bd95f68360cc071d0) and to increment times vars.

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
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1adef671dac978ef3a26eb7ec28b928c29)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` | A blueprint pass-through for GetTimeline(FName Name).
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1a25d292f407cebcf4bf58fdbc130be874)`(FName Name) const` | Get the timeline from TimelinesCollection by its name.
`public virtual void `[`Serialize`](#classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27)`(FArchive & Ar)` | It used to save all timelines in the TimelinesCollection, and reload them correctly.
`protected TMap< FName, `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * > `[`TimelinesCollection`](#classUNTimelineClient_1af9b1553ab4dbf3246725aae6f379c9ae) | Collection of timelines instanciated by [InstanciateTimelinesFromConfig()](#classUNTimelineClient_1a975de7e3dace38650ce072a999f21866)
`protected void `[`InstanciateTimelinesFromConfig`](#classUNTimelineClient_1a975de7e3dace38650ce072a999f21866)`()` | 

## Members

#### `public  `[`UNTimelineClient`](#classUNTimelineClient_1a5681002cd61186d942306798fd0140fa)`()` <a id="classUNTimelineClient_1a5681002cd61186d942306798fd0140fa"></a>

#### `public virtual void `[`Init`](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)`()` <a id="classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615"></a>

This method allows to instanciate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).

**See also**: [FConfiguredTimeline](#structFConfiguredTimeline)

#### `public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1adef671dac978ef3a26eb7ec28b928c29)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` <a id="classUNTimelineClient_1adef671dac978ef3a26eb7ec28b928c29"></a>

A blueprint pass-through for GetTimeline(FName Name).

#### Parameters
* `Config` - To allow having a combobox of configured timeline

#### `public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1a25d292f407cebcf4bf58fdbc130be874)`(FName Name) const` <a id="classUNTimelineClient_1a25d292f407cebcf4bf58fdbc130be874"></a>

Get the timeline from TimelinesCollection by its name.

#### Parameters
* `Name` - The name of the timeline

#### `public virtual void `[`Serialize`](#classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27)`(FArchive & Ar)` <a id="classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27"></a>

It used to save all timelines in the TimelinesCollection, and reload them correctly.

#### Parameters
* `Ar` - Archive for save and load

#### `protected TMap< FName, `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * > `[`TimelinesCollection`](#classUNTimelineClient_1af9b1553ab4dbf3246725aae6f379c9ae) <a id="classUNTimelineClient_1af9b1553ab4dbf3246725aae6f379c9ae"></a>

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
`public TArray< `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf)` > `[`ConfiguredTimeline`](#classUNTimelineConfig_1a8e65c72e77d25e4787435f6cd8a6e23d) | 

## Members

#### `public TArray< `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf)` > `[`ConfiguredTimeline`](#classUNTimelineConfig_1a8e65c72e77d25e4787435f6cd8a6e23d) <a id="classUNTimelineConfig_1a8e65c72e77d25e4787435f6cd8a6e23d"></a>

# class `UNTimelineDecorator` <a id="classUNTimelineDecorator"></a>

```
class UNTimelineDecorator
  : public UObject
  : public NTimelineInterface
```  

The decorator for [NTimelineInterface](#classNTimelineInterface) object.

It manages:

* serialization

* attachment of [UNEventDecorator](#classUNEventDecorator) object to the embeded [NTimeline](#classNTimeline)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNTimelineDecorator`](#classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0)`()` | Just a default ctor for UObject paradigme
`public virtual void `[`Init`](#classUNTimelineDecorator_1a5875e0cd5c876f0303be703bfb3f9d52)`(`[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * TimelineManager,FName _Label)` | this method is used to instanciate the embeded [NTimeline](#classNTimeline)
`public virtual void `[`Clear`](#classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305)`()` | Reset default data
`public virtual void `[`SetTickInterval`](#classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d)`(float _TickInterval)` | Defined the tick interval for this timeline
`public virtual void `[`SetCurrentTime`](#classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce)`(float _CurrentTime)` | Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)
`public virtual float `[`GetCurrentTime`](#classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2)`() const` | Retrieve the current time since this timeline exists and play
`public virtual void `[`SetLabel`](#classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763)`(FName _Label)` | Give a name to this timeline
`public virtual FName `[`GetLabel`](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)`() const` | Return the actual name
`public virtual void `[`NotifyTick`](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)`()` | This manages to notify every events saved in this timeline with the new time added.
`public inline virtual bool `[`Attached`](#classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | This object should works only with Decorators. This method is reserved for core objects. 
`public inline virtual void `[`Attached`](#classUNTimelineDecorator_1abcf856f19c3608357de804d15d0e2689)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | This object should works only with Decorators. This method is reserved for core objects. 
`public virtual void `[`BeginDestroy`](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3)`()` | 
`public virtual void `[`Serialize`](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9)`(FArchive & Ar)` | It used to save all events state in the EventStore, and reload them correclty.
`public TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`GetTimeline`](#classUNTimelineDecorator_1a18c2085acb175e91abfcebc41c706758)`() const` | 
`public virtual void `[`AddEvent`](#classUNTimelineDecorator_1a39979ad6186e008643b2e6212bd87ae9)`(`[`UNEventDecorator`](#classUNEventDecorator)` * Event)` | This method is made to work with decorators object. It will save data in the EventStore array for serialization and save game. 
`public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71)`() const` | This retrieve the EventStore
`public `[`FNEventRecord`](#structFNEventRecord)` * `[`GetEventRecord`](#classUNTimelineDecorator_1ae3a50854058b0abf00fca41eb21f05b5)`(FString UId)` | Retrieve an event record by its Id
`public void `[`OnTimelineEventExpired`](#classUNTimelineDecorator_1a9333ccf12bfeaf5513307bc77c7cfbd1)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` | A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a721aa7e672e1bf842cdfb2f9a64f01df). It controls the EventStore data refreshing.
`public virtual FNTimelineEventDelegate & `[`OnEventExpired`](#classUNTimelineDecorator_1aeda133e24b140024c3aac51a56a217cf)`()` | #### Returns
`public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` | Creates a new Event and use this timeline as the outer for this new object.
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76) | The embeded object
`protected virtual void `[`RefreshRecordData`](#classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a)`(const int32 & Index)` | This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

## Members

#### `public inline  `[`UNTimelineDecorator`](#classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0)`()` <a id="classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0"></a>

Just a default ctor for UObject paradigme

#### `public virtual void `[`Init`](#classUNTimelineDecorator_1a5875e0cd5c876f0303be703bfb3f9d52)`(`[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * TimelineManager,FName _Label)` <a id="classUNTimelineDecorator_1a5875e0cd5c876f0303be703bfb3f9d52"></a>

this method is used to instanciate the embeded [NTimeline](#classNTimeline)
#### Parameters
* `TimelineManager` - The Decorator which provide the [NTimelineManager](#classNTimelineManager) object.

#### `public virtual void `[`Clear`](#classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305)`()` <a id="classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305"></a>

Reset default data

#### `public virtual void `[`SetTickInterval`](#classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d)`(float _TickInterval)` <a id="classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d"></a>

Defined the tick interval for this timeline

#### Parameters
* `_TickInterval` - Time in secs

#### `public virtual void `[`SetCurrentTime`](#classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce)`(float _CurrentTime)` <a id="classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce"></a>

Should be used only for serialization because it is internnaly computed with [NotifyTick()](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)

#### Parameters
* `_CurrentTime` - Time in secs

#### `public virtual float `[`GetCurrentTime`](#classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2)`() const` <a id="classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2"></a>

Retrieve the current time since this timeline exists and play

#### `public virtual void `[`SetLabel`](#classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763)`(FName _Label)` <a id="classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763"></a>

Give a name to this timeline

#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)`() const` <a id="classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04"></a>

Return the actual name

#### `public virtual void `[`NotifyTick`](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)`()` <a id="classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414"></a>

This manages to notify every events saved in this timeline with the new time added.

#### `public inline virtual bool `[`Attached`](#classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e"></a>

This object should works only with Decorators. This method is reserved for core objects. 
**See also**: UNTimelineDecorator::Attached(UNEventDecorator* Event)

#### `public inline virtual void `[`Attached`](#classUNTimelineDecorator_1abcf856f19c3608357de804d15d0e2689)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classUNTimelineDecorator_1abcf856f19c3608357de804d15d0e2689"></a>

This object should works only with Decorators. This method is reserved for core objects. 
**See also**: UNTimelineDecorator::Attached(UNEventDecorator* Event)

#### `public virtual void `[`BeginDestroy`](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3)`()` <a id="classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3"></a>

#### `public virtual void `[`Serialize`](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9)`(FArchive & Ar)` <a id="classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9"></a>

It used to save all events state in the EventStore, and reload them correclty.

#### Parameters
* `Ar` - Archive for save and load

#### `public TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`GetTimeline`](#classUNTimelineDecorator_1a18c2085acb175e91abfcebc41c706758)`() const` <a id="classUNTimelineDecorator_1a18c2085acb175e91abfcebc41c706758"></a>

#### `public virtual void `[`AddEvent`](#classUNTimelineDecorator_1a39979ad6186e008643b2e6212bd87ae9)`(`[`UNEventDecorator`](#classUNEventDecorator)` * Event)` <a id="classUNTimelineDecorator_1a39979ad6186e008643b2e6212bd87ae9"></a>

This method is made to work with decorators object. It will save data in the EventStore array for serialization and save game. 
#### Parameters
* `Event` - The decorator event

#### `public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71)`() const` <a id="classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71"></a>

This retrieve the EventStore

#### `public `[`FNEventRecord`](#structFNEventRecord)` * `[`GetEventRecord`](#classUNTimelineDecorator_1ae3a50854058b0abf00fca41eb21f05b5)`(FString UId)` <a id="classUNTimelineDecorator_1ae3a50854058b0abf00fca41eb21f05b5"></a>

Retrieve an event record by its Id

#### `public void `[`OnTimelineEventExpired`](#classUNTimelineDecorator_1a9333ccf12bfeaf5513307bc77c7cfbd1)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classUNTimelineDecorator_1a9333ccf12bfeaf5513307bc77c7cfbd1"></a>

A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a721aa7e672e1bf842cdfb2f9a64f01df). It controls the EventStore data refreshing.

#### Parameters
* `Event` - The native Event which will be killed 

* `ExpiredTime` - The time when this event expires 

* `Index` - The index of the NTimeline::Events array

#### `public virtual FNTimelineEventDelegate & `[`OnEventExpired`](#classUNTimelineDecorator_1aeda133e24b140024c3aac51a56a217cf)`()` <a id="classUNTimelineDecorator_1aeda133e24b140024c3aac51a56a217cf"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcasted when an event expires.

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7"></a>

Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76) <a id="classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76"></a>

The embeded object

#### `protected virtual void `[`RefreshRecordData`](#classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a)`(const int32 & Index)` <a id="classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a"></a>

This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

#### Parameters
* `Index` - The index of the NTimeline::Events array 

* `Record` - The record you want to synchronize.

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

# class `UNTimelineManagerDecorator` <a id="classUNTimelineManagerDecorator"></a>

```
class UNTimelineManagerDecorator
  : public UObject
  : public NTimelineManager
```  

This is the abstract decorator that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or UE4 c++ paradigm.

As the close relation between [NTimelineManager](#classNTimelineManager) and [NTimeline](#classNTimeline) classes (core lib), This class is coupled with [UNTimelineDecorator](#classUNTimelineDecorator). 
**See also**: [UNTimelineDecorator](#classUNTimelineDecorator)

To ease blueprint usages, most of the [UNTimelineDecorator](#classUNTimelineDecorator) public functionnalities are accessible here. This class works as a pass-through too for [UNTimelineDecorator](#classUNTimelineDecorator).

**See also**: [AddEvent()](#classUNTimelineManagerDecorator_1a2b84bfc86395348ca4995b202b038238), [CreateNewEvent()](#classUNTimelineManagerDecorator_1a12df827b8172ba4e34bc163c2a9564de), [CreateAndAddNewEvent()](#classUNTimelineManagerDecorator_1a4029c1f60449033ca3dda2e28bdf7098)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Pause`](#classUNTimelineManagerDecorator_1a1b664da3c9dc614df40822ebce117cfb)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classUNTimelineManagerDecorator_1a16f09380884450c7b220f1c78c336cf3)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classUNTimelineManagerDecorator_1abe640ee5d20aed0044f17b625c5923ed)`()` | This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0
`public virtual void `[`SetTickInterval`](#classUNTimelineManagerDecorator_1a6924490076a80b578220f0536184c06e)`(float _TickInterval)` | Defined the desired ticking interval
`public virtual void `[`Init`](#classUNTimelineManagerDecorator_1afa01753617c42cf5c4a323b4e14c0c4d)`(float _TickInterval,FName _Label)` | The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public virtual void `[`Serialize`](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)`(FArchive & Ar)` | It's the starting link of serialization chain for all embeded decorators. This calls [UNTimelineDecorator::Serialize()](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9).
`public virtual void `[`BeginDestroy`](#classUNTimelineManagerDecorator_1ab6701a003cf2311d71890fa567089024)`()` | This call the [UNTimelineDecorator::BeginDestroy()](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3) too.
`public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerDecorator_1a752b30671744f945a588d4c35adedd81)`() const` | Get the events list. TODO should be great to have a type filter possibility with a TSubclassOf<UNEventDecorator> parameter
`public float `[`GetCurrentTime`](#classUNTimelineManagerDecorator_1adc4d0b50faa76c955cb928750de41352)`() const` | 
`public FName `[`GetLabel`](#classUNTimelineManagerDecorator_1aed6e9c7e069c9e7637076a7b235adf7f)`() const` | A pass-through for the embeded [UNTimelineDecorator::GetLabel()](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)
`public virtual void `[`AddEvent`](#classUNTimelineManagerDecorator_1a2b84bfc86395348ca4995b202b038238)`(`[`UNEventDecorator`](#classUNEventDecorator)` * Event)` | Adds an event to the timeline object, it works as a pass-through for UNTimelineDecorator::Attached(UNEventDecorator* Event)
`public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineManagerDecorator_1a12df827b8172ba4e34bc163c2a9564de)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` | A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7): Creates a new Event and use this timeline as the outer for this new object.
`public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerDecorator_1a4029c1f60449033ca3dda2e28bdf7098)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` | Attaches the event to the timeline stream + A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7): Creates a new Event and use this timeline as the outer for this new object.
`protected `[`UNTimelineDecorator`](#classUNTimelineDecorator)` * `[`MyTimeline`](#classUNTimelineManagerDecorator_1a5a5a6bff257a09d9146813eaeb53fe78) | the timeline associated to this manager.
`protected  `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)`()` | Protected ctor to force instanciation with CreateObject() methods (factory methods).

## Members

#### `public virtual void `[`Pause`](#classUNTimelineManagerDecorator_1a1b664da3c9dc614df40822ebce117cfb)`()` <a id="classUNTimelineManagerDecorator_1a1b664da3c9dc614df40822ebce117cfb"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classUNTimelineManagerDecorator_1a16f09380884450c7b220f1c78c336cf3)`()` <a id="classUNTimelineManagerDecorator_1a16f09380884450c7b220f1c78c336cf3"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classUNTimelineManagerDecorator_1abe640ee5d20aed0044f17b625c5923ed)`()` <a id="classUNTimelineManagerDecorator_1abe640ee5d20aed0044f17b625c5923ed"></a>

This pause the timeline ticking and reset the [NTimeline::CurrentTime](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) to 0

#### `public virtual void `[`SetTickInterval`](#classUNTimelineManagerDecorator_1a6924490076a80b578220f0536184c06e)`(float _TickInterval)` <a id="classUNTimelineManagerDecorator_1a6924490076a80b578220f0536184c06e"></a>

Defined the desired ticking interval

#### `public virtual void `[`Init`](#classUNTimelineManagerDecorator_1afa01753617c42cf5c4a323b4e14c0c4d)`(float _TickInterval,FName _Label)` <a id="classUNTimelineManagerDecorator_1afa01753617c42cf5c4a323b4e14c0c4d"></a>

The embeded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerDecorator()](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)

#### Parameters
* `_TickInterval` - Interval time between tick in sec 

* `_Label` - Name of the Timeline.

#### `public virtual void `[`Serialize`](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)`(FArchive & Ar)` <a id="classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831"></a>

It's the starting link of serialization chain for all embeded decorators. This calls [UNTimelineDecorator::Serialize()](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9).

#### Parameters
* `Ar` - the FArchive used for serialization as usual.

#### `public virtual void `[`BeginDestroy`](#classUNTimelineManagerDecorator_1ab6701a003cf2311d71890fa567089024)`()` <a id="classUNTimelineManagerDecorator_1ab6701a003cf2311d71890fa567089024"></a>

This call the [UNTimelineDecorator::BeginDestroy()](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3) too.

#### `public virtual const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetEvents`](#classUNTimelineManagerDecorator_1a752b30671744f945a588d4c35adedd81)`() const` <a id="classUNTimelineManagerDecorator_1a752b30671744f945a588d4c35adedd81"></a>

Get the events list. TODO should be great to have a type filter possibility with a TSubclassOf<UNEventDecorator> parameter

#### `public float `[`GetCurrentTime`](#classUNTimelineManagerDecorator_1adc4d0b50faa76c955cb928750de41352)`() const` <a id="classUNTimelineManagerDecorator_1adc4d0b50faa76c955cb928750de41352"></a>

#### `public FName `[`GetLabel`](#classUNTimelineManagerDecorator_1aed6e9c7e069c9e7637076a7b235adf7f)`() const` <a id="classUNTimelineManagerDecorator_1aed6e9c7e069c9e7637076a7b235adf7f"></a>

A pass-through for the embeded [UNTimelineDecorator::GetLabel()](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)

#### `public virtual void `[`AddEvent`](#classUNTimelineManagerDecorator_1a2b84bfc86395348ca4995b202b038238)`(`[`UNEventDecorator`](#classUNEventDecorator)` * Event)` <a id="classUNTimelineManagerDecorator_1a2b84bfc86395348ca4995b202b038238"></a>

Adds an event to the timeline object, it works as a pass-through for UNTimelineDecorator::Attached(UNEventDecorator* Event)

#### Parameters
* `Event` - An Event object you want to saved to the associated timeline.

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineManagerDecorator_1a12df827b8172ba4e34bc163c2a9564de)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerDecorator_1a12df827b8172ba4e34bc163c2a9564de"></a>

A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7): Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerDecorator_1a4029c1f60449033ca3dda2e28bdf7098)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` <a id="classUNTimelineManagerDecorator_1a4029c1f60449033ca3dda2e28bdf7098"></a>

Attaches the event to the timeline stream + A pass-through for [UNTimelineDecorator::CreateNewEvent()](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7): Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Class` - The derived class of your choice 

* `Name` - The label of the event, can be usefull for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undeterminated time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `protected `[`UNTimelineDecorator`](#classUNTimelineDecorator)` * `[`MyTimeline`](#classUNTimelineManagerDecorator_1a5a5a6bff257a09d9146813eaeb53fe78) <a id="classUNTimelineManagerDecorator_1a5a5a6bff257a09d9146813eaeb53fe78"></a>

the timeline associated to this manager.

#### `protected  `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)`()` <a id="classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd"></a>

Protected ctor to force instanciation with CreateObject() methods (factory methods).

It instanciates the embeded timeline with CreateDefaultSubobject().

# class `UNTimelineManagerDecoratorFactory` <a id="classUNTimelineManagerDecoratorFactory"></a>

This class is a factory to managed properly [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) instanciation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `FConfiguredTimeline` <a id="structFConfiguredTimeline"></a>

This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) | This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.
`public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimeline_1aa0763505594b494c99c1e616ce95533b) | The Configured Timeline class

## Members

#### `public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) <a id="structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6"></a>

This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.

#### `public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimeline_1aa0763505594b494c99c1e616ce95533b) <a id="structFConfiguredTimeline_1aa0763505594b494c99c1e616ce95533b"></a>

The Configured Timeline class

# struct `FConfiguredTimelineConf` <a id="structFConfiguredTimelineConf"></a>

This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFConfiguredTimelineConf_1a50b49283e97d44dba511bfe696c818bc) | This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.
`public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimelineConf_1adc85551cc214da691536b3ca60045896) | The Configured Timeline class
`public float `[`TickInterval`](#structFConfiguredTimelineConf_1a237b9ef8f53f8d1dd4072a6befffbf76) | You can use this to add more or less frequency between each tick.

## Members

#### `public FName `[`Name`](#structFConfiguredTimelineConf_1a50b49283e97d44dba511bfe696c818bc) <a id="structFConfiguredTimelineConf_1a50b49283e97d44dba511bfe696c818bc"></a>

This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.

#### `public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimelineConf_1adc85551cc214da691536b3ca60045896) <a id="structFConfiguredTimelineConf_1adc85551cc214da691536b3ca60045896"></a>

The Configured Timeline class

#### `public float `[`TickInterval`](#structFConfiguredTimelineConf_1a237b9ef8f53f8d1dd4072a6befffbf76) <a id="structFConfiguredTimelineConf_1a237b9ef8f53f8d1dd4072a6befffbf76"></a>

You can use this to add more or less frequency between each tick.

# struct `FNEventRecord` <a id="structFNEventRecord"></a>

This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a3343fdc03d8785b874d6c9c00590f1b5) and a record object used for savegame.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`Event`](#structFNEventRecord_1a26e0a371b63a69727963bae05415c4b6) | The [UNEventDecorator](#classUNEventDecorator) object
`public FString `[`UId`](#structFNEventRecord_1a7f2897d3d4d99b00731ab28a8453a18e) | The [UNEventDecorator](#classUNEventDecorator) UId, it can be used to create consistant link to an object that envelops and EventDecorator
`public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) | The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt)
`public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) | The delay before starting in secs
`public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) | The duration this event lives in secs (0 means inderterminate)
`public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) | The name of the event
`public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) | Expiration time of this event in secs (0 means can't expired))
`public FString `[`EventClassName`](#structFNEventRecord_1a5ebb6654bd18ffe427e104f74fd9ba93) | This is used only for serialization, it allow to re-instance the object on load
`public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` | 
`public void `[`Serialize`](#structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4)`(FArchive & Ar,`[`UNTimelineDecorator`](#classUNTimelineDecorator)` * Timeline)` | It manages Event object saving and loading

## Members

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`Event`](#structFNEventRecord_1a26e0a371b63a69727963bae05415c4b6) <a id="structFNEventRecord_1a26e0a371b63a69727963bae05415c4b6"></a>

The [UNEventDecorator](#classUNEventDecorator) object

#### `public FString `[`UId`](#structFNEventRecord_1a7f2897d3d4d99b00731ab28a8453a18e) <a id="structFNEventRecord_1a7f2897d3d4d99b00731ab28a8453a18e"></a>

The [UNEventDecorator](#classUNEventDecorator) UId, it can be used to create consistant link to an object that envelops and EventDecorator

#### `public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) <a id="structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d"></a>

The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt)

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

#### `public void `[`Serialize`](#structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4)`(FArchive & Ar,`[`UNTimelineDecorator`](#classUNTimelineDecorator)` * Timeline)` <a id="structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4"></a>

It manages Event object saving and loading

Generated by [Moxygen](https://sourcey.com/moxygen)