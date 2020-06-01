# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`UNEventDecoratorFactory`](#namespaceUNEventDecoratorFactory) | 
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | Required to create a UE4 module
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | Required to create a UE4 module
`class `[`FTimelinePinFactory`](#classFTimelinePinFactory) | It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.
`class `[`INTimelineGameInstance`](#classINTimelineGameInstance) | This interface should be implemented by your GameInstance class or blueprint object. See README.md in step by step guide to see how to implements it.
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemCoreTimelineTest`](#classNansTimelineSystemCoreTimelineTest) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NEvent`](#classNEvent) | An abstract class to manage events which can be attached to a timeline.
`class `[`NEventFake`](#classNEventFake) | 
`class `[`NEventInterface`](#classNEventInterface) | 
`class `[`NTimeline`](#classNTimeline) | Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManager](#classNTimelineManager) class is dedicated to handle it.
`class `[`NTimelineInterface`](#classNTimelineInterface) | 
`class `[`NTimelineManager`](#classNTimelineManager) | This class is the client for the [NTimelineInterface](#classNTimelineInterface) object. Its goal is to decoupled client interface with timeline management.
`class `[`NTimelineManagerFake`](#classNTimelineManagerFake) | This class is used for tests only
`class `[`NUnrealEventProxy`](#classNUnrealEventProxy) | This class is just a pass-through to allows an [UNEventDecorator](#classUNEventDecorator) (a derived UObject) to be passed on the core system using TSharedPtr.
`class `[`NUnrealTimelineProxy`](#classNUnrealTimelineProxy) | This class is a pass-through to allows an [NUnrealTimelineProxy](#classNUnrealTimelineProxy) (a derived UObject) to be passed on the core system using TSharedPtr, and it manages [NUnrealEventProxy](#classNUnrealEventProxy) attachment .
`class `[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin) | This class allows to create a dedicated pin to get names from [UNTimelineConfig](#classUNTimelineConfig).
`class `[`TimelineManagerTickableOnPauseFake`](#classTimelineManagerTickableOnPauseFake) | This class is used for tests only
`class `[`TimelineTimerManagerFake`](#classTimelineTimerManagerFake) | 
`class `[`UNEventDecorator`](#classUNEventDecorator) | Base abstract class to create [NEventInterface](#classNEventInterface) decorators (Blueprint or c++).
`class `[`UNEventDecoratorFake`](#classUNEventDecoratorFake) | This class is used for tests only
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | This decorator is fitted to track time when player plays since the game is launched.
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | It tracks game session but refreshes when level changed.
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | It tracks realtime, it is not altered by pause or slowmo.
`class `[`UNTimelineBlueprintHelpers`](#classUNTimelineBlueprintHelpers) | A simple Blueprint Library class to manage Timeline creation.
`class `[`UNTimelineClient`](#classUNTimelineClient) | This class should be used by your GameInstance object. This object is the glue for all the timeline configuration and blueprint helpers.
`class `[`UNTimelineConfig`](#classUNTimelineConfig) | A simple configuration to ease timeline instanciation for developpers.
`class `[`UNTimelineDecorator`](#classUNTimelineDecorator) | The decorator for [NTimelineInterface](#classNTimelineInterface) object.
`class `[`UNTimelineGameInstance`](#classUNTimelineGameInstance) | **See also**: [INTimelineGameInstance](#classINTimelineGameInstance)
`class `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator) | This is the abstract decorator that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or c++.
`class `[`UNTimelineManagerDecoratorFactory`](#classUNTimelineManagerDecoratorFactory) | This class is a factory to managed properly [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) instanciation.
`struct `[`FConfiguredTimeline`](#structFConfiguredTimeline) | This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.
`struct `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf) | This struct to create Configured Timeline and ease Timeline instanciation. This allows to associated a Timeline Name to a class.
`struct `[`FNEventRecord`](#structFNEventRecord) | This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4) and a record object used for savegame.
`struct `[`FTimelineNameProperty`](#structFTimelineNameProperty) | 

# namespace `UNEventDecoratorFactory` <a id="namespaceUNEventDecoratorFactory"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`static T * `[`CreateObject`](#namespaceUNEventDecoratorFactory_1acc8cc41bc9714c3d5e9839fde6ee21f1)`(UObject * Outer,const TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,EObjectFlags Flags)`            | 
`public template<>`  <br/>`static T * `[`CreateObjectFromEvent`](#namespaceUNEventDecoratorFactory_1a3241b578d59be218ae144fa65454cf39)`(UObject * Outer,const TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Object,const TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,EObjectFlags Flags)`            | 

## Members

#### `public template<>`  <br/>`static T * `[`CreateObject`](#namespaceUNEventDecoratorFactory_1acc8cc41bc9714c3d5e9839fde6ee21f1)`(UObject * Outer,const TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,EObjectFlags Flags)` <a id="namespaceUNEventDecoratorFactory_1acc8cc41bc9714c3d5e9839fde6ee21f1"></a>

#### `public template<>`  <br/>`static T * `[`CreateObjectFromEvent`](#namespaceUNEventDecoratorFactory_1a3241b578d59be218ae144fa65454cf39)`(UObject * Outer,const TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Object,const TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,EObjectFlags Flags)` <a id="namespaceUNEventDecoratorFactory_1a3241b578d59be218ae144fa65454cf39"></a>

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

# class `NansTimelineSystemCoreTimelineTest` <a id="classNansTimelineSystemCoreTimelineTest"></a>

```
class NansTimelineSystemCoreTimelineTest
  : public Test
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`protected `[`TimelineTimerManagerFake`](#classTimelineTimerManagerFake)` * `[`Timer`](#classNansTimelineSystemCoreTimelineTest_1a5d2721999f5c5737a3b604c81c3623dc) | 
`protected TArray< TSharedPtr< `[`NEventFake`](#classNEventFake)` > > `[`Events`](#classNansTimelineSystemCoreTimelineTest_1a73e7e0074625ce997a29086a0070ff17) | 
`protected inline void `[`SetUp`](#classNansTimelineSystemCoreTimelineTest_1a8447b488cf4d6e2013bfd13f0d5e1791)`()` | 

## Members

#### `protected `[`TimelineTimerManagerFake`](#classTimelineTimerManagerFake)` * `[`Timer`](#classNansTimelineSystemCoreTimelineTest_1a5d2721999f5c5737a3b604c81c3623dc) <a id="classNansTimelineSystemCoreTimelineTest_1a5d2721999f5c5737a3b604c81c3623dc"></a>

#### `protected TArray< TSharedPtr< `[`NEventFake`](#classNEventFake)` > > `[`Events`](#classNansTimelineSystemCoreTimelineTest_1a73e7e0074625ce997a29086a0070ff17) <a id="classNansTimelineSystemCoreTimelineTest_1a73e7e0074625ce997a29086a0070ff17"></a>

#### `protected inline void `[`SetUp`](#classNansTimelineSystemCoreTimelineTest_1a8447b488cf4d6e2013bfd13f0d5e1791)`()` <a id="classNansTimelineSystemCoreTimelineTest_1a8447b488cf4d6e2013bfd13f0d5e1791"></a>

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

An abstract class to manage events which can be attached to a timeline.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NEvent`](#classNEvent_1aac75c1f215cd691c48e87495f2131686)`()` | Default ctor
`public inline  `[`NEvent`](#classNEvent_1aadd9d898d0ae0afc18955e15577ea281)`(FName _Label)` | Ctor to gives directly a name for this event.
`public inline virtual  `[`~NEvent`](#classNEvent_1a179af95c5b72caf083dc7dbbda577244)`()` | 
`public virtual bool `[`IsExpired`](#classNEvent_1a035106bed5f526ecf68ae7b067e7beff)`() const` | It computes with Duration and LocalTime
`public virtual const float `[`GetLocalTime`](#classNEvent_1a74e7fae4f40337ca18e115280d7ebf7f)`() const` | Getter for LocalTime
`public virtual const float `[`GetStartedAt`](#classNEvent_1a65f998aadcef8a8036f977c5f5226eee)`() const` | Getter for StartedAt
`public virtual float `[`GetDuration`](#classNEvent_1a27aa249bec02b2132fff7b521731ee81)`() const` | Getter for Duration
`public virtual void `[`Start`](#classNEvent_1a3ba279542a5aeddc86d924bbd4a12594)`(float StartTime)` | A setter for StartedAt
`public virtual float `[`GetDelay`](#classNEvent_1afed25f6f7bbd624401803a76d530f18f)`() const` | Increments LocalTime
`public virtual const FString `[`GetUID`](#classNEvent_1a902e03f2e33fd2a39e7b113c0bdc0f5c)`() const` | 
`public virtual const FName `[`GetEventLabel`](#classNEvent_1adefb1f4297e5e4b1342249b666396d9a)`() const` | Getter for Label
`public virtual void `[`SetLocalTime`](#classNEvent_1a09ebad2d5cd8c97ec830b55f1c347c3b)`(float _LocalTime)` | 
`public virtual void `[`SetStartedAt`](#classNEvent_1aab4e709ab903d1029543769f64a28f20)`(float _StartedAt)` | 
`public virtual void `[`SetDuration`](#classNEvent_1aed6e1d3aed21e84fad370ab2d1734510)`(float _Duration)` | 
`public virtual void `[`SetDelay`](#classNEvent_1ad6bc835e40776921b793b182af400d69)`(float _Delay)` | 
`public virtual void `[`SetEventLabel`](#classNEvent_1ab5066c7e0d47be716f3d6b6e45a04298)`(FName _EventLabel)` | 
`public virtual void `[`NotifyAddTime`](#classNEvent_1aef073190e18a886364a0ce8f41dda052)`(float NewTime)` | Increments LocalTime 
`public virtual void `[`Clear`](#classNEvent_1a52fefc3a883f2db7366b96e24d8bfed2)`()` | Reset all default data
`protected FName `[`Label`](#classNEvent_1aca50001fe9723034e65be03e06d3f59e) | 
`protected float `[`LocalTime`](#classNEvent_1a79caff85e8c98d0422a1e11dd47e27bb) | 
`protected float `[`StartedAt`](#classNEvent_1ab7eaaeb61f9c50c2882acf67c8c80b40) | 
`protected float `[`Duration`](#classNEvent_1a67fd9c10419486d8c1fda1a9a7b5f971) | 
`protected float `[`Delay`](#classNEvent_1a7bfe0f1f00c6781d84c8398bc0dc780d) | 
`protected FString `[`Id`](#classNEvent_1a8d80055abe14a0a04077153145e846af) | 

## Members

#### `public inline  `[`NEvent`](#classNEvent_1aac75c1f215cd691c48e87495f2131686)`()` <a id="classNEvent_1aac75c1f215cd691c48e87495f2131686"></a>

Default ctor

#### `public inline  `[`NEvent`](#classNEvent_1aadd9d898d0ae0afc18955e15577ea281)`(FName _Label)` <a id="classNEvent_1aadd9d898d0ae0afc18955e15577ea281"></a>

Ctor to gives directly a name for this event.

#### `public inline virtual  `[`~NEvent`](#classNEvent_1a179af95c5b72caf083dc7dbbda577244)`()` <a id="classNEvent_1a179af95c5b72caf083dc7dbbda577244"></a>

#### `public virtual bool `[`IsExpired`](#classNEvent_1a035106bed5f526ecf68ae7b067e7beff)`() const` <a id="classNEvent_1a035106bed5f526ecf68ae7b067e7beff"></a>

It computes with Duration and LocalTime

#### `public virtual const float `[`GetLocalTime`](#classNEvent_1a74e7fae4f40337ca18e115280d7ebf7f)`() const` <a id="classNEvent_1a74e7fae4f40337ca18e115280d7ebf7f"></a>

Getter for LocalTime

#### `public virtual const float `[`GetStartedAt`](#classNEvent_1a65f998aadcef8a8036f977c5f5226eee)`() const` <a id="classNEvent_1a65f998aadcef8a8036f977c5f5226eee"></a>

Getter for StartedAt

#### `public virtual float `[`GetDuration`](#classNEvent_1a27aa249bec02b2132fff7b521731ee81)`() const` <a id="classNEvent_1a27aa249bec02b2132fff7b521731ee81"></a>

Getter for Duration

#### `public virtual void `[`Start`](#classNEvent_1a3ba279542a5aeddc86d924bbd4a12594)`(float StartTime)` <a id="classNEvent_1a3ba279542a5aeddc86d924bbd4a12594"></a>

A setter for StartedAt

#### `public virtual float `[`GetDelay`](#classNEvent_1afed25f6f7bbd624401803a76d530f18f)`() const` <a id="classNEvent_1afed25f6f7bbd624401803a76d530f18f"></a>

Increments LocalTime

#### `public virtual const FString `[`GetUID`](#classNEvent_1a902e03f2e33fd2a39e7b113c0bdc0f5c)`() const` <a id="classNEvent_1a902e03f2e33fd2a39e7b113c0bdc0f5c"></a>

#### `public virtual const FName `[`GetEventLabel`](#classNEvent_1adefb1f4297e5e4b1342249b666396d9a)`() const` <a id="classNEvent_1adefb1f4297e5e4b1342249b666396d9a"></a>

Getter for Label

#### `public virtual void `[`SetLocalTime`](#classNEvent_1a09ebad2d5cd8c97ec830b55f1c347c3b)`(float _LocalTime)` <a id="classNEvent_1a09ebad2d5cd8c97ec830b55f1c347c3b"></a>

#### `public virtual void `[`SetStartedAt`](#classNEvent_1aab4e709ab903d1029543769f64a28f20)`(float _StartedAt)` <a id="classNEvent_1aab4e709ab903d1029543769f64a28f20"></a>

#### `public virtual void `[`SetDuration`](#classNEvent_1aed6e1d3aed21e84fad370ab2d1734510)`(float _Duration)` <a id="classNEvent_1aed6e1d3aed21e84fad370ab2d1734510"></a>

#### `public virtual void `[`SetDelay`](#classNEvent_1ad6bc835e40776921b793b182af400d69)`(float _Delay)` <a id="classNEvent_1ad6bc835e40776921b793b182af400d69"></a>

#### `public virtual void `[`SetEventLabel`](#classNEvent_1ab5066c7e0d47be716f3d6b6e45a04298)`(FName _EventLabel)` <a id="classNEvent_1ab5066c7e0d47be716f3d6b6e45a04298"></a>

#### `public virtual void `[`NotifyAddTime`](#classNEvent_1aef073190e18a886364a0ce8f41dda052)`(float NewTime)` <a id="classNEvent_1aef073190e18a886364a0ce8f41dda052"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Millisecs

#### `public virtual void `[`Clear`](#classNEvent_1a52fefc3a883f2db7366b96e24d8bfed2)`()` <a id="classNEvent_1a52fefc3a883f2db7366b96e24d8bfed2"></a>

Reset all default data

#### `protected FName `[`Label`](#classNEvent_1aca50001fe9723034e65be03e06d3f59e) <a id="classNEvent_1aca50001fe9723034e65be03e06d3f59e"></a>

#### `protected float `[`LocalTime`](#classNEvent_1a79caff85e8c98d0422a1e11dd47e27bb) <a id="classNEvent_1a79caff85e8c98d0422a1e11dd47e27bb"></a>

#### `protected float `[`StartedAt`](#classNEvent_1ab7eaaeb61f9c50c2882acf67c8c80b40) <a id="classNEvent_1ab7eaaeb61f9c50c2882acf67c8c80b40"></a>

#### `protected float `[`Duration`](#classNEvent_1a67fd9c10419486d8c1fda1a9a7b5f971) <a id="classNEvent_1a67fd9c10419486d8c1fda1a9a7b5f971"></a>

#### `protected float `[`Delay`](#classNEvent_1a7bfe0f1f00c6781d84c8398bc0dc780d) <a id="classNEvent_1a7bfe0f1f00c6781d84c8398bc0dc780d"></a>

#### `protected FString `[`Id`](#classNEvent_1a8d80055abe14a0a04077153145e846af) <a id="classNEvent_1a8d80055abe14a0a04077153145e846af"></a>

# class `NEventFake` <a id="classNEventFake"></a>

```
class NEventFake
  : public NEvent
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`EventLabel`](#classNEventFake_1a129e4e549acfc878f978e4641ea3ec54) | 
`public bool `[`bIsExpired`](#classNEventFake_1abcc66b37b5c90e35fa2ff39fd72c9a5f) | 
`public inline  `[`NEventFake`](#classNEventFake_1ad401180d71e0707c4251e8fb25618585)`(FName _Label,float _Duration,float _Delay)` | 
`public inline virtual bool `[`IsExpired`](#classNEventFake_1a833cdec860024ad7132719d170b6e5af)`() const` | It computes with Duration and LocalTime
`public inline virtual const FName `[`GetEventLabel`](#classNEventFake_1af6fe312384bdf34f547371fe14bdac55)`() const` | Getter for Label
`public inline void `[`SetExpired`](#classNEventFake_1ab012b45f8fe88cc569d4436e7901ef7c)`()` | 

## Members

#### `public FName `[`EventLabel`](#classNEventFake_1a129e4e549acfc878f978e4641ea3ec54) <a id="classNEventFake_1a129e4e549acfc878f978e4641ea3ec54"></a>

#### `public bool `[`bIsExpired`](#classNEventFake_1abcc66b37b5c90e35fa2ff39fd72c9a5f) <a id="classNEventFake_1abcc66b37b5c90e35fa2ff39fd72c9a5f"></a>

#### `public inline  `[`NEventFake`](#classNEventFake_1ad401180d71e0707c4251e8fb25618585)`(FName _Label,float _Duration,float _Delay)` <a id="classNEventFake_1ad401180d71e0707c4251e8fb25618585"></a>

#### `public inline virtual bool `[`IsExpired`](#classNEventFake_1a833cdec860024ad7132719d170b6e5af)`() const` <a id="classNEventFake_1a833cdec860024ad7132719d170b6e5af"></a>

It computes with Duration and LocalTime

#### `public inline virtual const FName `[`GetEventLabel`](#classNEventFake_1af6fe312384bdf34f547371fe14bdac55)`() const` <a id="classNEventFake_1af6fe312384bdf34f547371fe14bdac55"></a>

Getter for Label

#### `public inline void `[`SetExpired`](#classNEventFake_1ab012b45f8fe88cc569d4436e7901ef7c)`()` <a id="classNEventFake_1ab012b45f8fe88cc569d4436e7901ef7c"></a>

# class `NEventInterface` <a id="classNEventInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`IsExpired`](#classNEventInterface_1afd64986f323915c61ae5478764bde9de)`() const` | 
`public const float `[`GetLocalTime`](#classNEventInterface_1a77fbebce451091c6d6dda61a74f090d7)`() const` | 
`public const float `[`GetStartedAt`](#classNEventInterface_1a8452276ef3bb1621b5cd3b6eb38e2591)`() const` | 
`public float `[`GetDuration`](#classNEventInterface_1abb1b6c05e352b2dd0d8ad07401868851)`() const` | 
`public float `[`GetDelay`](#classNEventInterface_1a05ad20b16c2c9a07c82821ba9424b086)`() const` | 
`public const FString `[`GetUID`](#classNEventInterface_1ac3e7f334edceaff2915dfc2b2b7be20d)`() const` | 
`public const FName `[`GetEventLabel`](#classNEventInterface_1ade495738a17e98e110742533aa1752be)`() const` | 
`public void `[`SetLocalTime`](#classNEventInterface_1ac716c3624cae2ced48465c794cdb1032)`(float _LocalTime)` | 
`public void `[`SetStartedAt`](#classNEventInterface_1a072d3fb3d59e8d08dc5977c040ef390c)`(float _StartedAt)` | 
`public void `[`SetDuration`](#classNEventInterface_1a58ca8d033bf9c8e21f0efb7b003fefd2)`(float _Duration)` | 
`public void `[`SetDelay`](#classNEventInterface_1afbcb8c5728d4d4c9257e43f78684d8ea)`(float _Delay)` | 
`public void `[`SetEventLabel`](#classNEventInterface_1ab2088d15c004fa01660411f87950cfa1)`(FName _EventLabel)` | 
`public void `[`Start`](#classNEventInterface_1ab1ab56c02ce79c35c0c3d0acdad4e95b)`(float StartTime)` | 
`public void `[`NotifyAddTime`](#classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e)`(float NewTime)` | 
`public void `[`Clear`](#classNEventInterface_1a868685845638769e355b105eeefae196)`()` | 

## Members

#### `public bool `[`IsExpired`](#classNEventInterface_1afd64986f323915c61ae5478764bde9de)`() const` <a id="classNEventInterface_1afd64986f323915c61ae5478764bde9de"></a>

#### `public const float `[`GetLocalTime`](#classNEventInterface_1a77fbebce451091c6d6dda61a74f090d7)`() const` <a id="classNEventInterface_1a77fbebce451091c6d6dda61a74f090d7"></a>

#### `public const float `[`GetStartedAt`](#classNEventInterface_1a8452276ef3bb1621b5cd3b6eb38e2591)`() const` <a id="classNEventInterface_1a8452276ef3bb1621b5cd3b6eb38e2591"></a>

#### `public float `[`GetDuration`](#classNEventInterface_1abb1b6c05e352b2dd0d8ad07401868851)`() const` <a id="classNEventInterface_1abb1b6c05e352b2dd0d8ad07401868851"></a>

#### `public float `[`GetDelay`](#classNEventInterface_1a05ad20b16c2c9a07c82821ba9424b086)`() const` <a id="classNEventInterface_1a05ad20b16c2c9a07c82821ba9424b086"></a>

#### `public const FString `[`GetUID`](#classNEventInterface_1ac3e7f334edceaff2915dfc2b2b7be20d)`() const` <a id="classNEventInterface_1ac3e7f334edceaff2915dfc2b2b7be20d"></a>

#### `public const FName `[`GetEventLabel`](#classNEventInterface_1ade495738a17e98e110742533aa1752be)`() const` <a id="classNEventInterface_1ade495738a17e98e110742533aa1752be"></a>

#### `public void `[`SetLocalTime`](#classNEventInterface_1ac716c3624cae2ced48465c794cdb1032)`(float _LocalTime)` <a id="classNEventInterface_1ac716c3624cae2ced48465c794cdb1032"></a>

#### `public void `[`SetStartedAt`](#classNEventInterface_1a072d3fb3d59e8d08dc5977c040ef390c)`(float _StartedAt)` <a id="classNEventInterface_1a072d3fb3d59e8d08dc5977c040ef390c"></a>

#### `public void `[`SetDuration`](#classNEventInterface_1a58ca8d033bf9c8e21f0efb7b003fefd2)`(float _Duration)` <a id="classNEventInterface_1a58ca8d033bf9c8e21f0efb7b003fefd2"></a>

#### `public void `[`SetDelay`](#classNEventInterface_1afbcb8c5728d4d4c9257e43f78684d8ea)`(float _Delay)` <a id="classNEventInterface_1afbcb8c5728d4d4c9257e43f78684d8ea"></a>

#### `public void `[`SetEventLabel`](#classNEventInterface_1ab2088d15c004fa01660411f87950cfa1)`(FName _EventLabel)` <a id="classNEventInterface_1ab2088d15c004fa01660411f87950cfa1"></a>

#### `public void `[`Start`](#classNEventInterface_1ab1ab56c02ce79c35c0c3d0acdad4e95b)`(float StartTime)` <a id="classNEventInterface_1ab1ab56c02ce79c35c0c3d0acdad4e95b"></a>

#### `public void `[`NotifyAddTime`](#classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e)`(float NewTime)` <a id="classNEventInterface_1adbb382a156b6da8d76c7bda9e3173b2e"></a>

#### `public void `[`Clear`](#classNEventInterface_1a868685845638769e355b105eeefae196)`()` <a id="classNEventInterface_1a868685845638769e355b105eeefae196"></a>

# class `NTimeline` <a id="classNTimeline"></a>

```
class NTimeline
  : public NTimelineInterface
```  

Its goal is to saved events and place them in time. It works as a Time & Event container. The [NTimelineManager](#classNTimelineManager) class is dedicated to handle it.

**See also**: ./TimelineManager.h

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FEventDelegate `[`EventExpired`](#classNTimeline_1a52680c1a036e791bb2249892f97419a6) | **See also**: [OnExpired()](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)
`public  `[`NTimeline`](#classNTimeline_1a0b11124c2e2f3776869bf5231c3a8f42)`(`[`NTimelineManager`](#classNTimelineManager)` * TimerManager,FName _Label)` | A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.
`public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` | Calls [Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
`public virtual bool `[`Attached`](#classNTimeline_1a0fbf5c029b007c777168dd0f035a550c)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | It creates a FEventTuple and calls [BeforeOnAttached()](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b) to checks if it can be attached and [AfterOnAttached()](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b) for any custom usages
`public virtual void `[`Attached`](#classNTimeline_1ae29d93c36d89df8113a74757bc106f52)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | Same as [Attached(TSharedPtr<NEventInterface> Event)](#classNTimeline_1a0fbf5c029b007c777168dd0f035a550c) but for a collection of objects.
`public virtual void `[`SetTickInterval`](#classNTimeline_1af4782d4a0bb4b13d2bce2684e9bdf539)`(float _TickInterval)` | This should be called only by its friend [NTimelineManager](#classNTimelineManager) or a decorator to maintain consistency with its manager.
`public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` | This method is mainly used for savegame serialization
`public virtual float `[`GetCurrentTime`](#classNTimeline_1af27e09d598d6d5b47980983040142ee9)`() const` | Get CurrentTime
`public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` | Returns the FEventTuple collection
`public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` | Give a name to this timeline 
`public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` | Return the actual name
`public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4)` Tuple)` | This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a0fbf5c029b007c777168dd0f035a550c) methods to set data during runtime.
`public virtual void `[`Clear`](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)`()` | This completely reset every events. It should be used with caution.
`public virtual void `[`NotifyTick`](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c)`()` | This manages to notify every events saved in this timeline with the new time added. It uses internally [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) to increment time.
`protected FName `[`Label`](#classNTimeline_1a008f3afba683e14f05887e4df108c260) | The name of this timeline
`protected float `[`TickInterval`](#classNTimeline_1a2d3ccd44aefb61bd3eb793d5d7c31421) | Tick interval, should be set by its manager
`protected float `[`CurrentTime`](#classNTimeline_1aca3e3a5c49472abf26cc4a10da25e740) | It is computed internally in the [NotifyTick()](#classNTimeline_1ad5766056b3fdac5e80a7118100c78e0c) method. In every tick it adds [GetTickInterval()](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417) return.
`protected inline  `[`NTimeline`](#classNTimeline_1a6143741ff06add02f22ee82e5f1b6147)`()` | This to allow inherited adapters to have a default constructor
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` | In case of specialisation needs to avoid the attach process in some cases
`protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` | If needed to make some stats, analytics, trigger error,...
`protected virtual const float `[`GetTickInterval`](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417)`() const` | This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.
`protected virtual void `[`OnExpired`](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` | Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference
`typedef `[`FEventTuple`](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4) | An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time

## Members

#### `public FEventDelegate `[`EventExpired`](#classNTimeline_1a52680c1a036e791bb2249892f97419a6) <a id="classNTimeline_1a52680c1a036e791bb2249892f97419a6"></a>

**See also**: [OnExpired()](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)

#### `public  `[`NTimeline`](#classNTimeline_1a0b11124c2e2f3776869bf5231c3a8f42)`(`[`NTimelineManager`](#classNTimelineManager)` * TimerManager,FName _Label)` <a id="classNTimeline_1a0b11124c2e2f3776869bf5231c3a8f42"></a>

A Timeline can't exists with a manager. This contructor garanties the necessary coupling & behavior consistancy.

#### Parameters
* `TimerManager` - Timer which manage all time behavior (tick, pause, stop, play,...) 

* `_Label` - (optionnal) The name of this timeline. If not provided it creates a name with a static incremented value.

#### `public virtual  `[`~NTimeline`](#classNTimeline_1adffcefb7fc7f2768021994f8730eb356)`()` <a id="classNTimeline_1adffcefb7fc7f2768021994f8730eb356"></a>

Calls [Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

#### `public virtual bool `[`Attached`](#classNTimeline_1a0fbf5c029b007c777168dd0f035a550c)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classNTimeline_1a0fbf5c029b007c777168dd0f035a550c"></a>

It creates a FEventTuple and calls [BeforeOnAttached()](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b) to checks if it can be attached and [AfterOnAttached()](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b) for any custom usages

#### Parameters
* `Event` - The event you want to put in the timeline stream

#### `public virtual void `[`Attached`](#classNTimeline_1ae29d93c36d89df8113a74757bc106f52)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classNTimeline_1ae29d93c36d89df8113a74757bc106f52"></a>

Same as [Attached(TSharedPtr<NEventInterface> Event)](#classNTimeline_1a0fbf5c029b007c777168dd0f035a550c) but for a collection of objects.

#### `public virtual void `[`SetTickInterval`](#classNTimeline_1af4782d4a0bb4b13d2bce2684e9bdf539)`(float _TickInterval)` <a id="classNTimeline_1af4782d4a0bb4b13d2bce2684e9bdf539"></a>

This should be called only by its friend [NTimelineManager](#classNTimelineManager) or a decorator to maintain consistency with its manager.

#### `public virtual void `[`SetCurrentTime`](#classNTimeline_1a0411bf651e453dd5446074b11829654d)`(float _CurrentTime)` <a id="classNTimeline_1a0411bf651e453dd5446074b11829654d"></a>

This method is mainly used for savegame serialization

#### `public virtual float `[`GetCurrentTime`](#classNTimeline_1af27e09d598d6d5b47980983040142ee9)`() const` <a id="classNTimeline_1af27e09d598d6d5b47980983040142ee9"></a>

Get CurrentTime

#### `public const TArray< `[`NTimeline::FEventTuple`](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4)` > `[`GetEvents`](#classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6)`() const` <a id="classNTimeline_1abf7ab8d1d90f06c80097ef760ed1d5b6"></a>

Returns the FEventTuple collection

#### `public virtual void `[`SetLabel`](#classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153)`(FName _Label)` <a id="classNTimeline_1a059eca9a31a3ad6abd9e9b9b057ac153"></a>

Give a name to this timeline 
#### Parameters
* `_Label` - The name

#### `public virtual FName `[`GetLabel`](#classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25)`() const` <a id="classNTimeline_1a8516a8cac69ee9f96ad1c9ea4864ea25"></a>

Return the actual name

#### `public void `[`SetTuple`](#classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec)`(`[`NTimeline::FEventTuple`](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4)` Tuple)` <a id="classNTimeline_1aac29e19f74a9c983da3be8c9d68461ec"></a>

This should be used only to set data from an archive (save game). Prefer [NTimeline::Attached()](#classNTimeline_1a0fbf5c029b007c777168dd0f035a550c) methods to set data during runtime.

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

#### `protected inline virtual bool `[`BeforeOnAttached`](#classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` <a id="classNTimeline_1a4321b628067c1b3796b5a465d1ca0a8b"></a>

In case of specialisation needs to avoid the attach process in some cases

#### `protected inline virtual void `[`AfterOnAttached`](#classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float AttachedTime)` <a id="classNTimeline_1a58a67d0b0d36e4bb8222b3ae10a2342b"></a>

If needed to make some stats, analytics, trigger error,...

#### `protected virtual const float `[`GetTickInterval`](#classNTimeline_1a7c0dc7947a2f271fe68020d322fca417)`() const` <a id="classNTimeline_1a7c0dc7947a2f271fe68020d322fca417"></a>

This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.

#### `protected virtual void `[`OnExpired`](#classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classNTimeline_1a0d9dd0276af8afabfea4c049f4395b78"></a>

Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference

#### `typedef `[`FEventTuple`](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4) <a id="classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4"></a>

An event tuple is an event representation, it allows to keep important details trace in memory. 0: Event object 1: attached time 2: delay 3: duration 4: label 5: expired time

# class `NTimelineInterface` <a id="classNTimelineInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`Attached`](#classNTimelineInterface_1ae3db05abf80375c1e458958331fea033)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | 
`public void `[`Attached`](#classNTimelineInterface_1a3abcd5e2d2218a7269f6864aa8a7cb08)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | 
`public void `[`SetTickInterval`](#classNTimelineInterface_1ad894c4e8cacecfe46c861afbb4579f0a)`(float _TickInterval)` | 
`public void `[`SetCurrentTime`](#classNTimelineInterface_1ae3bcfd2792a53b0e254b32b857b9d404)`(float _CurrentTime)` | 
`public float `[`GetCurrentTime`](#classNTimelineInterface_1a9a821c703f10f5b2865bd7c5302c8661)`() const` | 
`public void `[`SetLabel`](#classNTimelineInterface_1a88b958f47721634befa5a5118fa87a02)`(FName _Label)` | 
`public FName `[`GetLabel`](#classNTimelineInterface_1a78a95ae2a1104409553fe3ed30a56e10)`() const` | 
`public void `[`Clear`](#classNTimelineInterface_1a5de152382b1e669f1a994e910c406643)`()` | 
`public void `[`NotifyTick`](#classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3)`()` | 

## Members

#### `public bool `[`Attached`](#classNTimelineInterface_1ae3db05abf80375c1e458958331fea033)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classNTimelineInterface_1ae3db05abf80375c1e458958331fea033"></a>

#### `public void `[`Attached`](#classNTimelineInterface_1a3abcd5e2d2218a7269f6864aa8a7cb08)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classNTimelineInterface_1a3abcd5e2d2218a7269f6864aa8a7cb08"></a>

#### `public void `[`SetTickInterval`](#classNTimelineInterface_1ad894c4e8cacecfe46c861afbb4579f0a)`(float _TickInterval)` <a id="classNTimelineInterface_1ad894c4e8cacecfe46c861afbb4579f0a"></a>

#### `public void `[`SetCurrentTime`](#classNTimelineInterface_1ae3bcfd2792a53b0e254b32b857b9d404)`(float _CurrentTime)` <a id="classNTimelineInterface_1ae3bcfd2792a53b0e254b32b857b9d404"></a>

#### `public float `[`GetCurrentTime`](#classNTimelineInterface_1a9a821c703f10f5b2865bd7c5302c8661)`() const` <a id="classNTimelineInterface_1a9a821c703f10f5b2865bd7c5302c8661"></a>

#### `public void `[`SetLabel`](#classNTimelineInterface_1a88b958f47721634befa5a5118fa87a02)`(FName _Label)` <a id="classNTimelineInterface_1a88b958f47721634befa5a5118fa87a02"></a>

#### `public FName `[`GetLabel`](#classNTimelineInterface_1a78a95ae2a1104409553fe3ed30a56e10)`() const` <a id="classNTimelineInterface_1a78a95ae2a1104409553fe3ed30a56e10"></a>

#### `public void `[`Clear`](#classNTimelineInterface_1a5de152382b1e669f1a994e910c406643)`()` <a id="classNTimelineInterface_1a5de152382b1e669f1a994e910c406643"></a>

#### `public void `[`NotifyTick`](#classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3)`()` <a id="classNTimelineInterface_1ab418ac5c001201d9868442f7773165c3"></a>

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
`protected virtual void `[`Clear`](#classNTimelineManager_1a337d18b7bd76ecefe59441f29f2553ab)`()` | Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
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

Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

#### `protected inline virtual void `[`onValidateTimelineTick`](#classNTimelineManager_1a1f4e4f731583060d7d0f5750795b809a)`()` <a id="classNTimelineManager_1a1f4e4f731583060d7d0f5750795b809a"></a>

This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.

#### `protected inline virtual void `[`onNotifyTimelineTickBefore`](#classNTimelineManager_1a4cfa006fae1385cce28cf61b674abe0d)`()` <a id="classNTimelineManager_1a4cfa006fae1385cce28cf61b674abe0d"></a>

This method is call immediately before ticking

#### `protected inline virtual void `[`onNotifyTimelineTickAfter`](#classNTimelineManager_1a499e7d4d685b91d3697bac9953e88268)`()` <a id="classNTimelineManager_1a499e7d4d685b91d3697bac9953e88268"></a>

This method is call immediately after ticking

# class `NTimelineManagerFake` <a id="classNTimelineManagerFake"></a>

```
class NTimelineManagerFake
  : public NTimelineManager
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
`public virtual bool `[`IsExpired`](#classNUnrealEventProxy_1a2ab770fdaf8a2e66adf4128be813d157)`() const` | 
`public virtual const float `[`GetLocalTime`](#classNUnrealEventProxy_1aab01b11713feaadebf3b841254626e43)`() const` | 
`public virtual const float `[`GetStartedAt`](#classNUnrealEventProxy_1ada79157425ac4d78d3bae4823357ce89)`() const` | 
`public virtual float `[`GetDuration`](#classNUnrealEventProxy_1a7556392cdbdaf35ed0b09c9910b3a187)`() const` | 
`public virtual void `[`Start`](#classNUnrealEventProxy_1a03e4aa3c7b41f9d40d028215b25aa04d)`(float StartTime)` | 
`public virtual void `[`NotifyAddTime`](#classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345)`(float NewTime)` | 
`public virtual float `[`GetDelay`](#classNUnrealEventProxy_1a2677f3f63bc2282827a226d7c7a840ab)`() const` | 
`public virtual const FName `[`GetEventLabel`](#classNUnrealEventProxy_1ac23e8b1279065e45016d8f5d6040a24b)`() const` | 
`public virtual const FString `[`GetUID`](#classNUnrealEventProxy_1a6a405f4dfcc52bcb41b46c127214083a)`() const` | 
`public virtual void `[`SetLocalTime`](#classNUnrealEventProxy_1a4592b1545ddc54090813287e78bf4259)`(float _LocalTime)` | 
`public virtual void `[`SetStartedAt`](#classNUnrealEventProxy_1a5af78086c9576e90c72e411a5736e8b6)`(float _StartedAt)` | 
`public virtual void `[`SetDuration`](#classNUnrealEventProxy_1a2bf362638bc5bc1384e5d0c97a8ee360)`(float _Duration)` | 
`public virtual void `[`SetDelay`](#classNUnrealEventProxy_1ab9f93904bc977d1ada3b5d4669857b85)`(float _Delay)` | 
`public virtual void `[`SetEventLabel`](#classNUnrealEventProxy_1abce884ce83319b3d6c323e363fe0b7cd)`(FName _EventLabel)` | 
`public virtual void `[`Clear`](#classNUnrealEventProxy_1a9fa63a487060c3003355552552cb600a)`()` | 
`public `[`UNEventDecorator`](#classUNEventDecorator)` & `[`GetUnrealObject`](#classNUnrealEventProxy_1a195f7a860aceba0ae76c7866901b7e95)`()` | 

## Members

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` & `[`Event`](#classNUnrealEventProxy_1ae30cbb7423f945c8078b83cb47709532) <a id="classNUnrealEventProxy_1ae30cbb7423f945c8078b83cb47709532"></a>

#### `public inline  `[`NUnrealEventProxy`](#classNUnrealEventProxy_1a7d30a9a2460faa07dda4237f18cbaee5)`(`[`UNEventDecorator`](#classUNEventDecorator)` & _Event)` <a id="classNUnrealEventProxy_1a7d30a9a2460faa07dda4237f18cbaee5"></a>

#### `public virtual bool `[`IsExpired`](#classNUnrealEventProxy_1a2ab770fdaf8a2e66adf4128be813d157)`() const` <a id="classNUnrealEventProxy_1a2ab770fdaf8a2e66adf4128be813d157"></a>

#### `public virtual const float `[`GetLocalTime`](#classNUnrealEventProxy_1aab01b11713feaadebf3b841254626e43)`() const` <a id="classNUnrealEventProxy_1aab01b11713feaadebf3b841254626e43"></a>

#### `public virtual const float `[`GetStartedAt`](#classNUnrealEventProxy_1ada79157425ac4d78d3bae4823357ce89)`() const` <a id="classNUnrealEventProxy_1ada79157425ac4d78d3bae4823357ce89"></a>

#### `public virtual float `[`GetDuration`](#classNUnrealEventProxy_1a7556392cdbdaf35ed0b09c9910b3a187)`() const` <a id="classNUnrealEventProxy_1a7556392cdbdaf35ed0b09c9910b3a187"></a>

#### `public virtual void `[`Start`](#classNUnrealEventProxy_1a03e4aa3c7b41f9d40d028215b25aa04d)`(float StartTime)` <a id="classNUnrealEventProxy_1a03e4aa3c7b41f9d40d028215b25aa04d"></a>

#### `public virtual void `[`NotifyAddTime`](#classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345)`(float NewTime)` <a id="classNUnrealEventProxy_1aebef80d18a8920af0d766695e6276345"></a>

#### `public virtual float `[`GetDelay`](#classNUnrealEventProxy_1a2677f3f63bc2282827a226d7c7a840ab)`() const` <a id="classNUnrealEventProxy_1a2677f3f63bc2282827a226d7c7a840ab"></a>

#### `public virtual const FName `[`GetEventLabel`](#classNUnrealEventProxy_1ac23e8b1279065e45016d8f5d6040a24b)`() const` <a id="classNUnrealEventProxy_1ac23e8b1279065e45016d8f5d6040a24b"></a>

#### `public virtual const FString `[`GetUID`](#classNUnrealEventProxy_1a6a405f4dfcc52bcb41b46c127214083a)`() const` <a id="classNUnrealEventProxy_1a6a405f4dfcc52bcb41b46c127214083a"></a>

#### `public virtual void `[`SetLocalTime`](#classNUnrealEventProxy_1a4592b1545ddc54090813287e78bf4259)`(float _LocalTime)` <a id="classNUnrealEventProxy_1a4592b1545ddc54090813287e78bf4259"></a>

#### `public virtual void `[`SetStartedAt`](#classNUnrealEventProxy_1a5af78086c9576e90c72e411a5736e8b6)`(float _StartedAt)` <a id="classNUnrealEventProxy_1a5af78086c9576e90c72e411a5736e8b6"></a>

#### `public virtual void `[`SetDuration`](#classNUnrealEventProxy_1a2bf362638bc5bc1384e5d0c97a8ee360)`(float _Duration)` <a id="classNUnrealEventProxy_1a2bf362638bc5bc1384e5d0c97a8ee360"></a>

#### `public virtual void `[`SetDelay`](#classNUnrealEventProxy_1ab9f93904bc977d1ada3b5d4669857b85)`(float _Delay)` <a id="classNUnrealEventProxy_1ab9f93904bc977d1ada3b5d4669857b85"></a>

#### `public virtual void `[`SetEventLabel`](#classNUnrealEventProxy_1abce884ce83319b3d6c323e363fe0b7cd)`(FName _EventLabel)` <a id="classNUnrealEventProxy_1abce884ce83319b3d6c323e363fe0b7cd"></a>

#### `public virtual void `[`Clear`](#classNUnrealEventProxy_1a9fa63a487060c3003355552552cb600a)`()` <a id="classNUnrealEventProxy_1a9fa63a487060c3003355552552cb600a"></a>

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
`public virtual bool `[`Attached`](#classNUnrealTimelineProxy_1a5f87631c37cdcba6b8bdc359b5f1a6b5)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | 
`public virtual void `[`Attached`](#classNUnrealTimelineProxy_1aedddc222f0aef97ce80df43d295c67a7)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | 
`public virtual void `[`SetTickInterval`](#classNUnrealTimelineProxy_1a34e36b80dbcdd43682447670c07df295)`(float _TickInterval)` | 
`public virtual void `[`SetCurrentTime`](#classNUnrealTimelineProxy_1ab2659e648dc0c4411bb3a4a389081ed3)`(float _CurrentTime)` | 
`public virtual float `[`GetCurrentTime`](#classNUnrealTimelineProxy_1ad9f56c6070ccaa4958dd5ea3289dc210)`() const` | 
`public virtual void `[`SetLabel`](#classNUnrealTimelineProxy_1adf1c8d680d112638c45b0f3476ca19c1)`(FName _Label)` | 
`public virtual FName `[`GetLabel`](#classNUnrealTimelineProxy_1ae525709779b518b085a3dd77a0317617)`() const` | 
`public virtual void `[`Clear`](#classNUnrealTimelineProxy_1a06aaedc689ba6d694900e7ee619b06be)`()` | 
`public virtual void `[`NotifyTick`](#classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be)`()` | 

## Members

#### `public `[`UNTimelineDecorator`](#classUNTimelineDecorator)` & `[`Timeline`](#classNUnrealTimelineProxy_1a40f55d7cc326c9e6b663f6bbb1648ced) <a id="classNUnrealTimelineProxy_1a40f55d7cc326c9e6b663f6bbb1648ced"></a>

#### `public inline  `[`NUnrealTimelineProxy`](#classNUnrealTimelineProxy_1a7e885e1d821260b1da07b38ea5c2410b)`(`[`UNTimelineDecorator`](#classUNTimelineDecorator)` & _Timeline)` <a id="classNUnrealTimelineProxy_1a7e885e1d821260b1da07b38ea5c2410b"></a>

#### `public virtual bool `[`Attached`](#classNUnrealTimelineProxy_1a5f87631c37cdcba6b8bdc359b5f1a6b5)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classNUnrealTimelineProxy_1a5f87631c37cdcba6b8bdc359b5f1a6b5"></a>

#### `public virtual void `[`Attached`](#classNUnrealTimelineProxy_1aedddc222f0aef97ce80df43d295c67a7)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classNUnrealTimelineProxy_1aedddc222f0aef97ce80df43d295c67a7"></a>

#### `public virtual void `[`SetTickInterval`](#classNUnrealTimelineProxy_1a34e36b80dbcdd43682447670c07df295)`(float _TickInterval)` <a id="classNUnrealTimelineProxy_1a34e36b80dbcdd43682447670c07df295"></a>

#### `public virtual void `[`SetCurrentTime`](#classNUnrealTimelineProxy_1ab2659e648dc0c4411bb3a4a389081ed3)`(float _CurrentTime)` <a id="classNUnrealTimelineProxy_1ab2659e648dc0c4411bb3a4a389081ed3"></a>

#### `public virtual float `[`GetCurrentTime`](#classNUnrealTimelineProxy_1ad9f56c6070ccaa4958dd5ea3289dc210)`() const` <a id="classNUnrealTimelineProxy_1ad9f56c6070ccaa4958dd5ea3289dc210"></a>

#### `public virtual void `[`SetLabel`](#classNUnrealTimelineProxy_1adf1c8d680d112638c45b0f3476ca19c1)`(FName _Label)` <a id="classNUnrealTimelineProxy_1adf1c8d680d112638c45b0f3476ca19c1"></a>

#### `public virtual FName `[`GetLabel`](#classNUnrealTimelineProxy_1ae525709779b518b085a3dd77a0317617)`() const` <a id="classNUnrealTimelineProxy_1ae525709779b518b085a3dd77a0317617"></a>

#### `public virtual void `[`Clear`](#classNUnrealTimelineProxy_1a06aaedc689ba6d694900e7ee619b06be)`()` <a id="classNUnrealTimelineProxy_1a06aaedc689ba6d694900e7ee619b06be"></a>

#### `public virtual void `[`NotifyTick`](#classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be)`()` <a id="classNUnrealTimelineProxy_1ab6034f19bf6c86b206a60ff2bbbcf1be"></a>

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
  : public NTimelineManager
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

# class `TimelineTimerManagerFake` <a id="classTimelineTimerManagerFake"></a>

```
class TimelineTimerManagerFake
  : public NTimelineManager
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

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
`public virtual bool `[`IsExpired`](#classUNEventDecorator_1ae69c1d2dc0bd6bbe4381e0387d96ed1e)`() const` | 
`public virtual const float `[`GetLocalTime`](#classUNEventDecorator_1aa20a4fea4a15bf4e2fa1a41f303fa52e)`() const` | 
`public virtual const float `[`GetStartedAt`](#classUNEventDecorator_1a8cf74bd6fbadd256e499e4ef9094ba79)`() const` | 
`public virtual float `[`GetDuration`](#classUNEventDecorator_1a678ba817c31779c5ae2d216995337078)`() const` | 
`public virtual void `[`Start`](#classUNEventDecorator_1a7137c38ec0511ca1beabe2e4f83b641e)`(float StartTime)` | 
`public virtual void `[`NotifyAddTime`](#classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07)`(float NewTime)` | 
`public virtual float `[`GetDelay`](#classUNEventDecorator_1a33715665287b45121f2ff25514c41ef1)`() const` | 
`public virtual const FName `[`GetEventLabel`](#classUNEventDecorator_1ad88e97e6031018c0f3de2ce245341dd6)`() const` | 
`public virtual const FString `[`GetUID`](#classUNEventDecorator_1a4bddd3ceb943d396ee3d1b63e91fd08f)`() const` | 
`public virtual void `[`SetLocalTime`](#classUNEventDecorator_1a1bd2690e366d7ad871e74007c15fe07b)`(float _LocalTime)` | 
`public virtual void `[`SetStartedAt`](#classUNEventDecorator_1a669a459814f553d242bd4a105b4b6bb3)`(float _StartedAt)` | 
`public virtual void `[`SetDuration`](#classUNEventDecorator_1ade8dd2b05d490b5892aaf63991aa1e6d)`(float _Duration)` | 
`public virtual void `[`SetDelay`](#classUNEventDecorator_1a59b38b2293b9e6ac91fd1161821b8600)`(float _Delay)` | 
`public virtual void `[`SetEventLabel`](#classUNEventDecorator_1a0780498b4c684dea9487841549335167)`(FName _EventLabel)` | 
`public virtual void `[`Clear`](#classUNEventDecorator_1a6876f229d6f190d204abe89ba0847d1e)`()` | 
`public virtual void `[`BeginDestroy`](#classUNEventDecorator_1a75739f0f1ec3c9dcde05bddb93e00664)`()` | 
`public virtual void `[`Serialize`](#classUNEventDecorator_1ac1bbc6721835bf4aa992cc2e1e0ee9b7)`(FArchive & Ar)` | 
`public virtual void `[`Init`](#classUNEventDecorator_1ab8e1e00ad0cc2d47887296f217c54879)`(FName _Label)` | This is where the Core object is instanciated. You should override this to instanciate your derived core object.
`public virtual TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`GetEvent`](#classUNEventDecorator_1a289aa0372ca4512839143e84617dec47)`() const` | This is used by other decorators which need to pass the core object to their own. 
`protected TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`Event`](#classUNEventDecorator_1a0c2fe0db6d7d2eb0f837d3f5e79d875e) | The actual decorator is for this object. It shoulds be instanciate on a ctor or a dedicated init function

## Members

#### `public inline  `[`UNEventDecorator`](#classUNEventDecorator_1a863909d823063f8446d2dcf30fe8174c)`()` <a id="classUNEventDecorator_1a863909d823063f8446d2dcf30fe8174c"></a>

#### `public virtual bool `[`IsExpired`](#classUNEventDecorator_1ae69c1d2dc0bd6bbe4381e0387d96ed1e)`() const` <a id="classUNEventDecorator_1ae69c1d2dc0bd6bbe4381e0387d96ed1e"></a>

#### `public virtual const float `[`GetLocalTime`](#classUNEventDecorator_1aa20a4fea4a15bf4e2fa1a41f303fa52e)`() const` <a id="classUNEventDecorator_1aa20a4fea4a15bf4e2fa1a41f303fa52e"></a>

#### `public virtual const float `[`GetStartedAt`](#classUNEventDecorator_1a8cf74bd6fbadd256e499e4ef9094ba79)`() const` <a id="classUNEventDecorator_1a8cf74bd6fbadd256e499e4ef9094ba79"></a>

#### `public virtual float `[`GetDuration`](#classUNEventDecorator_1a678ba817c31779c5ae2d216995337078)`() const` <a id="classUNEventDecorator_1a678ba817c31779c5ae2d216995337078"></a>

#### `public virtual void `[`Start`](#classUNEventDecorator_1a7137c38ec0511ca1beabe2e4f83b641e)`(float StartTime)` <a id="classUNEventDecorator_1a7137c38ec0511ca1beabe2e4f83b641e"></a>

#### `public virtual void `[`NotifyAddTime`](#classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07)`(float NewTime)` <a id="classUNEventDecorator_1a2b36838efadbdf6b1bf77a0c2cf65e07"></a>

#### `public virtual float `[`GetDelay`](#classUNEventDecorator_1a33715665287b45121f2ff25514c41ef1)`() const` <a id="classUNEventDecorator_1a33715665287b45121f2ff25514c41ef1"></a>

#### `public virtual const FName `[`GetEventLabel`](#classUNEventDecorator_1ad88e97e6031018c0f3de2ce245341dd6)`() const` <a id="classUNEventDecorator_1ad88e97e6031018c0f3de2ce245341dd6"></a>

#### `public virtual const FString `[`GetUID`](#classUNEventDecorator_1a4bddd3ceb943d396ee3d1b63e91fd08f)`() const` <a id="classUNEventDecorator_1a4bddd3ceb943d396ee3d1b63e91fd08f"></a>

#### `public virtual void `[`SetLocalTime`](#classUNEventDecorator_1a1bd2690e366d7ad871e74007c15fe07b)`(float _LocalTime)` <a id="classUNEventDecorator_1a1bd2690e366d7ad871e74007c15fe07b"></a>

#### `public virtual void `[`SetStartedAt`](#classUNEventDecorator_1a669a459814f553d242bd4a105b4b6bb3)`(float _StartedAt)` <a id="classUNEventDecorator_1a669a459814f553d242bd4a105b4b6bb3"></a>

#### `public virtual void `[`SetDuration`](#classUNEventDecorator_1ade8dd2b05d490b5892aaf63991aa1e6d)`(float _Duration)` <a id="classUNEventDecorator_1ade8dd2b05d490b5892aaf63991aa1e6d"></a>

#### `public virtual void `[`SetDelay`](#classUNEventDecorator_1a59b38b2293b9e6ac91fd1161821b8600)`(float _Delay)` <a id="classUNEventDecorator_1a59b38b2293b9e6ac91fd1161821b8600"></a>

#### `public virtual void `[`SetEventLabel`](#classUNEventDecorator_1a0780498b4c684dea9487841549335167)`(FName _EventLabel)` <a id="classUNEventDecorator_1a0780498b4c684dea9487841549335167"></a>

#### `public virtual void `[`Clear`](#classUNEventDecorator_1a6876f229d6f190d204abe89ba0847d1e)`()` <a id="classUNEventDecorator_1a6876f229d6f190d204abe89ba0847d1e"></a>

#### `public virtual void `[`BeginDestroy`](#classUNEventDecorator_1a75739f0f1ec3c9dcde05bddb93e00664)`()` <a id="classUNEventDecorator_1a75739f0f1ec3c9dcde05bddb93e00664"></a>

#### `public virtual void `[`Serialize`](#classUNEventDecorator_1ac1bbc6721835bf4aa992cc2e1e0ee9b7)`(FArchive & Ar)` <a id="classUNEventDecorator_1ac1bbc6721835bf4aa992cc2e1e0ee9b7"></a>

#### `public virtual void `[`Init`](#classUNEventDecorator_1ab8e1e00ad0cc2d47887296f217c54879)`(FName _Label)` <a id="classUNEventDecorator_1ab8e1e00ad0cc2d47887296f217c54879"></a>

This is where the Core object is instanciated. You should override this to instanciate your derived core object.

#### `public virtual TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`GetEvent`](#classUNEventDecorator_1a289aa0372ca4512839143e84617dec47)`() const` <a id="classUNEventDecorator_1a289aa0372ca4512839143e84617dec47"></a>

This is used by other decorators which need to pass the core object to their own. 
**See also**: [UNTimelineDecorator::Attached()](#classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e)

#### `protected TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > `[`Event`](#classUNEventDecorator_1a0c2fe0db6d7d2eb0f837d3f5e79d875e) <a id="classUNEventDecorator_1a0c2fe0db6d7d2eb0f837d3f5e79d875e"></a>

The actual decorator is for this object. It shoulds be instanciate on a ctor or a dedicated init function

# class `UNEventDecoratorFake` <a id="classUNEventDecoratorFake"></a>

```
class UNEventDecoratorFake
  : public UNEventDecorator
```  

This class is used for tests only

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

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
`public virtual void `[`Clear`](#classUNGameLifeTimelineManager_1a07f948da0bdc9c6196768e9f556763a8)`()` | clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
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

clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

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
`public virtual void `[`Clear`](#classUNLevelLifeTimelineManager_1a464dbe9bdc4bd9380268f5cd71e2b897)`()` | Removes all attached events clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)
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

Removes all attached events clears timer + unbind delegate + invalidate handle. Calls [NTimeline::Clear()](#classNTimeline_1aa1c1ea88a8875507cd18f2d4464eddd8)

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
`public virtual void `[`Serialize`](#classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27)`(FArchive & Ar)` | It used to save all timelines in the EventStore, and reload them correctly.
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

It used to save all timelines in the EventStore, and reload them correctly.

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
`public virtual void `[`Clear`](#classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305)`()` | 
`public virtual void `[`SetTickInterval`](#classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d)`(float _TickInterval)` | 
`public virtual void `[`SetCurrentTime`](#classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce)`(float _CurrentTime)` | 
`public virtual float `[`GetCurrentTime`](#classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2)`() const` | 
`public virtual void `[`SetLabel`](#classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763)`(FName _Label)` | 
`public virtual FName `[`GetLabel`](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)`() const` | 
`public virtual void `[`NotifyTick`](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)`()` | 
`public inline virtual bool `[`Attached`](#classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` | This object should works only with Decorators. This method is reserved for core objects. 
`public inline virtual void `[`Attached`](#classUNTimelineDecorator_1abcf856f19c3608357de804d15d0e2689)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` | This object should works only with Decorators. This method is reserved for core objects. 
`public virtual void `[`BeginDestroy`](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3)`()` | 
`public TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`GetTimeline`](#classUNTimelineDecorator_1a18c2085acb175e91abfcebc41c706758)`() const` | 
`public virtual void `[`AddEvent`](#classUNTimelineDecorator_1a39979ad6186e008643b2e6212bd87ae9)`(`[`UNEventDecorator`](#classUNEventDecorator)` * Event)` | This method is made to work with decorators object. It will save data in the EventStore array for serialization and save game. 
`public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71)`() const` | This retrieve the EventStore
`public void `[`OnEventExpired`](#classUNTimelineDecorator_1af66a84b74f059aed26634c0a01ad6a61)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` | A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a52680c1a036e791bb2249892f97419a6). It controls the EventStore data refreshing.
`public virtual void `[`Serialize`](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9)`(FArchive & Ar)` | It used to save all events state in the EventStore, and reload them correclty.
`public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`CreateNewEvent`](#classUNTimelineDecorator_1aab2ab273fc40a076e51ef306b60fcdc7)`(TSubclassOf< `[`UNEventDecorator`](#classUNEventDecorator)` > Class,FName Name,float Duration,float Delay)` | Creates a new Event and use this timeline as the outer for this new object.
`protected TSharedPtr< `[`NTimeline`](#classNTimeline)` > `[`Timeline`](#classUNTimelineDecorator_1ae3a1e91c51313ad9fef6d787f2ee3b76) | The embeded object
`protected virtual void `[`RefreshRecordData`](#classUNTimelineDecorator_1ae631f75cbddac322ed8e59dc730ce07a)`(const int32 & Index)` | This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

## Members

#### `public inline  `[`UNTimelineDecorator`](#classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0)`()` <a id="classUNTimelineDecorator_1ac09cda631e61251a0bef283cea76d4e0"></a>

Just a default ctor for UObject paradigme

#### `public virtual void `[`Init`](#classUNTimelineDecorator_1a5875e0cd5c876f0303be703bfb3f9d52)`(`[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * TimelineManager,FName _Label)` <a id="classUNTimelineDecorator_1a5875e0cd5c876f0303be703bfb3f9d52"></a>

this method is used to instanciate the embeded [NTimeline](#classNTimeline)
#### Parameters
* `TimelineManager` - The Decorator which provide the [NTimelineManager](#classNTimelineManager) object.

#### `public virtual void `[`Clear`](#classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305)`()` <a id="classUNTimelineDecorator_1a911af71c7621d03cfba0a59cd06d9305"></a>

#### `public virtual void `[`SetTickInterval`](#classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d)`(float _TickInterval)` <a id="classUNTimelineDecorator_1aadb16c4b869dc4852c054534c687629d"></a>

#### `public virtual void `[`SetCurrentTime`](#classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce)`(float _CurrentTime)` <a id="classUNTimelineDecorator_1a1a77fe79d0d597df2685acd072b0bcce"></a>

#### `public virtual float `[`GetCurrentTime`](#classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2)`() const` <a id="classUNTimelineDecorator_1a988de26672d73d693757d0ed8238b9f2"></a>

#### `public virtual void `[`SetLabel`](#classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763)`(FName _Label)` <a id="classUNTimelineDecorator_1a3b4a02a04f013e165212abdee6ef3763"></a>

#### `public virtual FName `[`GetLabel`](#classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04)`() const` <a id="classUNTimelineDecorator_1ac1f503e58bb4cf170ce1051e303a7f04"></a>

#### `public virtual void `[`NotifyTick`](#classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414)`()` <a id="classUNTimelineDecorator_1a3744e0f81cd35114ad68f31666c1e414"></a>

#### `public inline virtual bool `[`Attached`](#classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event)` <a id="classUNTimelineDecorator_1a5614115547ec6acd75dba7dfb2f0e57e"></a>

This object should works only with Decorators. This method is reserved for core objects. 
**See also**: UNTimelineDecorator::Attached(UNEventDecorator* Event)

#### `public inline virtual void `[`Attached`](#classUNTimelineDecorator_1abcf856f19c3608357de804d15d0e2689)`(TArray< TSharedPtr< `[`NEventInterface`](#classNEventInterface)` >> EventsCollection)` <a id="classUNTimelineDecorator_1abcf856f19c3608357de804d15d0e2689"></a>

This object should works only with Decorators. This method is reserved for core objects. 
**See also**: UNTimelineDecorator::Attached(UNEventDecorator* Event)

#### `public virtual void `[`BeginDestroy`](#classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3)`()` <a id="classUNTimelineDecorator_1a239b786e67d44b466d1c1b7cb780c3b3"></a>

#### `public TSharedPtr< `[`NTimelineInterface`](#classNTimelineInterface)` > `[`GetTimeline`](#classUNTimelineDecorator_1a18c2085acb175e91abfcebc41c706758)`() const` <a id="classUNTimelineDecorator_1a18c2085acb175e91abfcebc41c706758"></a>

#### `public virtual void `[`AddEvent`](#classUNTimelineDecorator_1a39979ad6186e008643b2e6212bd87ae9)`(`[`UNEventDecorator`](#classUNEventDecorator)` * Event)` <a id="classUNTimelineDecorator_1a39979ad6186e008643b2e6212bd87ae9"></a>

This method is made to work with decorators object. It will save data in the EventStore array for serialization and save game. 
#### Parameters
* `Event` - The decorator event

#### `public const TArray< `[`FNEventRecord`](#structFNEventRecord)` > `[`GetAdaptedEvents`](#classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71)`() const` <a id="classUNTimelineDecorator_1a332145e2dc18aa14f40781aa4c090b71"></a>

This retrieve the EventStore

#### `public void `[`OnEventExpired`](#classUNTimelineDecorator_1af66a84b74f059aed26634c0a01ad6a61)`(TSharedPtr< `[`NEventInterface`](#classNEventInterface)` > Event,const float & ExpiredTime,const int32 & Index)` <a id="classUNTimelineDecorator_1af66a84b74f059aed26634c0a01ad6a61"></a>

A delegate attached to [NTimeline::EventExpired](#classNTimeline_1a52680c1a036e791bb2249892f97419a6). It controls the EventStore data refreshing.

#### Parameters
* `Event` - The native Event which will be killed 

* `ExpiredTime` - The time when this event expires 

* `Index` - The index of the NTimeline::Events array

#### `public virtual void `[`Serialize`](#classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9)`(FArchive & Ar)` <a id="classUNTimelineDecorator_1a80be4f38003a75be5296f1fae4720dd9"></a>

It used to save all events state in the EventStore, and reload them correclty.

#### Parameters
* `Ar` - Archive for save and load

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

This goal is to synchronize a [NTimeline::FEventTuple](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4) with is associated [FNEventRecord](#structFNEventRecord). It checks coherence with Tuple Event and Record Event before doing it.

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

This is the abstract decorator that every Timeline manager shoulds override. It brings all core functionnalities for blueprint or c++.

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

This struct is both a pass-through for [NTimeline::FEventTuple](#classNTimeline_1a9c84d07b1a46de333b43ebd79ced4aa4) and a record object used for savegame.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`Event`](#structFNEventRecord_1a26e0a371b63a69727963bae05415c4b6) | The [UNEventDecorator](#classUNEventDecorator) object
`public float `[`AttachedTime`](#structFNEventRecord_1aa0ee04d0933a7f61e76f65097e03a63d) | The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt)
`public float `[`Delay`](#structFNEventRecord_1a93060a69818f28c533e913e0f6f6c6dc) | The delay before starting in secs
`public float `[`Duration`](#structFNEventRecord_1a1678e0c5820aff90fc32e45bad7a2afe) | The duration this event lives in secs (0 means inderterminate)
`public FName `[`Label`](#structFNEventRecord_1a87eae2eb09b8c2163a8394431ed2abf5) | The name of the event
`public float `[`ExpiredTime`](#structFNEventRecord_1a86eb7e67a45918b2da35f1a44c24815d) | Expiration time of this event in secs (0 means can't expired))
`public FString `[`EventClassName`](#structFNEventRecord_1a5ebb6654bd18ffe427e104f74fd9ba93) | This is used only for serialization, it allow to re-instance the object on load
`public inline  `[`FNEventRecord`](#structFNEventRecord_1a910e08d553b4f854ba60458cfd14064d)`()` | 
`public inline  `[`FNEventRecord`](#structFNEventRecord_1ab5b7184a999984c38050b6f556836359)`(`[`UNEventDecorator`](#classUNEventDecorator)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` | 
`public void `[`Serialize`](#structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4)`(FArchive & Ar,`[`UNTimelineDecorator`](#classUNTimelineDecorator)` * Timeline)` | It manages Event object saving and loading

## Members

#### `public `[`UNEventDecorator`](#classUNEventDecorator)` * `[`Event`](#structFNEventRecord_1a26e0a371b63a69727963bae05415c4b6) <a id="structFNEventRecord_1a26e0a371b63a69727963bae05415c4b6"></a>

The [UNEventDecorator](#classUNEventDecorator) object

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

#### `public inline  `[`FNEventRecord`](#structFNEventRecord_1ab5b7184a999984c38050b6f556836359)`(`[`UNEventDecorator`](#classUNEventDecorator)` * _Event,float _AttachedTime,float _Delay,float _Duration,FName _Label,float _ExpiredTime)` <a id="structFNEventRecord_1ab5b7184a999984c38050b6f556836359"></a>

#### `public void `[`Serialize`](#structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4)`(FArchive & Ar,`[`UNTimelineDecorator`](#classUNTimelineDecorator)` * Timeline)` <a id="structFNEventRecord_1a5f0d5e581132f6e94b1c1dca10e486f4"></a>

It manages Event object saving and loading

# struct `FTimelineNameProperty` <a id="structFTimelineNameProperty"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`TimelineName`](#structFTimelineNameProperty_1a1230f076c5216894d0a6bf5d2f210394) | 

## Members

#### `public FName `[`TimelineName`](#structFTimelineNameProperty_1a1230f076c5216894d0a6bf5d2f210394) <a id="structFTimelineNameProperty_1a1230f076c5216894d0a6bf5d2f210394"></a>

Generated by [Moxygen](https://sourcey.com/moxygen)