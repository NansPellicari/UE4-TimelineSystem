# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`FNTimelineManagerDecoratorFactory`](#namespaceFNTimelineManagerDecoratorFactory) | This class is a factory to managed properly [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) instantiation.
`namespace `[`UnrealBuildTool::Rules`](#namespaceUnrealBuildTool_1_1Rules) | 
`class `[`FAssetTypeActions_NEventBlueprint`](#classFAssetTypeActions__NEventBlueprint) | Allow to defined [UNEventBase](#classUNEventBase) asset and open it in blueprint editor.
`class `[`FNansTimelineSystemCommands`](#classFNansTimelineSystemCommands) | 
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | Required to create a UE4 module
`class `[`FNansTimelineSystemEdModule`](#classFNansTimelineSystemEdModule) | 
`class `[`FNansTimelineSystemStyle`](#classFNansTimelineSystemStyle) | 
`class `[`FNansTimelineSystemToolbar`](#classFNansTimelineSystemToolbar) | 
`class `[`FNansTimelineSystemUE4Module`](#classFNansTimelineSystemUE4Module) | Required to create a UE4 module
`class `[`FNConfiguredTimelineCustomization`](#classFNConfiguredTimelineCustomization) | 
`class `[`FNEvent`](#classFNEvent) | A concrete implementation basically used by [FNTimeline](#classFNTimeline)
`class `[`FNTimeline`](#classFNTimeline) | **See also**: NTimelineInterface
`class `[`FNTimelineManager`](#classFNTimelineManager) | This class is the client for the NTimelineInterface object. Its goal is to decoupled client interface with timeline management.
`class `[`FTimelinePinFactory`](#classFTimelinePinFactory) | It is fully dedicated to make our custom Pin available for the Unreal Editor Graph.
`class `[`INEvent`](#classINEvent) | An interface to manage events which can be attached to a timeline.
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`SConfiguredTimelinePin`](#classSConfiguredTimelinePin) | This class allows to create a dedicated pin to get names from [UNTimelineConfig](#classUNTimelineConfig).
`class `[`SNTimeline`](#classSNTimeline) | This widget will draw timeline and events thanks to its [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) passed in.
`class `[`SWindowTimeline`](#classSWindowTimeline) | The main window that embedded the timeline widget ([SNTimeline](#classSNTimeline)) and the timelines selector.
`class `[`UNEventBase`](#classUNEventBase) | This is only a view object used to retrieve events from blueprint.
`class `[`UNEventBaseBlueprint`](#classUNEventBaseBlueprint) | A [UNEventBaseBlueprint](#classUNEventBaseBlueprint) is essentially a specialized Blueprint whose graphs control an [UNEventBase](#classUNEventBase). The [UNEventBase](#classUNEventBase) factory should pick this for you automatically
`class `[`UNEventFactory`](#classUNEventFactory) | Allows to create a blueprint asset in the editor with default event nodes.
`class `[`UNEventGraph`](#classUNEventGraph) | A dedicated graph for [UNEventBase](#classUNEventBase) used for [UNEventBaseBlueprint](#classUNEventBaseBlueprint) creation.
`class `[`UNEventGraphSchema`](#classUNEventGraphSchema) | A dedicated graph schema for [UNEventBase](#classUNEventBase) used for [UNEventBaseBlueprint](#classUNEventBaseBlueprint) creation.
`class `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager) | This decorator is fitted to track time when player plays since the game is launched.
`class `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager) | It tracks game session but refreshes when level changed.
`class `[`UNRealLifeTimelineManager`](#classUNRealLifeTimelineManager) | It tracks realtime, it is not altered by pause or slowmo.
`class `[`UNTimelineBlueprintHelpers`](#classUNTimelineBlueprintHelpers) | A simple Blueprint Library class to manage Timeline creation.
`class `[`UNTimelineClient`](#classUNTimelineClient) | This class should be used by your GameInstance object. This object is the glue for all the timeline configuration and blueprint helpers.
`class `[`UNTimelineConfig`](#classUNTimelineConfig) | A simple configuration to ease timeline instantiation for developpers.
`class `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator) | This is the abstract decorator that every Timeline manager should override. It brings all core functionalities for blueprint or UE4 c++ paradigm.
`class `[`UTimelineGameSubsystem`](#classUTimelineGameSubsystem) | 
`struct `[`FConfiguredTimeline`](#structFConfiguredTimeline) | This struct to create Configured Timeline and ease Timeline instantiation. This allows to associated a Timeline Name to a class.
`struct `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf) | This struct to create Configured Timeline and ease Timeline instantiation. This allows to associated a Timeline Name to a class.
`struct `[`FEventSlot`](#structFEventSlot) | All details about an event to draw
`struct `[`FEventsRow`](#structFEventsRow) | Saved data when timeline are paint. 
`struct `[`FParamsEventChanged`](#structFParamsEventChanged) | 
`struct `[`FTimelineData`](#structFTimelineData) | Saved data when timeline are paint. 

# namespace `FNTimelineManagerDecoratorFactory` <a id="namespaceFNTimelineManagerDecoratorFactory"></a>

This class is a factory to managed properly [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) instantiation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public template<>`  <br/>`static T * `[`CreateObject`](#namespaceFNTimelineManagerDecoratorFactory_1a635b20a46982b89dd7bb4806bf352a41)`(UObject * Outer,const float & TickInterval,const FName & InLabel,const EObjectFlags & Flags)`            | Method to create a derived [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator).
`public template<>`  <br/>`static T * `[`CreateObject`](#namespaceFNTimelineManagerDecoratorFactory_1ab68d66e806fab177fc5cc323867c8dc1)`(UObject * Outer,const UClass * Class,const float & TickInterval,const FName & InLabel,const EObjectFlags & Flags)`            | This method is a factory method to create a derived [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) with a specific UClass.

## Members

#### `public template<>`  <br/>`static T * `[`CreateObject`](#namespaceFNTimelineManagerDecoratorFactory_1a635b20a46982b89dd7bb4806bf352a41)`(UObject * Outer,const float & TickInterval,const FName & InLabel,const EObjectFlags & Flags)` <a id="namespaceFNTimelineManagerDecoratorFactory_1a635b20a46982b89dd7bb4806bf352a41"></a>

Method to create a derived [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator).

#### Parameters
* `Outer` - The outer of the new object. 

* `TickInterval` - The interval between tick in sec 

* `InLabel` - The name of this new Timeline 

* `Flags` - The EObjectFlags for NewObject().

#### `public template<>`  <br/>`static T * `[`CreateObject`](#namespaceFNTimelineManagerDecoratorFactory_1ab68d66e806fab177fc5cc323867c8dc1)`(UObject * Outer,const UClass * Class,const float & TickInterval,const FName & InLabel,const EObjectFlags & Flags)` <a id="namespaceFNTimelineManagerDecoratorFactory_1ab68d66e806fab177fc5cc323867c8dc1"></a>

This method is a factory method to create a derived [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) with a specific UClass.

#### Parameters
* `Outer` - The outer of the new object. 

* `Class` - The specific class we want our object will be. 

* `TickInterval` - The interval between tick in sec 

* `InLabel` - The name of this new Timeline 

* `Flags` - The EObjectFlags for NewObject().

# namespace `UnrealBuildTool::Rules` <a id="namespaceUnrealBuildTool_1_1Rules"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`UnrealBuildTool::Rules::NansTimelineSystemEd`](#classUnrealBuildTool_1_1Rules_1_1NansTimelineSystemEd) | 

# class `UnrealBuildTool::Rules::NansTimelineSystemEd` <a id="classUnrealBuildTool_1_1Rules_1_1NansTimelineSystemEd"></a>

```
class UnrealBuildTool::Rules::NansTimelineSystemEd
  : public ModuleRules
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NansTimelineSystemEd`](#classUnrealBuildTool_1_1Rules_1_1NansTimelineSystemEd_1a413c3380b077138d08b887fa0e363656)`(ReadOnlyTargetRules Target)` | 

## Members

#### `public inline  `[`NansTimelineSystemEd`](#classUnrealBuildTool_1_1Rules_1_1NansTimelineSystemEd_1a413c3380b077138d08b887fa0e363656)`(ReadOnlyTargetRules Target)` <a id="classUnrealBuildTool_1_1Rules_1_1NansTimelineSystemEd_1a413c3380b077138d08b887fa0e363656"></a>

# class `FAssetTypeActions_NEventBlueprint` <a id="classFAssetTypeActions__NEventBlueprint"></a>

```
class FAssetTypeActions_NEventBlueprint
  : public FAssetTypeActions_Blueprint
```  

Allow to defined [UNEventBase](#classUNEventBase) asset and open it in blueprint editor.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual FText `[`GetName`](#classFAssetTypeActions__NEventBlueprint_1a4d517f4029293744d5bba541d6479049)`() const` | 
`public virtual FColor `[`GetTypeColor`](#classFAssetTypeActions__NEventBlueprint_1a63bfbdbacd5ceb04147a34c01eebea24)`() const` | 
`public virtual UClass * `[`GetSupportedClass`](#classFAssetTypeActions__NEventBlueprint_1a802c1a8cbebd182e6e201f82b03ce713)`() const` | 
`public virtual uint32 `[`GetCategories`](#classFAssetTypeActions__NEventBlueprint_1a7641d7f87c250c003085226b7a427553)`()` | 
`public virtual void `[`OpenAssetEditor`](#classFAssetTypeActions__NEventBlueprint_1a570b341f2926f97805f225b3fbee1246)`(const TArray< UObject * > & InObjects,TSharedPtr< IToolkitHost > EditWithinLevelEditor)` | 
`protected virtual UFactory * `[`GetFactoryForBlueprintType`](#classFAssetTypeActions__NEventBlueprint_1a95299c1c2bb25037ee23c08eacf11390)`(UBlueprint * InBlueprint) const` | 

## Members

#### `public virtual FText `[`GetName`](#classFAssetTypeActions__NEventBlueprint_1a4d517f4029293744d5bba541d6479049)`() const` <a id="classFAssetTypeActions__NEventBlueprint_1a4d517f4029293744d5bba541d6479049"></a>

#### `public virtual FColor `[`GetTypeColor`](#classFAssetTypeActions__NEventBlueprint_1a63bfbdbacd5ceb04147a34c01eebea24)`() const` <a id="classFAssetTypeActions__NEventBlueprint_1a63bfbdbacd5ceb04147a34c01eebea24"></a>

#### `public virtual UClass * `[`GetSupportedClass`](#classFAssetTypeActions__NEventBlueprint_1a802c1a8cbebd182e6e201f82b03ce713)`() const` <a id="classFAssetTypeActions__NEventBlueprint_1a802c1a8cbebd182e6e201f82b03ce713"></a>

#### `public virtual uint32 `[`GetCategories`](#classFAssetTypeActions__NEventBlueprint_1a7641d7f87c250c003085226b7a427553)`()` <a id="classFAssetTypeActions__NEventBlueprint_1a7641d7f87c250c003085226b7a427553"></a>

#### `public virtual void `[`OpenAssetEditor`](#classFAssetTypeActions__NEventBlueprint_1a570b341f2926f97805f225b3fbee1246)`(const TArray< UObject * > & InObjects,TSharedPtr< IToolkitHost > EditWithinLevelEditor)` <a id="classFAssetTypeActions__NEventBlueprint_1a570b341f2926f97805f225b3fbee1246"></a>

#### `protected virtual UFactory * `[`GetFactoryForBlueprintType`](#classFAssetTypeActions__NEventBlueprint_1a95299c1c2bb25037ee23c08eacf11390)`(UBlueprint * InBlueprint) const` <a id="classFAssetTypeActions__NEventBlueprint_1a95299c1c2bb25037ee23c08eacf11390"></a>

# class `FNansTimelineSystemCommands` <a id="classFNansTimelineSystemCommands"></a>

```
class FNansTimelineSystemCommands
  : public TCommands< FNansTimelineSystemCommands >
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSharedPtr< FUICommandInfo > `[`MyButton`](#classFNansTimelineSystemCommands_1a9fcea2c9c028fb563a18f3e293b0a044) | 
`public TSharedPtr< FUICommandInfo > `[`MyMenuButton`](#classFNansTimelineSystemCommands_1a7996f047ed738d71b6f1a3abc8ccd5e8) | 
`public inline  `[`FNansTimelineSystemCommands`](#classFNansTimelineSystemCommands_1a6f52a32a2d66ace5ae17357c1311743d)`()` | 
`public virtual void `[`RegisterCommands`](#classFNansTimelineSystemCommands_1ad5abc77eaf97ca28e2bf4692d92c85a8)`()` | 

## Members

#### `public TSharedPtr< FUICommandInfo > `[`MyButton`](#classFNansTimelineSystemCommands_1a9fcea2c9c028fb563a18f3e293b0a044) <a id="classFNansTimelineSystemCommands_1a9fcea2c9c028fb563a18f3e293b0a044"></a>

#### `public TSharedPtr< FUICommandInfo > `[`MyMenuButton`](#classFNansTimelineSystemCommands_1a7996f047ed738d71b6f1a3abc8ccd5e8) <a id="classFNansTimelineSystemCommands_1a7996f047ed738d71b6f1a3abc8ccd5e8"></a>

#### `public inline  `[`FNansTimelineSystemCommands`](#classFNansTimelineSystemCommands_1a6f52a32a2d66ace5ae17357c1311743d)`()` <a id="classFNansTimelineSystemCommands_1a6f52a32a2d66ace5ae17357c1311743d"></a>

#### `public virtual void `[`RegisterCommands`](#classFNansTimelineSystemCommands_1ad5abc77eaf97ca28e2bf4692d92c85a8)`()` <a id="classFNansTimelineSystemCommands_1ad5abc77eaf97ca28e2bf4692d92c85a8"></a>

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

# class `FNansTimelineSystemEdModule` <a id="classFNansTimelineSystemEdModule"></a>

```
class FNansTimelineSystemEdModule
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansTimelineSystemEdModule_1a49b21fe1b5a7dee0314d2cc289f07a8d)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansTimelineSystemEdModule_1a8ee1be78a281a4511196282c14af16a3)`()` | 
`protected TSharedPtr< `[`FTimelinePinFactory`](#classFTimelinePinFactory)` > `[`TimelinePinFactory`](#classFNansTimelineSystemEdModule_1a96c035595ee1f1923ff00a3108f67a9e) | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansTimelineSystemEdModule_1a49b21fe1b5a7dee0314d2cc289f07a8d)`()` <a id="classFNansTimelineSystemEdModule_1a49b21fe1b5a7dee0314d2cc289f07a8d"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansTimelineSystemEdModule_1a8ee1be78a281a4511196282c14af16a3)`()` <a id="classFNansTimelineSystemEdModule_1a8ee1be78a281a4511196282c14af16a3"></a>

#### `protected TSharedPtr< `[`FTimelinePinFactory`](#classFTimelinePinFactory)` > `[`TimelinePinFactory`](#classFNansTimelineSystemEdModule_1a96c035595ee1f1923ff00a3108f67a9e) <a id="classFNansTimelineSystemEdModule_1a96c035595ee1f1923ff00a3108f67a9e"></a>

# class `FNansTimelineSystemStyle` <a id="classFNansTimelineSystemStyle"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `FNansTimelineSystemToolbar` <a id="classFNansTimelineSystemToolbar"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`Register`](#classFNansTimelineSystemToolbar_1aee3f698b7e4080ca3963278f0b3c6952)`()` | 
`public void `[`Unregister`](#classFNansTimelineSystemToolbar_1a80c3a5baa8ce6fb179ac0baab7d21a20)`()` | 
`public void `[`MyButton_Clicked`](#classFNansTimelineSystemToolbar_1aeb1a4e40720573d93e08eb2b3e2ce6a5)`() const` | 
`public void `[`AddToolbarExtension`](#classFNansTimelineSystemToolbar_1a5040e609a1e58b856e329a5630cd3f68)`(FToolBarBuilder & builder) const` | 

## Members

#### `public void `[`Register`](#classFNansTimelineSystemToolbar_1aee3f698b7e4080ca3963278f0b3c6952)`()` <a id="classFNansTimelineSystemToolbar_1aee3f698b7e4080ca3963278f0b3c6952"></a>

#### `public void `[`Unregister`](#classFNansTimelineSystemToolbar_1a80c3a5baa8ce6fb179ac0baab7d21a20)`()` <a id="classFNansTimelineSystemToolbar_1a80c3a5baa8ce6fb179ac0baab7d21a20"></a>

#### `public void `[`MyButton_Clicked`](#classFNansTimelineSystemToolbar_1aeb1a4e40720573d93e08eb2b3e2ce6a5)`() const` <a id="classFNansTimelineSystemToolbar_1aeb1a4e40720573d93e08eb2b3e2ce6a5"></a>

#### `public void `[`AddToolbarExtension`](#classFNansTimelineSystemToolbar_1a5040e609a1e58b856e329a5630cd3f68)`(FToolBarBuilder & builder) const` <a id="classFNansTimelineSystemToolbar_1a5040e609a1e58b856e329a5630cd3f68"></a>

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

# class `FNConfiguredTimelineCustomization` <a id="classFNConfiguredTimelineCustomization"></a>

```
class FNConfiguredTimelineCustomization
  : public IPropertyTypeCustomization
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`CustomizeHeader`](#classFNConfiguredTimelineCustomization_1a6cd2880bd321f564d53268e5d436699b)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class FDetailWidgetRow & HeaderRow,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` | IPropertyTypeCustomization interface
`public virtual void `[`CustomizeChildren`](#classFNConfiguredTimelineCustomization_1aaa890957b685f2356c1ca343d98cc1ea)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class IDetailChildrenBuilder & StructBuilder,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` | 
`protected void `[`OnAttributeSelected`](#classFNConfiguredTimelineCustomization_1a08693e1bd21a7222a2fd8def00235463)`(TSharedPtr< FName > Selection,ESelectInfo::Type SelectInfo)` | 

## Members

#### `public virtual void `[`CustomizeHeader`](#classFNConfiguredTimelineCustomization_1a6cd2880bd321f564d53268e5d436699b)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class FDetailWidgetRow & HeaderRow,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` <a id="classFNConfiguredTimelineCustomization_1a6cd2880bd321f564d53268e5d436699b"></a>

IPropertyTypeCustomization interface

#### `public virtual void `[`CustomizeChildren`](#classFNConfiguredTimelineCustomization_1aaa890957b685f2356c1ca343d98cc1ea)`(TSharedRef< IPropertyHandle > StructPropertyHandle,class IDetailChildrenBuilder & StructBuilder,IPropertyTypeCustomizationUtils & StructCustomizationUtils)` <a id="classFNConfiguredTimelineCustomization_1aaa890957b685f2356c1ca343d98cc1ea"></a>

#### `protected void `[`OnAttributeSelected`](#classFNConfiguredTimelineCustomization_1a08693e1bd21a7222a2fd8def00235463)`(TSharedPtr< FName > Selection,ESelectInfo::Type SelectInfo)` <a id="classFNConfiguredTimelineCustomization_1a08693e1bd21a7222a2fd8def00235463"></a>

# class `FNEvent` <a id="classFNEvent"></a>

```
class FNEvent
  : public INEvent
```  

A concrete implementation basically used by [FNTimeline](#classFNTimeline)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`FNEvent`](#classFNEvent_1abb17247bc26322d40d0995811c4383dc)`()` | 
`public  `[`FNEvent`](#classFNEvent_1a4eaa1fa1bcdbba3b2480dad67dcae754)`(const FName & InLabel,const FString & InUId)` | Ctor to gives directly a name for this event and an Id (optional).
`public virtual bool `[`IsExpired`](#classFNEvent_1a697cddde4278f9c60dc149d181b173e9)`() const` | It indicates if the event expired.
`public virtual float `[`GetLocalTime`](#classFNEvent_1a8f7fed176c897f0e925fc6a66dd243fb)`() const` | Returns the localTime since the events has been attached (+ delay if > 0) to a timeline
`public virtual float `[`GetAttachedTime`](#classFNEvent_1a2f55c8171cc9885bd9eea917fd310acc)`() const` | The time relative to the timeline this event has been attached to.
`public virtual float `[`GetStartedAt`](#classFNEvent_1aafec0b38229705448b87b71cf42cdf6b)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public virtual float `[`GetDuration`](#classFNEvent_1a697fdce654a5c75f7a26e09dd179d2cc)`() const` | The duration this event should live
`public virtual float `[`GetDelay`](#classFNEvent_1a7027d6ee8bd99db3d4c4b96895a7d925)`() const` | The delay before this event starts
`public virtual FString `[`GetUID`](#classFNEvent_1aeb9e42151fa951667a4fb59cdfd99107)`() const` | Retrieve the unique ID generated or given in ctor
`public virtual float `[`GetExpiredTime`](#classFNEvent_1ab9761dda1888eca490d0edfb0d9b21d6)`() const` | The time relative to the timeline this event has been expired, should return -1 if this event has no duration.
`public virtual FName `[`GetEventLabel`](#classFNEvent_1a372c0b57e65e6058f957eca8eee84dbf)`() const` | Getter for Label
`public virtual bool `[`IsAttachable`](#classFNEvent_1ad1814e824813ce21f0d0c7a79b7afb50)`() const` | Timeline use this to know if this event can be attached on.
`public virtual void `[`SetEventLabel`](#classFNEvent_1af77646045222aaa9390540d5c0428bca)`(const FName & InEventLabel)` | A setter for the label. 
`public virtual void `[`SetAttachedTime`](#classFNEvent_1a8a65b6f4c99d9f46d3b297fe7872e2fd)`(const float & InLocalTime)` | Set the time this event is attached to timeline, should be used only by a [FNTimeline](#classFNTimeline).
`public virtual void `[`SetAttachable`](#classFNEvent_1a436502d2e3a45ea471ac493926fdc262)`(const bool & bInIsAttachable)` | This can be useful to avoid an Event to be attached to a timeline. 
`public virtual void `[`SetExpiredTime`](#classFNEvent_1a58b3422dc0e4f290fb430819ab88e32e)`(const float & InLocalTime)` | Set the expired time for this event. It is called by the [FNTimeline](#classFNTimeline). 
`public virtual void `[`SetDuration`](#classFNEvent_1a8bfa4519eb19be809d803e4da5fd93e2)`(const float & InDuration)` | A setter for the duration.
`public virtual void `[`SetDelay`](#classFNEvent_1a96e8b3ea40ecabb84fb508155874dcb8)`(const float & InDelay)` | A setter for the delay.
`public virtual void `[`Start`](#classFNEvent_1abcdec459fc6ef977b6139d1d442628e9)`(const float & StartTime)` | This should be used only by NTimeline or serialization.
`public virtual void `[`Stop`](#classFNEvent_1a5038a95a83e7a9bab802eb9b2b63a439)`()` | This can stop the event and make it expires to its next tick.
`public virtual void `[`AddTime`](#classFNEvent_1a84f3c65805c537cfde95b5e94c36689c)`(const float & NewTime)` | Increments LocalTime 
`public virtual void `[`Clear`](#classFNEvent_1aadee41191ba101a0fa78e106709ceb62)`()` | This should reset all data
`public virtual void `[`Archive`](#classFNEvent_1a4d2592a135c4244f11ee89472366ded4)`(FArchive & Ar)` | 
`protected FName `[`Label`](#classFNEvent_1a459d04df45a7dc744756994ce25ec5cf) | 
`protected float `[`AttachedTime`](#classFNEvent_1a9143752f6f8a81f2bc49a189ae8ea180) | 
`protected float `[`LocalTime`](#classFNEvent_1a58c81d2675c737a5d6c56f92ab2a2180) | 
`protected float `[`StartedAt`](#classFNEvent_1a53656b7c1dcb37293192174eb533881a) | 
`protected float `[`ExpiredTime`](#classFNEvent_1ad3388d91597e30800dda91a0a48d3d8e) | 
`protected float `[`Duration`](#classFNEvent_1a9257e7f323feb52a0e5b5bd86e55aa06) | 
`protected float `[`Delay`](#classFNEvent_1af4371014ad3d38c07f392bae66de0a65) | 
`protected FString `[`UId`](#classFNEvent_1a5e35799863cc179e30638ae66bf6a482) | 
`protected bool `[`bActivated`](#classFNEvent_1a94254b2e6a7362837f869a8ac6c93658) | 
`protected bool `[`bIsAttachable`](#classFNEvent_1aaf24820f6bd170abe3267b8be8693b6d) | 

## Members

#### `public  `[`FNEvent`](#classFNEvent_1abb17247bc26322d40d0995811c4383dc)`()` <a id="classFNEvent_1abb17247bc26322d40d0995811c4383dc"></a>

#### `public  `[`FNEvent`](#classFNEvent_1a4eaa1fa1bcdbba3b2480dad67dcae754)`(const FName & InLabel,const FString & InUId)` <a id="classFNEvent_1a4eaa1fa1bcdbba3b2480dad67dcae754"></a>

Ctor to gives directly a name for this event and an Id (optional).

#### `public virtual bool `[`IsExpired`](#classFNEvent_1a697cddde4278f9c60dc149d181b173e9)`() const` <a id="classFNEvent_1a697cddde4278f9c60dc149d181b173e9"></a>

It indicates if the event expired.

#### `public virtual float `[`GetLocalTime`](#classFNEvent_1a8f7fed176c897f0e925fc6a66dd243fb)`() const` <a id="classFNEvent_1a8f7fed176c897f0e925fc6a66dd243fb"></a>

Returns the localTime since the events has been attached (+ delay if > 0) to a timeline

#### `public virtual float `[`GetAttachedTime`](#classFNEvent_1a2f55c8171cc9885bd9eea917fd310acc)`() const` <a id="classFNEvent_1a2f55c8171cc9885bd9eea917fd310acc"></a>

The time relative to the timeline this event has been attached to.

#### `public virtual float `[`GetStartedAt`](#classFNEvent_1aafec0b38229705448b87b71cf42cdf6b)`() const` <a id="classFNEvent_1aafec0b38229705448b87b71cf42cdf6b"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public virtual float `[`GetDuration`](#classFNEvent_1a697fdce654a5c75f7a26e09dd179d2cc)`() const` <a id="classFNEvent_1a697fdce654a5c75f7a26e09dd179d2cc"></a>

The duration this event should live

#### `public virtual float `[`GetDelay`](#classFNEvent_1a7027d6ee8bd99db3d4c4b96895a7d925)`() const` <a id="classFNEvent_1a7027d6ee8bd99db3d4c4b96895a7d925"></a>

The delay before this event starts

#### `public virtual FString `[`GetUID`](#classFNEvent_1aeb9e42151fa951667a4fb59cdfd99107)`() const` <a id="classFNEvent_1aeb9e42151fa951667a4fb59cdfd99107"></a>

Retrieve the unique ID generated or given in ctor

#### `public virtual float `[`GetExpiredTime`](#classFNEvent_1ab9761dda1888eca490d0edfb0d9b21d6)`() const` <a id="classFNEvent_1ab9761dda1888eca490d0edfb0d9b21d6"></a>

The time relative to the timeline this event has been expired, should return -1 if this event has no duration.

#### `public virtual FName `[`GetEventLabel`](#classFNEvent_1a372c0b57e65e6058f957eca8eee84dbf)`() const` <a id="classFNEvent_1a372c0b57e65e6058f957eca8eee84dbf"></a>

Getter for Label

#### `public virtual bool `[`IsAttachable`](#classFNEvent_1ad1814e824813ce21f0d0c7a79b7afb50)`() const` <a id="classFNEvent_1ad1814e824813ce21f0d0c7a79b7afb50"></a>

Timeline use this to know if this event can be attached on.

#### `public virtual void `[`SetEventLabel`](#classFNEvent_1af77646045222aaa9390540d5c0428bca)`(const FName & InEventLabel)` <a id="classFNEvent_1af77646045222aaa9390540d5c0428bca"></a>

A setter for the label. 
#### Parameters
* `InEventLabel` - A name to identify easily the event

#### `public virtual void `[`SetAttachedTime`](#classFNEvent_1a8a65b6f4c99d9f46d3b297fe7872e2fd)`(const float & InLocalTime)` <a id="classFNEvent_1a8a65b6f4c99d9f46d3b297fe7872e2fd"></a>

Set the time this event is attached to timeline, should be used only by a [FNTimeline](#classFNTimeline).

#### `public virtual void `[`SetAttachable`](#classFNEvent_1a436502d2e3a45ea471ac493926fdc262)`(const bool & bInIsAttachable)` <a id="classFNEvent_1a436502d2e3a45ea471ac493926fdc262"></a>

This can be useful to avoid an Event to be attached to a timeline. 
**See also**: [FNTimeline::Attached()](#classFNTimeline_1acac6e8fa7780e7d612e601cd0d479bf3)

**See also**: [ENTimelineEvent::BeforeAttached](#Timeline_8h_1aca8212740df4678d46efc8cae12ab0c9ab0b87ce0c6e7571ffbd0f6408c4539be)

#### Parameters
* `bInIsAttachable` - boolean to defined is attachable capability

#### `public virtual void `[`SetExpiredTime`](#classFNEvent_1a58b3422dc0e4f290fb430819ab88e32e)`(const float & InLocalTime)` <a id="classFNEvent_1a58b3422dc0e4f290fb430819ab88e32e"></a>

Set the expired time for this event. It is called by the [FNTimeline](#classFNTimeline). 
#### Parameters
* `InLocalTime` - the time relative to the timeline

#### `public virtual void `[`SetDuration`](#classFNEvent_1a8bfa4519eb19be809d803e4da5fd93e2)`(const float & InDuration)` <a id="classFNEvent_1a8bfa4519eb19be809d803e4da5fd93e2"></a>

A setter for the duration.

#### Parameters
* `InDuration` - Time in secs

#### `public virtual void `[`SetDelay`](#classFNEvent_1a96e8b3ea40ecabb84fb508155874dcb8)`(const float & InDelay)` <a id="classFNEvent_1a96e8b3ea40ecabb84fb508155874dcb8"></a>

A setter for the delay.

#### Parameters
* `InDelay` - Time in secs

#### `public virtual void `[`Start`](#classFNEvent_1abcdec459fc6ef977b6139d1d442628e9)`(const float & StartTime)` <a id="classFNEvent_1abcdec459fc6ef977b6139d1d442628e9"></a>

This should be used only by NTimeline or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public virtual void `[`Stop`](#classFNEvent_1a5038a95a83e7a9bab802eb9b2b63a439)`()` <a id="classFNEvent_1a5038a95a83e7a9bab802eb9b2b63a439"></a>

This can stop the event and make it expires to its next tick.

#### `public virtual void `[`AddTime`](#classFNEvent_1a84f3c65805c537cfde95b5e94c36689c)`(const float & NewTime)` <a id="classFNEvent_1a84f3c65805c537cfde95b5e94c36689c"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Milliseconds

#### `public virtual void `[`Clear`](#classFNEvent_1aadee41191ba101a0fa78e106709ceb62)`()` <a id="classFNEvent_1aadee41191ba101a0fa78e106709ceb62"></a>

This should reset all data

#### `public virtual void `[`Archive`](#classFNEvent_1a4d2592a135c4244f11ee89472366ded4)`(FArchive & Ar)` <a id="classFNEvent_1a4d2592a135c4244f11ee89472366ded4"></a>

#### `protected FName `[`Label`](#classFNEvent_1a459d04df45a7dc744756994ce25ec5cf) <a id="classFNEvent_1a459d04df45a7dc744756994ce25ec5cf"></a>

#### `protected float `[`AttachedTime`](#classFNEvent_1a9143752f6f8a81f2bc49a189ae8ea180) <a id="classFNEvent_1a9143752f6f8a81f2bc49a189ae8ea180"></a>

#### `protected float `[`LocalTime`](#classFNEvent_1a58c81d2675c737a5d6c56f92ab2a2180) <a id="classFNEvent_1a58c81d2675c737a5d6c56f92ab2a2180"></a>

#### `protected float `[`StartedAt`](#classFNEvent_1a53656b7c1dcb37293192174eb533881a) <a id="classFNEvent_1a53656b7c1dcb37293192174eb533881a"></a>

#### `protected float `[`ExpiredTime`](#classFNEvent_1ad3388d91597e30800dda91a0a48d3d8e) <a id="classFNEvent_1ad3388d91597e30800dda91a0a48d3d8e"></a>

#### `protected float `[`Duration`](#classFNEvent_1a9257e7f323feb52a0e5b5bd86e55aa06) <a id="classFNEvent_1a9257e7f323feb52a0e5b5bd86e55aa06"></a>

#### `protected float `[`Delay`](#classFNEvent_1af4371014ad3d38c07f392bae66de0a65) <a id="classFNEvent_1af4371014ad3d38c07f392bae66de0a65"></a>

#### `protected FString `[`UId`](#classFNEvent_1a5e35799863cc179e30638ae66bf6a482) <a id="classFNEvent_1a5e35799863cc179e30638ae66bf6a482"></a>

#### `protected bool `[`bActivated`](#classFNEvent_1a94254b2e6a7362837f869a8ac6c93658) <a id="classFNEvent_1a94254b2e6a7362837f869a8ac6c93658"></a>

#### `protected bool `[`bIsAttachable`](#classFNEvent_1aaf24820f6bd170abe3267b8be8693b6d) <a id="classFNEvent_1aaf24820f6bd170abe3267b8be8693b6d"></a>

# class `FNTimeline` <a id="classFNTimeline"></a>

**See also**: NTimelineInterface

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`FNTimeline`](#classFNTimeline_1a292eed4c83e4c12341b00e240133fa91)`()` | 
`public  `[`FNTimeline`](#classFNTimeline_1aac1361e887fe554f1b82f5dc84c266b7)`(const FName & InLabel)` | #### Parameters
`public  `[`~FNTimeline`](#classFNTimeline_1a575d6c7980276a7a3a2ac9f83d1abc81)`()` | Empty events array
`public bool `[`Attached`](#classFNTimeline_1acac6e8fa7780e7d612e601cd0d479bf3)`(const TSharedPtr< `[`INEvent`](#classINEvent)` > & Event)` | Attached an event to this timeline. It creates a FEventTuple and calls BeforeOnAttached() to checks if it can be attached and AfterOnAttached() for any custom usages
`public void `[`Attached`](#classFNTimeline_1ab0985b3570e72bd3666ed0b3d8c34eba)`(const TArray< TSharedPtr< `[`INEvent`](#classINEvent)` >> & EventsCollection)` | Same as Attached(TSharedPtr<INEvent> Event) but for a collection of objects.
`public float `[`GetTickInterval`](#classFNTimeline_1a62d57ea19cb8ad1787ddc91bc32f20bb)`() const` | This is the value required by a timer manager to know the tick frequency for this timeline (given by NTimelineManager). The NotifyTick use this method to add time on CurrentTime at each call.
`public float `[`GetCurrentTime`](#classFNTimeline_1a4aba63a32699e29b9e13df41c910cedf)`() const` | Retrieve the current time since this timeline exists and play
`public void `[`SetLabel`](#classFNTimeline_1a423302167b09a6aa88872110f46171e3)`(const FName & InLabel)` | Give a name to this timeline 
`public FName `[`GetLabel`](#classFNTimeline_1aa3479c309f3e4656f70f7c40175a9e59)`() const` | Return the actual name
`public void `[`Clear`](#classFNTimeline_1a0007252237785f91de61d32339382436)`()` | This completely reset every events. It should be used with caution.
`public void `[`Archive`](#classFNTimeline_1aa196425dd62d2e2745643f6ded78e1a1)`(FArchive & Ar)` | Offer the opportunities to save data in a binary object. 
`public TArray< TSharedPtr< `[`INEvent`](#classINEvent)` > > `[`GetEvents`](#classFNTimeline_1aa52a754759c0d6cf7ef5d63149755144)`() const` | #### Returns
`public TArray< TSharedPtr< `[`INEvent`](#classINEvent)` > > `[`GetExpiredEvents`](#classFNTimeline_1aaee25bde92af142eb632d73286edc32c)`() const` | #### Returns
`public TSharedPtr< `[`INEvent`](#classINEvent)` > `[`GetEvent`](#classFNTimeline_1a078b26a2c213c1a351ebc12e95ae6c1f)`(const FString & InUID) const` | Get an event by its UID 
`public TSharedPtr< `[`INEvent`](#classINEvent)` > `[`GetExpiredEvent`](#classFNTimeline_1a7e731705a5bb40eb36fdd69ea7807afa)`(const FString & InUID) const` | Get an event by its UID 

## Members

#### `public  `[`FNTimeline`](#classFNTimeline_1a292eed4c83e4c12341b00e240133fa91)`()` <a id="classFNTimeline_1a292eed4c83e4c12341b00e240133fa91"></a>

#### `public  `[`FNTimeline`](#classFNTimeline_1aac1361e887fe554f1b82f5dc84c266b7)`(const FName & InLabel)` <a id="classFNTimeline_1aac1361e887fe554f1b82f5dc84c266b7"></a>

#### Parameters
* `InLabel` - (optional) The name of this timeline. If not provided it creates a name with a static incremented value.

#### `public  `[`~FNTimeline`](#classFNTimeline_1a575d6c7980276a7a3a2ac9f83d1abc81)`()` <a id="classFNTimeline_1a575d6c7980276a7a3a2ac9f83d1abc81"></a>

Empty events array

#### `public bool `[`Attached`](#classFNTimeline_1acac6e8fa7780e7d612e601cd0d479bf3)`(const TSharedPtr< `[`INEvent`](#classINEvent)` > & Event)` <a id="classFNTimeline_1acac6e8fa7780e7d612e601cd0d479bf3"></a>

Attached an event to this timeline. It creates a FEventTuple and calls BeforeOnAttached() to checks if it can be attached and AfterOnAttached() for any custom usages

#### Parameters
* `Event` - The event you want to put in the timeline stream

#### `public void `[`Attached`](#classFNTimeline_1ab0985b3570e72bd3666ed0b3d8c34eba)`(const TArray< TSharedPtr< `[`INEvent`](#classINEvent)` >> & EventsCollection)` <a id="classFNTimeline_1ab0985b3570e72bd3666ed0b3d8c34eba"></a>

Same as Attached(TSharedPtr<INEvent> Event) but for a collection of objects.

**See also**: FNTimeline::Attached(TSharedPtr<INEvent> Event)

#### `public float `[`GetTickInterval`](#classFNTimeline_1a62d57ea19cb8ad1787ddc91bc32f20bb)`() const` <a id="classFNTimeline_1a62d57ea19cb8ad1787ddc91bc32f20bb"></a>

This is the value required by a timer manager to know the tick frequency for this timeline (given by NTimelineManager). The NotifyTick use this method to add time on CurrentTime at each call.

#### `public float `[`GetCurrentTime`](#classFNTimeline_1a4aba63a32699e29b9e13df41c910cedf)`() const` <a id="classFNTimeline_1a4aba63a32699e29b9e13df41c910cedf"></a>

Retrieve the current time since this timeline exists and play

#### `public void `[`SetLabel`](#classFNTimeline_1a423302167b09a6aa88872110f46171e3)`(const FName & InLabel)` <a id="classFNTimeline_1a423302167b09a6aa88872110f46171e3"></a>

Give a name to this timeline 
#### Parameters
* `InLabel` - The name

#### `public FName `[`GetLabel`](#classFNTimeline_1aa3479c309f3e4656f70f7c40175a9e59)`() const` <a id="classFNTimeline_1aa3479c309f3e4656f70f7c40175a9e59"></a>

Return the actual name

#### `public void `[`Clear`](#classFNTimeline_1a0007252237785f91de61d32339382436)`()` <a id="classFNTimeline_1a0007252237785f91de61d32339382436"></a>

This completely reset every events. It should be used with caution.

#### `public void `[`Archive`](#classFNTimeline_1aa196425dd62d2e2745643f6ded78e1a1)`(FArchive & Ar)` <a id="classFNTimeline_1aa196425dd62d2e2745643f6ded78e1a1"></a>

Offer the opportunities to save data in a binary object. 
#### Parameters
* `Ar` - Archive where we need to save or load data.

#### `public TArray< TSharedPtr< `[`INEvent`](#classINEvent)` > > `[`GetEvents`](#classFNTimeline_1aa52a754759c0d6cf7ef5d63149755144)`() const` <a id="classFNTimeline_1aa52a754759c0d6cf7ef5d63149755144"></a>

#### Returns
Get the list of all events saved in this timeline

#### `public TArray< TSharedPtr< `[`INEvent`](#classINEvent)` > > `[`GetExpiredEvents`](#classFNTimeline_1aaee25bde92af142eb632d73286edc32c)`() const` <a id="classFNTimeline_1aaee25bde92af142eb632d73286edc32c"></a>

#### Returns
Get the list of all events expired in this timeline

#### `public TSharedPtr< `[`INEvent`](#classINEvent)` > `[`GetEvent`](#classFNTimeline_1a078b26a2c213c1a351ebc12e95ae6c1f)`(const FString & InUID) const` <a id="classFNTimeline_1a078b26a2c213c1a351ebc12e95ae6c1f"></a>

Get an event by its UID 
#### Returns
the event found or invalid TSharedPtr

#### `public TSharedPtr< `[`INEvent`](#classINEvent)` > `[`GetExpiredEvent`](#classFNTimeline_1a7e731705a5bb40eb36fdd69ea7807afa)`(const FString & InUID) const` <a id="classFNTimeline_1a7e731705a5bb40eb36fdd69ea7807afa"></a>

Get an event by its UID 
#### Returns
the event found or invalid TSharedPtr

# class `FNTimelineManager` <a id="classFNTimelineManager"></a>

This class is the client for the NTimelineInterface object. Its goal is to decoupled client interface with timeline management.

* [FNTimeline](#classFNTimeline) manages time computation, notify events accordingly and save all event states

* NTimelineManager manages client controls.

**See also**: NTimelineInterface 

**See also**: NTimeline

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`FNTimelineManager`](#classFNTimelineManager_1a553a843d413c1226dd73e60a5c8a0f6c)`()` | Calls the [Init()](#classFNTimelineManager_1ae6588ae70ff8c962ad7e6a6e17b850ff) method.
`public virtual  `[`~FNTimelineManager`](#classFNTimelineManager_1afec763fee5eab6211ecb71a98b919ce4)`()` | Calls [Clear()](#classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9) and release Timeline TSharedPtr
`public virtual void `[`Init`](#classFNTimelineManager_1ae6588ae70ff8c962ad7e6a6e17b850ff)`(const float & InTickInterval,const FName & InLabel)` | Instantiate the embedded NTimeline
`public virtual void `[`Pause`](#classFNTimelineManager_1adfdb9e277abe045ec3f39b1c82bae70a)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classFNTimelineManager_1a8bdc6933d803163abc747edbbbe9f1ba)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classFNTimelineManager_1ad83ffc005aaa74249ba19b0a28bf183a)`()` | This pause the timeline ticking and reset the NTimeline::CurrentTime to 0
`public virtual void `[`TimerTick`](#classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315)`()` | This checks the actual play state (ENTimelineTimerState) and tick the NTimelineInterface accordingly.
`public `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classFNTimelineManager_1ad24477f989e6699240c908c899ac9cd3)`() const` | Get the actual state.
`public TSharedPtr< `[`FNTimeline`](#classFNTimeline)` > `[`GetTimeline`](#classFNTimelineManager_1a30050f8bdc1a1b31b8856f1eedf0e8ca)`() const` | Get the coupled NTimelineInterface
`public virtual TSharedPtr< `[`INEvent`](#classINEvent)` > `[`CreateNewEvent`](#classFNTimelineManager_1a70061c46504ac123676913fe30568d49)`(const FName & Name,const float & Duration,const float & Delay) const` | Creates a new Event and use this timeline as the outer for this new object.
`public FNTimelineEventDelegate & `[`OnEventChanged`](#classFNTimelineManager_1a8333e517e06a022ecea528b1294d8f6c)`() const` | #### Returns
`public virtual void `[`Clear`](#classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9)`()` | Gives the opportunity to clean data. This calls Timeline::Clear()
`public virtual void `[`Archive`](#classFNTimelineManager_1abc88d207733c71ec4e1ea5ff004deb27)`(FArchive & Ar)` | Saves/loads State in archive + calls Timeline::Archive()
`protected `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classFNTimelineManager_1ac9a97cad8711f1236457cdd6cdb1fa21) | The actual state
`protected TSharedRef< `[`FNTimeline`](#classFNTimeline)` > `[`Timeline`](#classFNTimelineManager_1a0b5fd3b893fa54fe8d0c28c285f58fe2) | The coupled timeline
`protected inline virtual void `[`OnValidateTimelineTick`](#classFNTimelineManager_1ac5b30d2a1019afa9e357cedf2de7d10f)`()` | This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.
`protected inline virtual void `[`OnNotifyTimelineTickBefore`](#classFNTimelineManager_1ad433f22ab3c704fd922f4feb65f1f881)`()` | This method is call immediately before ticking
`protected inline virtual void `[`OnNotifyTimelineTickAfter`](#classFNTimelineManager_1a2e5b848bf8096cbfe7be5feb757cc0f7)`()` | This method is call immediately after ticking

## Members

#### `public  `[`FNTimelineManager`](#classFNTimelineManager_1a553a843d413c1226dd73e60a5c8a0f6c)`()` <a id="classFNTimelineManager_1a553a843d413c1226dd73e60a5c8a0f6c"></a>

Calls the [Init()](#classFNTimelineManager_1ae6588ae70ff8c962ad7e6a6e17b850ff) method.

#### `public virtual  `[`~FNTimelineManager`](#classFNTimelineManager_1afec763fee5eab6211ecb71a98b919ce4)`()` <a id="classFNTimelineManager_1afec763fee5eab6211ecb71a98b919ce4"></a>

Calls [Clear()](#classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9) and release Timeline TSharedPtr

#### `public virtual void `[`Init`](#classFNTimelineManager_1ae6588ae70ff8c962ad7e6a6e17b850ff)`(const float & InTickInterval,const FName & InLabel)` <a id="classFNTimelineManager_1ae6588ae70ff8c962ad7e6a6e17b850ff"></a>

Instantiate the embedded NTimeline

#### Parameters
* `InTickInterval` - Interval time between tick in sec 

* `InLabel` - Name of the Timeline.

#### `public virtual void `[`Pause`](#classFNTimelineManager_1adfdb9e277abe045ec3f39b1c82bae70a)`()` <a id="classFNTimelineManager_1adfdb9e277abe045ec3f39b1c82bae70a"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classFNTimelineManager_1a8bdc6933d803163abc747edbbbe9f1ba)`()` <a id="classFNTimelineManager_1a8bdc6933d803163abc747edbbbe9f1ba"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classFNTimelineManager_1ad83ffc005aaa74249ba19b0a28bf183a)`()` <a id="classFNTimelineManager_1ad83ffc005aaa74249ba19b0a28bf183a"></a>

This pause the timeline ticking and reset the NTimeline::CurrentTime to 0

#### `public virtual void `[`TimerTick`](#classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315)`()` <a id="classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315"></a>

This checks the actual play state (ENTimelineTimerState) and tick the NTimelineInterface accordingly.

#### `public `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`GetState`](#classFNTimelineManager_1ad24477f989e6699240c908c899ac9cd3)`() const` <a id="classFNTimelineManager_1ad24477f989e6699240c908c899ac9cd3"></a>

Get the actual state.

#### `public TSharedPtr< `[`FNTimeline`](#classFNTimeline)` > `[`GetTimeline`](#classFNTimelineManager_1a30050f8bdc1a1b31b8856f1eedf0e8ca)`() const` <a id="classFNTimelineManager_1a30050f8bdc1a1b31b8856f1eedf0e8ca"></a>

Get the coupled NTimelineInterface

#### `public virtual TSharedPtr< `[`INEvent`](#classINEvent)` > `[`CreateNewEvent`](#classFNTimelineManager_1a70061c46504ac123676913fe30568d49)`(const FName & Name,const float & Duration,const float & Delay) const` <a id="classFNTimelineManager_1a70061c46504ac123676913fe30568d49"></a>

Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Name` - The label of the event, can be useful for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undetermined time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `public FNTimelineEventDelegate & `[`OnEventChanged`](#classFNTimelineManager_1a8333e517e06a022ecea528b1294d8f6c)`() const` <a id="classFNTimelineManager_1a8333e517e06a022ecea528b1294d8f6c"></a>

#### Returns
a FNTimelineEventDelegate ref which is broadcast when an event changes.

#### `public virtual void `[`Clear`](#classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9)`()` <a id="classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9"></a>

Gives the opportunity to clean data. This calls Timeline::Clear()

#### `public virtual void `[`Archive`](#classFNTimelineManager_1abc88d207733c71ec4e1ea5ff004deb27)`(FArchive & Ar)` <a id="classFNTimelineManager_1abc88d207733c71ec4e1ea5ff004deb27"></a>

Saves/loads State in archive + calls Timeline::Archive()

#### `protected `[`ENTimelineTimerState`](#TimelineManager_8h_1aefac85f8316c882532fed2404c3f4de2)` `[`State`](#classFNTimelineManager_1ac9a97cad8711f1236457cdd6cdb1fa21) <a id="classFNTimelineManager_1ac9a97cad8711f1236457cdd6cdb1fa21"></a>

The actual state

#### `protected TSharedRef< `[`FNTimeline`](#classFNTimeline)` > `[`Timeline`](#classFNTimelineManager_1a0b5fd3b893fa54fe8d0c28c285f58fe2) <a id="classFNTimelineManager_1a0b5fd3b893fa54fe8d0c28c285f58fe2"></a>

The coupled timeline

#### `protected inline virtual void `[`OnValidateTimelineTick`](#classFNTimelineManager_1ac5b30d2a1019afa9e357cedf2de7d10f)`()` <a id="classFNTimelineManager_1ac5b30d2a1019afa9e357cedf2de7d10f"></a>

This should be used to make some checks right before ticking. So here you can manipulate State property to (not)allow ticking.

#### `protected inline virtual void `[`OnNotifyTimelineTickBefore`](#classFNTimelineManager_1ad433f22ab3c704fd922f4feb65f1f881)`()` <a id="classFNTimelineManager_1ad433f22ab3c704fd922f4feb65f1f881"></a>

This method is call immediately before ticking

#### `protected inline virtual void `[`OnNotifyTimelineTickAfter`](#classFNTimelineManager_1a2e5b848bf8096cbfe7be5feb757cc0f7)`()` <a id="classFNTimelineManager_1a2e5b848bf8096cbfe7be5feb757cc0f7"></a>

This method is call immediately after ticking

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

# class `INEvent` <a id="classINEvent"></a>

An interface to manage events which can be attached to a timeline.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~INEvent`](#classINEvent_1a3ebaa322a99cac6cf1e0096bb6a4449a)`() = default` | Default dtor
`public bool `[`IsExpired`](#classINEvent_1a45b84115b6ed27335cbbed7391251b03)`() const` | It indicates if the event expired.
`public float `[`GetLocalTime`](#classINEvent_1aa3fa1ae068130bd6fd550526ddfa3bff)`() const` | Returns the localTime since the events has been attached (+ delay if > 0) to a timeline
`public float `[`GetAttachedTime`](#classINEvent_1a4bc8c84a6c722d1537c59b2de86eefd7)`() const` | The time relative to the timeline this event has been attached to.
`public float `[`GetStartedAt`](#classINEvent_1a424eda5d3c78bf57558f6de08b4ee457)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public float `[`GetDuration`](#classINEvent_1ad7e7ea5568cb43569a9e7569c8ca9fca)`() const` | The duration this event should live
`public float `[`GetDelay`](#classINEvent_1a0ef2ede82ad41c9fbee775000ed41e04)`() const` | The delay before this event starts
`public FString `[`GetUID`](#classINEvent_1a34383374f442776a8cc3d23995000ba1)`() const` | Retrieve the unique ID generated or given in ctor
`public float `[`GetExpiredTime`](#classINEvent_1a57ec3f315593ca147f92ef4523d4b9bb)`() const` | The time relative to the timeline this event has been expired, should return -1 if this event has no duration.
`public FName `[`GetEventLabel`](#classINEvent_1a1e1329c0e181a83330612c99be93338d)`() const` | Getter for Label
`public bool `[`IsAttachable`](#classINEvent_1a9eee0f6e927ad0a43e15fc2ec3fd99bd)`() const` | Timeline use this to know if this event can be attached on.
`public void `[`SetEventLabel`](#classINEvent_1a3b179cbf6428629fd1c6e65486c73a1e)`(const FName & InEventLabel)` | A setter for the label. 
`public void `[`SetAttachedTime`](#classINEvent_1a5f423390b1eeab2af1efc1fc5625525e)`(const float & InLocalTime)` | Set the time this event is attached to timeline, should be used only by a [FNTimeline](#classFNTimeline).
`public void `[`SetAttachable`](#classINEvent_1ad29cc2132adfc9ad1f7e753afdfaa579)`(const bool & bInIsAttachable)` | This can be useful to avoid an Event to be attached to a timeline. 
`public void `[`SetExpiredTime`](#classINEvent_1acd54f94a9c5f80fccf10c619e575c50e)`(const float & InLocalTime)` | Set the expired time for this event. It is called by the [FNTimeline](#classFNTimeline). 
`public void `[`SetDuration`](#classINEvent_1a0ed37bb3d4cb2c2d682f849990beed2c)`(const float & InDuration)` | A setter for the duration.
`public void `[`SetDelay`](#classINEvent_1a9f25c14793ab9ba901e46c1cce5b3608)`(const float & InDelay)` | A setter for the delay.
`public void `[`Start`](#classINEvent_1a75fd4d4ea2fb8705db3166a049c81a80)`(const float & StartTime)` | This should be used only by NTimeline or serialization.
`public void `[`Stop`](#classINEvent_1ac37ad2fd82b26a2ad37b97b56065459e)`()` | This can stop the event and make it expires to its next tick.
`public void `[`AddTime`](#classINEvent_1a3a4b22179bd1918c23025da917a62aac)`(const float & NewTime)` | Increments LocalTime 
`public void `[`Clear`](#classINEvent_1a96197f5304308e63330b379b2f229a5f)`()` | This should reset all data
`public void `[`Archive`](#classINEvent_1a48539b241642c63e4aa1f500553ddde7)`(FArchive & Ar)` | 

## Members

#### `public virtual  `[`~INEvent`](#classINEvent_1a3ebaa322a99cac6cf1e0096bb6a4449a)`() = default` <a id="classINEvent_1a3ebaa322a99cac6cf1e0096bb6a4449a"></a>

Default dtor

#### `public bool `[`IsExpired`](#classINEvent_1a45b84115b6ed27335cbbed7391251b03)`() const` <a id="classINEvent_1a45b84115b6ed27335cbbed7391251b03"></a>

It indicates if the event expired.

#### `public float `[`GetLocalTime`](#classINEvent_1aa3fa1ae068130bd6fd550526ddfa3bff)`() const` <a id="classINEvent_1aa3fa1ae068130bd6fd550526ddfa3bff"></a>

Returns the localTime since the events has been attached (+ delay if > 0) to a timeline

#### `public float `[`GetAttachedTime`](#classINEvent_1a4bc8c84a6c722d1537c59b2de86eefd7)`() const` <a id="classINEvent_1a4bc8c84a6c722d1537c59b2de86eefd7"></a>

The time relative to the timeline this event has been attached to.

#### `public float `[`GetStartedAt`](#classINEvent_1a424eda5d3c78bf57558f6de08b4ee457)`() const` <a id="classINEvent_1a424eda5d3c78bf57558f6de08b4ee457"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public float `[`GetDuration`](#classINEvent_1ad7e7ea5568cb43569a9e7569c8ca9fca)`() const` <a id="classINEvent_1ad7e7ea5568cb43569a9e7569c8ca9fca"></a>

The duration this event should live

#### `public float `[`GetDelay`](#classINEvent_1a0ef2ede82ad41c9fbee775000ed41e04)`() const` <a id="classINEvent_1a0ef2ede82ad41c9fbee775000ed41e04"></a>

The delay before this event starts

#### `public FString `[`GetUID`](#classINEvent_1a34383374f442776a8cc3d23995000ba1)`() const` <a id="classINEvent_1a34383374f442776a8cc3d23995000ba1"></a>

Retrieve the unique ID generated or given in ctor

#### `public float `[`GetExpiredTime`](#classINEvent_1a57ec3f315593ca147f92ef4523d4b9bb)`() const` <a id="classINEvent_1a57ec3f315593ca147f92ef4523d4b9bb"></a>

The time relative to the timeline this event has been expired, should return -1 if this event has no duration.

#### `public FName `[`GetEventLabel`](#classINEvent_1a1e1329c0e181a83330612c99be93338d)`() const` <a id="classINEvent_1a1e1329c0e181a83330612c99be93338d"></a>

Getter for Label

#### `public bool `[`IsAttachable`](#classINEvent_1a9eee0f6e927ad0a43e15fc2ec3fd99bd)`() const` <a id="classINEvent_1a9eee0f6e927ad0a43e15fc2ec3fd99bd"></a>

Timeline use this to know if this event can be attached on.

#### `public void `[`SetEventLabel`](#classINEvent_1a3b179cbf6428629fd1c6e65486c73a1e)`(const FName & InEventLabel)` <a id="classINEvent_1a3b179cbf6428629fd1c6e65486c73a1e"></a>

A setter for the label. 
#### Parameters
* `InEventLabel` - A name to identify easily the event

#### `public void `[`SetAttachedTime`](#classINEvent_1a5f423390b1eeab2af1efc1fc5625525e)`(const float & InLocalTime)` <a id="classINEvent_1a5f423390b1eeab2af1efc1fc5625525e"></a>

Set the time this event is attached to timeline, should be used only by a [FNTimeline](#classFNTimeline).

#### `public void `[`SetAttachable`](#classINEvent_1ad29cc2132adfc9ad1f7e753afdfaa579)`(const bool & bInIsAttachable)` <a id="classINEvent_1ad29cc2132adfc9ad1f7e753afdfaa579"></a>

This can be useful to avoid an Event to be attached to a timeline. 
**See also**: [FNTimeline::Attached()](#classFNTimeline_1acac6e8fa7780e7d612e601cd0d479bf3)

**See also**: [ENTimelineEvent::BeforeAttached](#Timeline_8h_1aca8212740df4678d46efc8cae12ab0c9ab0b87ce0c6e7571ffbd0f6408c4539be)

#### Parameters
* `bInIsAttachable` - boolean to defined is attachable capability

#### `public void `[`SetExpiredTime`](#classINEvent_1acd54f94a9c5f80fccf10c619e575c50e)`(const float & InLocalTime)` <a id="classINEvent_1acd54f94a9c5f80fccf10c619e575c50e"></a>

Set the expired time for this event. It is called by the [FNTimeline](#classFNTimeline). 
#### Parameters
* `InLocalTime` - the time relative to the timeline

#### `public void `[`SetDuration`](#classINEvent_1a0ed37bb3d4cb2c2d682f849990beed2c)`(const float & InDuration)` <a id="classINEvent_1a0ed37bb3d4cb2c2d682f849990beed2c"></a>

A setter for the duration.

#### Parameters
* `InDuration` - Time in secs

#### `public void `[`SetDelay`](#classINEvent_1a9f25c14793ab9ba901e46c1cce5b3608)`(const float & InDelay)` <a id="classINEvent_1a9f25c14793ab9ba901e46c1cce5b3608"></a>

A setter for the delay.

#### Parameters
* `InDelay` - Time in secs

#### `public void `[`Start`](#classINEvent_1a75fd4d4ea2fb8705db3166a049c81a80)`(const float & StartTime)` <a id="classINEvent_1a75fd4d4ea2fb8705db3166a049c81a80"></a>

This should be used only by NTimeline or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public void `[`Stop`](#classINEvent_1ac37ad2fd82b26a2ad37b97b56065459e)`()` <a id="classINEvent_1ac37ad2fd82b26a2ad37b97b56065459e"></a>

This can stop the event and make it expires to its next tick.

#### `public void `[`AddTime`](#classINEvent_1a3a4b22179bd1918c23025da917a62aac)`(const float & NewTime)` <a id="classINEvent_1a3a4b22179bd1918c23025da917a62aac"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Milliseconds

#### `public void `[`Clear`](#classINEvent_1a96197f5304308e63330b379b2f229a5f)`()` <a id="classINEvent_1a96197f5304308e63330b379b2f229a5f"></a>

This should reset all data

#### `public void `[`Archive`](#classINEvent_1a48539b241642c63e4aa1f500553ddde7)`(FArchive & Ar)` <a id="classINEvent_1a48539b241642c63e4aa1f500553ddde7"></a>

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

# class `SNTimeline` <a id="classSNTimeline"></a>

```
class SNTimeline
  : public SLeafWidget
```  

This widget will draw timeline and events thanks to its [UNTimelineManagerDecorator](#classUNTimelineManagerDecorator) passed in.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SLATE_BEGIN_ARGS`](#classSNTimeline_1a07658b47fb4bc8a7c1266f0e62396b6e)`(`[`SNTimeline`](#classSNTimeline)`)` | 
`public void `[`Construct`](#classSNTimeline_1aad83f702aa077f671eaad9fc037022fe)`(const FArguments & InArgs)` | Constructs this widget with InArgs and listen FWorldDelegates::OnWorldBeginTearDown + FWorldDelegates::OnStartGameInstance to change bShouldComputeSize values.
`public virtual  `[`~SNTimeline`](#classSNTimeline_1ad5942bba32da43766e76c307ade28b3c)`()` | Clear TimelineRows if no other owners
`public void `[`ChangeTimeline`](#classSNTimeline_1a7416dfce67d9cd609786601d93db174a)`(`[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * Timeline)` | Will change the current timeline
`public virtual FVector2D `[`ComputeDesiredSize`](#classSNTimeline_1ad96a031c7e132735c2a491fd60402afc)`(float) const` | Compute the widget side depending on events and timeline data.
`public virtual FReply `[`OnMouseMove`](#classSNTimeline_1a8c8350549f84e900d3ac17534a170268)`(const FGeometry & MyGeometry,const FPointerEvent & MouseEvent)` | Manage tooltip to display event data.
`public void `[`CreateSlot`](#classSNTimeline_1a38a52283a713483e502bc974d2dd82ae)`(float EndPos,const `[`UNEventBase`](#classUNEventBase)` * Event) const` | Create a slot to draw (
`public virtual int32 `[`OnPaint`](#classSNTimeline_1ac55ba4f82b5f5cc290751e3a83442b50)`(const FPaintArgs & Args,const FGeometry & AllottedGeometry,const FSlateRect & MyCullingRect,FSlateWindowElementList & OutDrawElements,int32 LayerId,const FWidgetStyle & InWidgetStyle,bool bParentEnabled) const` | Will paint each event slots and timeline.
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetCurrentTimeline`](#classSNTimeline_1a3bad60db585f9af5e40c060c95c0df18)`() const` | Get the current timeline, can returns nullptr.

## Members

#### `public inline  `[`SLATE_BEGIN_ARGS`](#classSNTimeline_1a07658b47fb4bc8a7c1266f0e62396b6e)`(`[`SNTimeline`](#classSNTimeline)`)` <a id="classSNTimeline_1a07658b47fb4bc8a7c1266f0e62396b6e"></a>

#### `public void `[`Construct`](#classSNTimeline_1aad83f702aa077f671eaad9fc037022fe)`(const FArguments & InArgs)` <a id="classSNTimeline_1aad83f702aa077f671eaad9fc037022fe"></a>

Constructs this widget with InArgs and listen FWorldDelegates::OnWorldBeginTearDown + FWorldDelegates::OnStartGameInstance to change bShouldComputeSize values.

#### `public virtual  `[`~SNTimeline`](#classSNTimeline_1ad5942bba32da43766e76c307ade28b3c)`()` <a id="classSNTimeline_1ad5942bba32da43766e76c307ade28b3c"></a>

Clear TimelineRows if no other owners

#### `public void `[`ChangeTimeline`](#classSNTimeline_1a7416dfce67d9cd609786601d93db174a)`(`[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * Timeline)` <a id="classSNTimeline_1a7416dfce67d9cd609786601d93db174a"></a>

Will change the current timeline

#### `public virtual FVector2D `[`ComputeDesiredSize`](#classSNTimeline_1ad96a031c7e132735c2a491fd60402afc)`(float) const` <a id="classSNTimeline_1ad96a031c7e132735c2a491fd60402afc"></a>

Compute the widget side depending on events and timeline data.

#### `public virtual FReply `[`OnMouseMove`](#classSNTimeline_1a8c8350549f84e900d3ac17534a170268)`(const FGeometry & MyGeometry,const FPointerEvent & MouseEvent)` <a id="classSNTimeline_1a8c8350549f84e900d3ac17534a170268"></a>

Manage tooltip to display event data.

#### `public void `[`CreateSlot`](#classSNTimeline_1a38a52283a713483e502bc974d2dd82ae)`(float EndPos,const `[`UNEventBase`](#classUNEventBase)` * Event) const` <a id="classSNTimeline_1a38a52283a713483e502bc974d2dd82ae"></a>

Create a slot to draw (
**See also**: [SNTimeline::OnPaint()](#classSNTimeline_1ac55ba4f82b5f5cc290751e3a83442b50)) based on event data.

#### `public virtual int32 `[`OnPaint`](#classSNTimeline_1ac55ba4f82b5f5cc290751e3a83442b50)`(const FPaintArgs & Args,const FGeometry & AllottedGeometry,const FSlateRect & MyCullingRect,FSlateWindowElementList & OutDrawElements,int32 LayerId,const FWidgetStyle & InWidgetStyle,bool bParentEnabled) const` <a id="classSNTimeline_1ac55ba4f82b5f5cc290751e3a83442b50"></a>

Will paint each event slots and timeline.

#### `public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetCurrentTimeline`](#classSNTimeline_1a3bad60db585f9af5e40c060c95c0df18)`() const` <a id="classSNTimeline_1a3bad60db585f9af5e40c060c95c0df18"></a>

Get the current timeline, can returns nullptr.

# class `SWindowTimeline` <a id="classSWindowTimeline"></a>

```
class SWindowTimeline
  : public SCompoundWidget
```  

The main window that embedded the timeline widget ([SNTimeline](#classSNTimeline)) and the timelines selector.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SLATE_BEGIN_ARGS`](#classSWindowTimeline_1a8da5c967219ae9c1d1852fbb21d1bcfe)`(`[`SWindowTimeline`](#classSWindowTimeline)`)` | 
`public virtual  `[`~SWindowTimeline`](#classSWindowTimeline_1a49b9eb57fc0b801d75a97744966df0aa)`()` | 
`public void `[`Construct`](#classSWindowTimeline_1a829a1517d0087c4ae851b47c3c195e62)`(const FArguments & InArgs)` | Constructs this widget with InArgs
`public FText `[`BuildText`](#classSWindowTimeline_1ae989ebd5490a98790ccfe07c89cc2d06)`() const` | Display text depending on the context.

## Members

#### `public inline  `[`SLATE_BEGIN_ARGS`](#classSWindowTimeline_1a8da5c967219ae9c1d1852fbb21d1bcfe)`(`[`SWindowTimeline`](#classSWindowTimeline)`)` <a id="classSWindowTimeline_1a8da5c967219ae9c1d1852fbb21d1bcfe"></a>

#### `public virtual  `[`~SWindowTimeline`](#classSWindowTimeline_1a49b9eb57fc0b801d75a97744966df0aa)`()` <a id="classSWindowTimeline_1a49b9eb57fc0b801d75a97744966df0aa"></a>

#### `public void `[`Construct`](#classSWindowTimeline_1a829a1517d0087c4ae851b47c3c195e62)`(const FArguments & InArgs)` <a id="classSWindowTimeline_1a829a1517d0087c4ae851b47c3c195e62"></a>

Constructs this widget with InArgs

#### `public FText `[`BuildText`](#classSWindowTimeline_1ae989ebd5490a98790ccfe07c89cc2d06)`() const` <a id="classSWindowTimeline_1ae989ebd5490a98790ccfe07c89cc2d06"></a>

Display text depending on the context.

# class `UNEventBase` <a id="classUNEventBase"></a>

```
class UNEventBase
  : public UObject
  : public INEvent
```  

This is only a view object used to retrieve events from blueprint.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`UNEventBase`](#classUNEventBase_1a455691505e86b5aa4894bcdcce0c5e2e)`()` | 
`public void `[`Init`](#classUNEventBase_1a0af078c08b7a5302be91ed67e2b62b53)`(const TSharedPtr< `[`INEvent`](#classINEvent)` > & InEvent,const float & InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | 
`public virtual bool `[`IsExpired`](#classUNEventBase_1ac2ab1939bb5dc91ebdda3191c652a379)`() const` | It indicates if the event expired.
`public virtual float `[`GetLocalTime`](#classUNEventBase_1a62200a868420c01a4bc3d9adc7fc47f7)`() const` | Returns the localTime since the events has been attached (+ delay if > 0) to a timeline
`public virtual float `[`GetStartedAt`](#classUNEventBase_1a4d488e306ab130d28f1623725c158453)`() const` | The time relative to the timeline this event has been attached to + its start delay.
`public virtual float `[`GetDuration`](#classUNEventBase_1a5ec86b163cea385dc9307bb7c88cc618)`() const` | The duration this event should live
`public virtual float `[`GetDelay`](#classUNEventBase_1a7b90a9649e8279a9fb92fdec49abdc1a)`() const` | The delay before this event starts
`public virtual FName `[`GetEventLabel`](#classUNEventBase_1a4c124661577ce3229b5706e308ee391a)`() const` | Getter for Label
`public virtual void `[`SetEventLabel`](#classUNEventBase_1a6758698a83185bf08f225980f1050bf8)`(const FName & InEventLabel)` | A setter for the label. 
`public virtual FString `[`GetUID`](#classUNEventBase_1a7a45a85355cc04702641dccf89f94d18)`() const` | Retrieve the unique ID generated or given in ctor
`public virtual float `[`GetAttachedTime`](#classUNEventBase_1ae904ea0cacf1d5bdff57086c31ebe284)`() const` | The time relative to the timeline this event has been attached to.
`public virtual bool `[`IsAttachable`](#classUNEventBase_1a9da5bc76cbd140a14c09eb8edd2febf4)`() const` | Timeline use this to know if this event can be attached on.
`public virtual float `[`GetExpiredTime`](#classUNEventBase_1ab93b7c456139ec3bd41532cebe28e83b)`() const` | The time relative to the timeline this event has been expired, should return -1 if this event has no duration.
`public virtual void `[`Stop`](#classUNEventBase_1a6f604ed7ed2092d37cffe8b04f3992af)`()` | This can stop the event and make it expires to its next tick.
`public inline virtual void `[`SetAttachedTime`](#classUNEventBase_1a60a54be864ebf71576691d4e986a1d06)`(const float & InLocalTime)` | Set the time this event is attached to timeline, should be used only by a [FNTimeline](#classFNTimeline).
`public inline virtual void `[`SetAttachable`](#classUNEventBase_1a04aba824d88d39ae40bcf31ef74c9cdd)`(const bool & bInIsAttachable)` | This can be useful to avoid an Event to be attached to a timeline. 
`public inline virtual void `[`SetExpiredTime`](#classUNEventBase_1a99a16fa823326e5dc001722e2a3dc3bc)`(const float & InLocalTime)` | Set the expired time for this event. It is called by the [FNTimeline](#classFNTimeline). 
`public inline virtual void `[`SetDuration`](#classUNEventBase_1af820f8f0a72d9e02b1c5d9112b9ec46f)`(const float & InDuration)` | A setter for the duration.
`public inline virtual void `[`SetDelay`](#classUNEventBase_1a07131c9b6140553ee135f6ed76e37aa7)`(const float & InDelay)` | A setter for the delay.
`public inline virtual void `[`Start`](#classUNEventBase_1ad894725222f91a539c8ba1a6ed96190b)`(const float & StartTime)` | This should be used only by NTimeline or serialization.
`public inline virtual void `[`AddTime`](#classUNEventBase_1a5a4036afe5bed080a7256dd883e2dae1)`(const float & NewTime)` | Increments LocalTime 
`public inline virtual void `[`Clear`](#classUNEventBase_1a418810554527dcc9af674d6723675e60)`()` | This should reset all data
`public inline virtual void `[`Archive`](#classUNEventBase_1a08d9469f3ddd1a0ddd8bc5f8bae0f86c)`(FArchive & Ar)` | 
`public void `[`OnInit`](#classUNEventBase_1aa4f978c4bda7062ee7e11799ff3e3914)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public void `[`OnStart`](#classUNEventBase_1a7f90a5e005e12cac68c848b31f04027f)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public void `[`OnBeforeAttached`](#classUNEventBase_1a39cc025006ae72162b352d6a6d26b88f)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public void `[`OnAfterAttached`](#classUNEventBase_1a5c608c2661f3b4c08b425c7529c42ec6)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public void `[`OnExpired`](#classUNEventBase_1aaec81c0b5426582d53d4c1dfd615df48)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public void `[`OnTick`](#classUNEventBase_1ad5afbc2999dde8df5cbd2f5ba46dcff1)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public void `[`OnCleared`](#classUNEventBase_1a706dafe4dcc0585833d72fc7d5043edc)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` | #### Parameters
`public virtual void `[`BeginDestroy`](#classUNEventBase_1a11f4eb30deadcee0cb891465f5882fe3)`()` | 
`public TSharedPtr< `[`INEvent`](#classINEvent)` > `[`GetEvent`](#classUNEventBase_1ae01d27c74fb277bff470ce26e2e10d27)`()` | 

## Members

#### `public inline  `[`UNEventBase`](#classUNEventBase_1a455691505e86b5aa4894bcdcce0c5e2e)`()` <a id="classUNEventBase_1a455691505e86b5aa4894bcdcce0c5e2e"></a>

#### `public void `[`Init`](#classUNEventBase_1a0af078c08b7a5302be91ed67e2b62b53)`(const TSharedPtr< `[`INEvent`](#classINEvent)` > & InEvent,const float & InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1a0af078c08b7a5302be91ed67e2b62b53"></a>

#### `public virtual bool `[`IsExpired`](#classUNEventBase_1ac2ab1939bb5dc91ebdda3191c652a379)`() const` <a id="classUNEventBase_1ac2ab1939bb5dc91ebdda3191c652a379"></a>

It indicates if the event expired.

#### `public virtual float `[`GetLocalTime`](#classUNEventBase_1a62200a868420c01a4bc3d9adc7fc47f7)`() const` <a id="classUNEventBase_1a62200a868420c01a4bc3d9adc7fc47f7"></a>

Returns the localTime since the events has been attached (+ delay if > 0) to a timeline

#### `public virtual float `[`GetStartedAt`](#classUNEventBase_1a4d488e306ab130d28f1623725c158453)`() const` <a id="classUNEventBase_1a4d488e306ab130d28f1623725c158453"></a>

The time relative to the timeline this event has been attached to + its start delay.

#### `public virtual float `[`GetDuration`](#classUNEventBase_1a5ec86b163cea385dc9307bb7c88cc618)`() const` <a id="classUNEventBase_1a5ec86b163cea385dc9307bb7c88cc618"></a>

The duration this event should live

#### `public virtual float `[`GetDelay`](#classUNEventBase_1a7b90a9649e8279a9fb92fdec49abdc1a)`() const` <a id="classUNEventBase_1a7b90a9649e8279a9fb92fdec49abdc1a"></a>

The delay before this event starts

#### `public virtual FName `[`GetEventLabel`](#classUNEventBase_1a4c124661577ce3229b5706e308ee391a)`() const` <a id="classUNEventBase_1a4c124661577ce3229b5706e308ee391a"></a>

Getter for Label

#### `public virtual void `[`SetEventLabel`](#classUNEventBase_1a6758698a83185bf08f225980f1050bf8)`(const FName & InEventLabel)` <a id="classUNEventBase_1a6758698a83185bf08f225980f1050bf8"></a>

A setter for the label. 
#### Parameters
* `InEventLabel` - A name to identify easily the event

#### `public virtual FString `[`GetUID`](#classUNEventBase_1a7a45a85355cc04702641dccf89f94d18)`() const` <a id="classUNEventBase_1a7a45a85355cc04702641dccf89f94d18"></a>

Retrieve the unique ID generated or given in ctor

#### `public virtual float `[`GetAttachedTime`](#classUNEventBase_1ae904ea0cacf1d5bdff57086c31ebe284)`() const` <a id="classUNEventBase_1ae904ea0cacf1d5bdff57086c31ebe284"></a>

The time relative to the timeline this event has been attached to.

#### `public virtual bool `[`IsAttachable`](#classUNEventBase_1a9da5bc76cbd140a14c09eb8edd2febf4)`() const` <a id="classUNEventBase_1a9da5bc76cbd140a14c09eb8edd2febf4"></a>

Timeline use this to know if this event can be attached on.

#### `public virtual float `[`GetExpiredTime`](#classUNEventBase_1ab93b7c456139ec3bd41532cebe28e83b)`() const` <a id="classUNEventBase_1ab93b7c456139ec3bd41532cebe28e83b"></a>

The time relative to the timeline this event has been expired, should return -1 if this event has no duration.

#### `public virtual void `[`Stop`](#classUNEventBase_1a6f604ed7ed2092d37cffe8b04f3992af)`()` <a id="classUNEventBase_1a6f604ed7ed2092d37cffe8b04f3992af"></a>

This can stop the event and make it expires to its next tick.

#### `public inline virtual void `[`SetAttachedTime`](#classUNEventBase_1a60a54be864ebf71576691d4e986a1d06)`(const float & InLocalTime)` <a id="classUNEventBase_1a60a54be864ebf71576691d4e986a1d06"></a>

Set the time this event is attached to timeline, should be used only by a [FNTimeline](#classFNTimeline).

#### `public inline virtual void `[`SetAttachable`](#classUNEventBase_1a04aba824d88d39ae40bcf31ef74c9cdd)`(const bool & bInIsAttachable)` <a id="classUNEventBase_1a04aba824d88d39ae40bcf31ef74c9cdd"></a>

This can be useful to avoid an Event to be attached to a timeline. 
**See also**: [FNTimeline::Attached()](#classFNTimeline_1acac6e8fa7780e7d612e601cd0d479bf3)

**See also**: [ENTimelineEvent::BeforeAttached](#Timeline_8h_1aca8212740df4678d46efc8cae12ab0c9ab0b87ce0c6e7571ffbd0f6408c4539be)

#### Parameters
* `bInIsAttachable` - boolean to defined is attachable capability

#### `public inline virtual void `[`SetExpiredTime`](#classUNEventBase_1a99a16fa823326e5dc001722e2a3dc3bc)`(const float & InLocalTime)` <a id="classUNEventBase_1a99a16fa823326e5dc001722e2a3dc3bc"></a>

Set the expired time for this event. It is called by the [FNTimeline](#classFNTimeline). 
#### Parameters
* `InLocalTime` - the time relative to the timeline

#### `public inline virtual void `[`SetDuration`](#classUNEventBase_1af820f8f0a72d9e02b1c5d9112b9ec46f)`(const float & InDuration)` <a id="classUNEventBase_1af820f8f0a72d9e02b1c5d9112b9ec46f"></a>

A setter for the duration.

#### Parameters
* `InDuration` - Time in secs

#### `public inline virtual void `[`SetDelay`](#classUNEventBase_1a07131c9b6140553ee135f6ed76e37aa7)`(const float & InDelay)` <a id="classUNEventBase_1a07131c9b6140553ee135f6ed76e37aa7"></a>

A setter for the delay.

#### Parameters
* `InDelay` - Time in secs

#### `public inline virtual void `[`Start`](#classUNEventBase_1ad894725222f91a539c8ba1a6ed96190b)`(const float & StartTime)` <a id="classUNEventBase_1ad894725222f91a539c8ba1a6ed96190b"></a>

This should be used only by NTimeline or serialization.

#### Parameters
* `StartTime` - Time in secs

#### `public inline virtual void `[`AddTime`](#classUNEventBase_1a5a4036afe5bed080a7256dd883e2dae1)`(const float & NewTime)` <a id="classUNEventBase_1a5a4036afe5bed080a7256dd883e2dae1"></a>

Increments LocalTime 
#### Parameters
* `NewTime` - in Milliseconds

#### `public inline virtual void `[`Clear`](#classUNEventBase_1a418810554527dcc9af674d6723675e60)`()` <a id="classUNEventBase_1a418810554527dcc9af674d6723675e60"></a>

This should reset all data

#### `public inline virtual void `[`Archive`](#classUNEventBase_1a08d9469f3ddd1a0ddd8bc5f8bae0f86c)`(FArchive & Ar)` <a id="classUNEventBase_1a08d9469f3ddd1a0ddd8bc5f8bae0f86c"></a>

#### `public void `[`OnInit`](#classUNEventBase_1aa4f978c4bda7062ee7e11799ff3e3914)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1aa4f978c4bda7062ee7e11799ff3e3914"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public void `[`OnStart`](#classUNEventBase_1a7f90a5e005e12cac68c848b31f04027f)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1a7f90a5e005e12cac68c848b31f04027f"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public void `[`OnBeforeAttached`](#classUNEventBase_1a39cc025006ae72162b352d6a6d26b88f)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1a39cc025006ae72162b352d6a6d26b88f"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public void `[`OnAfterAttached`](#classUNEventBase_1a5c608c2661f3b4c08b425c7529c42ec6)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1a5c608c2661f3b4c08b425c7529c42ec6"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public void `[`OnExpired`](#classUNEventBase_1aaec81c0b5426582d53d4c1dfd615df48)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1aaec81c0b5426582d53d4c1dfd615df48"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public void `[`OnTick`](#classUNEventBase_1ad5afbc2999dde8df5cbd2f5ba46dcff1)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1ad5afbc2999dde8df5cbd2f5ba46dcff1"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public void `[`OnCleared`](#classUNEventBase_1a706dafe4dcc0585833d72fc7d5043edc)`(float InLocalTime,UWorld * InWorld,APlayerController * InPlayer)` <a id="classUNEventBase_1a706dafe4dcc0585833d72fc7d5043edc"></a>

#### Parameters
* `InLocalTime` - the time (in seconds) from the timeline start. /!\ It is also called when timeline is deserialize, it doesn't follow the chronological event life compare to other events. 

**See also**: [UNTimelineManagerDecorator::Serialize()](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)

#### Parameters
* `InWorld` - the world of the timeline that trigger this event 

* `InPlayer` - The current player.

#### `public virtual void `[`BeginDestroy`](#classUNEventBase_1a11f4eb30deadcee0cb891465f5882fe3)`()` <a id="classUNEventBase_1a11f4eb30deadcee0cb891465f5882fe3"></a>

#### `public TSharedPtr< `[`INEvent`](#classINEvent)` > `[`GetEvent`](#classUNEventBase_1ae01d27c74fb277bff470ce26e2e10d27)`()` <a id="classUNEventBase_1ae01d27c74fb277bff470ce26e2e10d27"></a>

# class `UNEventBaseBlueprint` <a id="classUNEventBaseBlueprint"></a>

```
class UNEventBaseBlueprint
  : public UBlueprint
```  

A [UNEventBaseBlueprint](#classUNEventBaseBlueprint) is essentially a specialized Blueprint whose graphs control an [UNEventBase](#classUNEventBase). The [UNEventBase](#classUNEventBase) factory should pick this for you automatically

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNEventFactory` <a id="classUNEventFactory"></a>

```
class UNEventFactory
  : public UFactory
```  

Allows to create a blueprint asset in the editor with default event nodes.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TSubclassOf< class `[`UNEventBase`](#classUNEventBase)` > `[`ParentClass`](#classUNEventFactory_1ae910043e1dabd6512daec08a15b6ffe6) | The parent class of the created blueprint
`public  `[`UNEventFactory`](#classUNEventFactory_1aefa05aa1d9f8e0e1c41c03e521950830)`()` | 
`public virtual UObject * `[`FactoryCreateNew`](#classUNEventFactory_1aecec3a3ca69eaf279cdb5c214a589093)`(UClass * InClass,UObject * InParent,FName InName,EObjectFlags Flags,UObject * Context,FFeedbackContext * Warn)` | 
`public virtual bool `[`ShouldShowInNewMenu`](#classUNEventFactory_1a3e0b5e81d454cb0d510dd4b1c042a8b5)`() const` | 
`public virtual uint32 `[`GetMenuCategories`](#classUNEventFactory_1a0d0624b96c0426f3e15aa7d9fa514d4b)`() const` | 

## Members

#### `public TSubclassOf< class `[`UNEventBase`](#classUNEventBase)` > `[`ParentClass`](#classUNEventFactory_1ae910043e1dabd6512daec08a15b6ffe6) <a id="classUNEventFactory_1ae910043e1dabd6512daec08a15b6ffe6"></a>

The parent class of the created blueprint

#### `public  `[`UNEventFactory`](#classUNEventFactory_1aefa05aa1d9f8e0e1c41c03e521950830)`()` <a id="classUNEventFactory_1aefa05aa1d9f8e0e1c41c03e521950830"></a>

#### `public virtual UObject * `[`FactoryCreateNew`](#classUNEventFactory_1aecec3a3ca69eaf279cdb5c214a589093)`(UClass * InClass,UObject * InParent,FName InName,EObjectFlags Flags,UObject * Context,FFeedbackContext * Warn)` <a id="classUNEventFactory_1aecec3a3ca69eaf279cdb5c214a589093"></a>

#### `public virtual bool `[`ShouldShowInNewMenu`](#classUNEventFactory_1a3e0b5e81d454cb0d510dd4b1c042a8b5)`() const` <a id="classUNEventFactory_1a3e0b5e81d454cb0d510dd4b1c042a8b5"></a>

#### `public virtual uint32 `[`GetMenuCategories`](#classUNEventFactory_1a0d0624b96c0426f3e15aa7d9fa514d4b)`() const` <a id="classUNEventFactory_1a0d0624b96c0426f3e15aa7d9fa514d4b"></a>

# class `UNEventGraph` <a id="classUNEventGraph"></a>

```
class UNEventGraph
  : public UEdGraph
```  

A dedicated graph for [UNEventBase](#classUNEventBase) used for [UNEventBaseBlueprint](#classUNEventBaseBlueprint) creation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `UNEventGraphSchema` <a id="classUNEventGraphSchema"></a>

```
class UNEventGraphSchema
  : public UEdGraphSchema_K2
```  

A dedicated graph schema for [UNEventBase](#classUNEventBase) used for [UNEventBaseBlueprint](#classUNEventBaseBlueprint) creation.

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
`public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) | Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315)
`public virtual void `[`Init`](#classUNGameLifeTimelineManager_1ae92d2bd1d429839b90220685bf68c4b1)`(const float & InTickInterval,const FName & InLabel)` | It creates the timer with a FTimerManager and attached TimerDelegate to it. 
`public virtual void `[`BeginDestroy`](#classUNGameLifeTimelineManager_1a9d2352f07a0015a0afefb0606889abba)`()` | Clears timer + unbind delegate + invalidate handle.
`protected float `[`SaveTime`](#classUNGameLifeTimelineManager_1a0d681eda0366cc78e75a8dbc3e49a1a4) | This is only used for savegame to keep time between sessions
`protected  `[`UNGameLifeTimelineManager`](#classUNGameLifeTimelineManager_1abe6ebaa8f9f8601a5e97f6ae3c8a8f4b)`()` | A default ctor for engine system

## Members

#### `public FTimerHandle `[`TimerHandle`](#classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab) <a id="classUNGameLifeTimelineManager_1ab3212791e62e45a2ae67a307007addab"></a>

Created by the FTimerManager

#### `public FTimerDelegate `[`TimerDelegate`](#classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61) <a id="classUNGameLifeTimelineManager_1a1ca6a4c74cf6e66b807b6ec72f5d5c61"></a>

Delegate required by the FTimerManager. It create a UObject delegate using [UNGameLifeTimelineManager::TimerTick()](#classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315)

#### `public virtual void `[`Init`](#classUNGameLifeTimelineManager_1ae92d2bd1d429839b90220685bf68c4b1)`(const float & InTickInterval,const FName & InLabel)` <a id="classUNGameLifeTimelineManager_1ae92d2bd1d429839b90220685bf68c4b1"></a>

It creates the timer with a FTimerManager and attached TimerDelegate to it. 
#### Parameters
* `InTickInterval` - The tick interval in seconds 

* `InLabel` - Name of the timer

#### `public virtual void `[`BeginDestroy`](#classUNGameLifeTimelineManager_1a9d2352f07a0015a0afefb0606889abba)`()` <a id="classUNGameLifeTimelineManager_1a9d2352f07a0015a0afefb0606889abba"></a>

Clears timer + unbind delegate + invalidate handle.

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

It could be useful for level bonus/malus attribution during a level session, or create a scheduled event.

For example:

* a player character take drugs and his capacities are altered for an amount of time

* player init a bomb and it should explode in a determined time.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1a410266cc414a950102c180b98eaf0e2f)`(const float & InTickInterval,const FName & InLabel)` | Attaches event on level changes The embedded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` | This method to clear and reload timeline when level changed
`public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a3d76c38bc335f678c6a179ceaec03177)`(UWorld * LoadedWorld)` | This method to clear and reload timeline when level changed
`public virtual void `[`Serialize`](#classUNLevelLifeTimelineManager_1af8219c4c92afed8f7a45913235ef821f)`(FArchive & Ar)` | This only saves level name and checks
`public virtual void `[`BeginDestroy`](#classUNLevelLifeTimelineManager_1aef9dac4ffdad51017a6a587295b769b4)`()` | Clears timer + unbind delegate + invalidate handle.
`protected FName `[`Label`](#classUNLevelLifeTimelineManager_1ab995fbe611974a32f0d09fcd2aec2513) | Used for save game object
`protected FString `[`LevelName`](#classUNLevelLifeTimelineManager_1a8141bcb7087a653bf7fa32509d12eab2) | Used for save game to make a sanity check (verify if current world is the same as the load game)
`protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` | Default ctor
`protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` | TODO WIP

## Members

#### `public virtual void `[`Init`](#classUNLevelLifeTimelineManager_1a410266cc414a950102c180b98eaf0e2f)`(const float & InTickInterval,const FName & InLabel)` <a id="classUNLevelLifeTimelineManager_1a410266cc414a950102c180b98eaf0e2f"></a>

Attaches event on level changes The embedded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerDecorator()](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)

#### Parameters
* `InTickInterval` - Interval time between tick in sec 

* `InLabel` - Name of the Timeline.

#### `public void `[`OnLevelRemoved`](#classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632)`(ULevel * Level,UWorld * World)` <a id="classUNLevelLifeTimelineManager_1a3c1cd7121203fc49d09d54dc73c86632"></a>

This method to clear and reload timeline when level changed

#### `public void `[`OnLevelChanged`](#classUNLevelLifeTimelineManager_1a3d76c38bc335f678c6a179ceaec03177)`(UWorld * LoadedWorld)` <a id="classUNLevelLifeTimelineManager_1a3d76c38bc335f678c6a179ceaec03177"></a>

This method to clear and reload timeline when level changed

#### `public virtual void `[`Serialize`](#classUNLevelLifeTimelineManager_1af8219c4c92afed8f7a45913235ef821f)`(FArchive & Ar)` <a id="classUNLevelLifeTimelineManager_1af8219c4c92afed8f7a45913235ef821f"></a>

This only saves level name and checks

#### `public virtual void `[`BeginDestroy`](#classUNLevelLifeTimelineManager_1aef9dac4ffdad51017a6a587295b769b4)`()` <a id="classUNLevelLifeTimelineManager_1aef9dac4ffdad51017a6a587295b769b4"></a>

Clears timer + unbind delegate + invalidate handle.

#### `protected FName `[`Label`](#classUNLevelLifeTimelineManager_1ab995fbe611974a32f0d09fcd2aec2513) <a id="classUNLevelLifeTimelineManager_1ab995fbe611974a32f0d09fcd2aec2513"></a>

Used for save game object

#### `protected FString `[`LevelName`](#classUNLevelLifeTimelineManager_1a8141bcb7087a653bf7fa32509d12eab2) <a id="classUNLevelLifeTimelineManager_1a8141bcb7087a653bf7fa32509d12eab2"></a>

Used for save game to make a sanity check (verify if current world is the same as the load game)

#### `protected  `[`UNLevelLifeTimelineManager`](#classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839)`()` <a id="classUNLevelLifeTimelineManager_1a59da215730db96d6bb7717b4a958b839"></a>

Default ctor

#### `protected void `[`SaveDataAndClear`](#classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb)`()` <a id="classUNLevelLifeTimelineManager_1a98cfc167f00c3fca48a9f7ab861842eb"></a>

TODO WIP

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
`public virtual void `[`Init`](#classUNRealLifeTimelineManager_1acf5dca0110674180de936316bc9d69b1)`(const float & InTickInterval,const FName & InLabel)` | This just init State to "Play" and time variables. The embedded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1a3b7412c8d62689c10f649740e37105e0)`() const` | Always returns true 'cause it can be paused or stopped
`public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` | Always returns true 'cause it can be paused or stopped
`public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` | This override methods allows to tick [UNTimelineManagerDecorator::TimerTick()](#classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315) and to increment times vars.
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

#### `public virtual void `[`Init`](#classUNRealLifeTimelineManager_1acf5dca0110674180de936316bc9d69b1)`(const float & InTickInterval,const FName & InLabel)` <a id="classUNRealLifeTimelineManager_1acf5dca0110674180de936316bc9d69b1"></a>

This just init State to "Play" and time variables. The embedded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerDecorator()](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)

#### Parameters
* `InTickInterval` - Interval time between tick in sec 

* `InLabel` - Name of the Timeline.

#### `public inline virtual bool `[`IsTickableWhenPaused`](#classUNRealLifeTimelineManager_1a3b7412c8d62689c10f649740e37105e0)`() const` <a id="classUNRealLifeTimelineManager_1a3b7412c8d62689c10f649740e37105e0"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual bool `[`IsTickable`](#classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65)`() const` <a id="classUNRealLifeTimelineManager_1aed1bad81ebfc134232dfc15757deae65"></a>

Always returns true 'cause it can be paused or stopped

#### `public virtual void `[`Tick`](#classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e)`(float DeltaTime)` <a id="classUNRealLifeTimelineManager_1a28e255d79d9a7ddc11d2a686eba28a8e"></a>

This override methods allows to tick [UNTimelineManagerDecorator::TimerTick()](#classFNTimelineManager_1a7ab2d5e6a262ca85c968f077710c2315) and to increment times vars.

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

**See also**: INTimelineGameInstance. 

**See also**: [UNTimelineConfig](#classUNTimelineConfig) to get more details on the configuration. 

**See also**: [FConfiguredTimeline](#structFConfiguredTimeline) to see how to use Configured Timeline as blueprint pins.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`UNTimelineClient`](#classUNTimelineClient_1a5681002cd61186d942306798fd0140fa)`()` | 
`public virtual void `[`Init`](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)`()` | This method allows to instantiate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1adef671dac978ef3a26eb7ec28b928c29)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Config) const` | A blueprint pass-through for GetTimeline(FName Name).
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUNTimelineClient_1a25d292f407cebcf4bf58fdbc130be874)`(FName Name) const` | Get the timeline from TimelinesCollection by its name.
`public virtual void `[`Serialize`](#classUNTimelineClient_1aef09f534dcf7de683bfe5aea7b184e27)`(FArchive & Ar)` | It used to save all timelines in the TimelinesCollection, and reload them correctly.
`protected TMap< FName, `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * > `[`TimelinesCollection`](#classUNTimelineClient_1af9b1553ab4dbf3246725aae6f379c9ae) | Collection of timelines instantiated in [Init()](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)

## Members

#### `public  `[`UNTimelineClient`](#classUNTimelineClient_1a5681002cd61186d942306798fd0140fa)`()` <a id="classUNTimelineClient_1a5681002cd61186d942306798fd0140fa"></a>

#### `public virtual void `[`Init`](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)`()` <a id="classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615"></a>

This method allows to instantiate all Timeline from the config: [FConfiguredTimeline](#structFConfiguredTimeline).

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

Collection of timelines instantiated in [Init()](#classUNTimelineClient_1a99d4009604d9b8c4f3f58adb30e6d615)

# class `UNTimelineConfig` <a id="classUNTimelineConfig"></a>

```
class UNTimelineConfig
  : public UDeveloperSettings
```  

A simple configuration to ease timeline instantiation for developpers.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TArray< `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf)` > `[`ConfiguredTimeline`](#classUNTimelineConfig_1a8e65c72e77d25e4787435f6cd8a6e23d) | 

## Members

#### `public TArray< `[`FConfiguredTimelineConf`](#structFConfiguredTimelineConf)` > `[`ConfiguredTimeline`](#classUNTimelineConfig_1a8e65c72e77d25e4787435f6cd8a6e23d) <a id="classUNTimelineConfig_1a8e65c72e77d25e4787435f6cd8a6e23d"></a>

# class `UNTimelineManagerDecorator` <a id="classUNTimelineManagerDecorator"></a>

```
class UNTimelineManagerDecorator
  : public UObject
  : public FNTimelineManager
```  

This is the abstract decorator that every Timeline manager should override. It brings all core functionalities for blueprint or UE4 c++ paradigm.

As the close relation between NTimelineManager and NTimeline classes (core lib), This class is coupled with UNTimelineDecorator. 
**See also**: UNTimelineDecorator

To ease blueprint usages, most of the UNTimelineDecorator public functionalities are accessible here. This class works as a pass-through too for UNTimelineDecorator.

**See also**: AddEvent(), [CreateNewEvent()](#classFNTimelineManager_1a70061c46504ac123676913fe30568d49), [CreateAndAddNewEvent()](#classUNTimelineManagerDecorator_1ae170074f6d2b96af0b3163d42c942b9f)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`bDebug`](#classUNTimelineManagerDecorator_1aadf990ac802d0ee7557ed2cb6d43da3d) | 
`public float `[`TickInterval`](#classUNTimelineManagerDecorator_1ae56e54a0f08d994dcbf1e8dc2b301b0a) | The interval retrieved from the timeline.
`public const float & `[`EventTime`](#classUNTimelineManagerDecorator_1a29e9a7c4d48d51d31f1df9e43c7ceab7) | 
`public virtual void `[`Pause`](#classUNTimelineManagerDecorator_1a1b664da3c9dc614df40822ebce117cfb)`()` | This pause the timeline ticking
`public virtual void `[`Play`](#classUNTimelineManagerDecorator_1a16f09380884450c7b220f1c78c336cf3)`()` | This (re)start the timeline ticking
`public virtual void `[`Stop`](#classUNTimelineManagerDecorator_1abe640ee5d20aed0044f17b625c5923ed)`()` | This pause the timeline ticking and reset the NTimeline::CurrentTime to 0
`public void `[`OnEventChangedDelegate`](#classUNTimelineManagerDecorator_1aaecdbbc5de72c32131f7dcef19b0f153)`(TSharedPtr< `[`INEvent`](#classINEvent)` > Event,const `[`ENTimelineEvent`](#Timeline_8h_1aca8212740df4678d46efc8cae12ab0c9)` & EventName,const float & LocalTime,const int32 & Index)` | 
`public virtual void `[`Init`](#classUNTimelineManagerDecorator_1a642cf6d81cf285ed4a79e2b98bc6484e)`(const float & InTickInterval,const FName & InLabel)` | The embedded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
`public virtual void `[`Serialize`](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)`(FArchive & Ar)` | It's the starting link of serialization chain for all embedded decorators. This calls UNTimelineDecorator::Serialize().
`public virtual void `[`BeginDestroy`](#classUNTimelineManagerDecorator_1ab6701a003cf2311d71890fa567089024)`()` | This calls [FNTimelineManager::Clear()](#classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9).
`public TArray< `[`UNEventBase`](#classUNEventBase)` * > `[`GetEvents`](#classUNTimelineManagerDecorator_1a636a2d0ac5950e0aed653f378b04e3c5)`() const` | 
`public TArray< `[`UNEventBase`](#classUNEventBase)` * > `[`GetExpiredEvents`](#classUNTimelineManagerDecorator_1a1139775a870015cd3042cca73e036bae)`() const` | 
`public `[`UNEventBase`](#classUNEventBase)` * `[`GetEvent`](#classUNTimelineManagerDecorator_1aa975120fb17b3dc7c455c33e37cac952)`(const FString & InUID) const` | 
`public float `[`GetCurrentTime`](#classUNTimelineManagerDecorator_1adc4d0b50faa76c955cb928750de41352)`() const` | 
`public FName `[`GetLabel`](#classUNTimelineManagerDecorator_1aed6e9c7e069c9e7637076a7b235adf7f)`() const` | 
`public void `[`SetLabel`](#classUNTimelineManagerDecorator_1ab37f83214580022621c695a7180a6b3c)`(const FName & Name)` | A pass-through for the embedded [FNTimeline::SetLabel()](#classFNTimeline_1a423302167b09a6aa88872110f46171e3)
`public  `[`UFUNCTION`](#classUNTimelineManagerDecorator_1a99daa6cdb789cba6b723c5aed78f06e7)`(BlueprintCallable,BlueprintImplementableEvent,Category,meta) const` | 
`public `[`UNEventBase`](#classUNEventBase)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerDecorator_1ae170074f6d2b96af0b3163d42c942b9f)`(FName InName,float InDuration,float InDelay,TSubclassOf< `[`UNEventBase`](#classUNEventBase)` > InClass)` | Attaches the event to the timeline stream Creates a new Event and use this timeline as the outer for this new object.
`public virtual void `[`Clear`](#classUNTimelineManagerDecorator_1ab6802b439e1c5aa98b520700c8175de3)`()` | Remove all EventBases and ExpiredEventBases
`protected FDateTime `[`StartedAt`](#classUNTimelineManagerDecorator_1a1453e9a6eb62bc4ca4d4a4578b54d8ad) | 
`protected TMap< FString, `[`UNEventBase`](#classUNEventBase)` * > `[`EventBases`](#classUNTimelineManagerDecorator_1a86a56f7689205d237836ee78439dab5e) | 
`protected TMap< FString, `[`UNEventBase`](#classUNEventBase)` * > `[`ExpiredEventBases`](#classUNTimelineManagerDecorator_1a250fcce6db6fada1f1d0a9f56b7b3073) | 
`protected  `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)`()` | Protected ctor to force instantiation with CreateObject() methods (factory methods). It instantiates the embedded timeline with CreateDefaultSubobject().

## Members

#### `public bool `[`bDebug`](#classUNTimelineManagerDecorator_1aadf990ac802d0ee7557ed2cb6d43da3d) <a id="classUNTimelineManagerDecorator_1aadf990ac802d0ee7557ed2cb6d43da3d"></a>

#### `public float `[`TickInterval`](#classUNTimelineManagerDecorator_1ae56e54a0f08d994dcbf1e8dc2b301b0a) <a id="classUNTimelineManagerDecorator_1ae56e54a0f08d994dcbf1e8dc2b301b0a"></a>

The interval retrieved from the timeline.

#### `public const float & `[`EventTime`](#classUNTimelineManagerDecorator_1a29e9a7c4d48d51d31f1df9e43c7ceab7) <a id="classUNTimelineManagerDecorator_1a29e9a7c4d48d51d31f1df9e43c7ceab7"></a>

#### `public virtual void `[`Pause`](#classUNTimelineManagerDecorator_1a1b664da3c9dc614df40822ebce117cfb)`()` <a id="classUNTimelineManagerDecorator_1a1b664da3c9dc614df40822ebce117cfb"></a>

This pause the timeline ticking

#### `public virtual void `[`Play`](#classUNTimelineManagerDecorator_1a16f09380884450c7b220f1c78c336cf3)`()` <a id="classUNTimelineManagerDecorator_1a16f09380884450c7b220f1c78c336cf3"></a>

This (re)start the timeline ticking

#### `public virtual void `[`Stop`](#classUNTimelineManagerDecorator_1abe640ee5d20aed0044f17b625c5923ed)`()` <a id="classUNTimelineManagerDecorator_1abe640ee5d20aed0044f17b625c5923ed"></a>

This pause the timeline ticking and reset the NTimeline::CurrentTime to 0

#### `public void `[`OnEventChangedDelegate`](#classUNTimelineManagerDecorator_1aaecdbbc5de72c32131f7dcef19b0f153)`(TSharedPtr< `[`INEvent`](#classINEvent)` > Event,const `[`ENTimelineEvent`](#Timeline_8h_1aca8212740df4678d46efc8cae12ab0c9)` & EventName,const float & LocalTime,const int32 & Index)` <a id="classUNTimelineManagerDecorator_1aaecdbbc5de72c32131f7dcef19b0f153"></a>

#### `public virtual void `[`Init`](#classUNTimelineManagerDecorator_1a642cf6d81cf285ed4a79e2b98bc6484e)`(const float & InTickInterval,const FName & InLabel)` <a id="classUNTimelineManagerDecorator_1a642cf6d81cf285ed4a79e2b98bc6484e"></a>

The embedded timeline is created as subobject in the ctor. So this just gives the Label to the timeline. 
**See also**: [UNTimelineManagerDecorator()](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)

#### Parameters
* `InTickInterval` - Interval time between tick in sec 

* `InLabel` - Name of the Timeline.

#### `public virtual void `[`Serialize`](#classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831)`(FArchive & Ar)` <a id="classUNTimelineManagerDecorator_1a01229041da8701773130398dc2ce3831"></a>

It's the starting link of serialization chain for all embedded decorators. This calls UNTimelineDecorator::Serialize().

#### Parameters
* `Ar` - the FArchive used for serialization as usual.

#### `public virtual void `[`BeginDestroy`](#classUNTimelineManagerDecorator_1ab6701a003cf2311d71890fa567089024)`()` <a id="classUNTimelineManagerDecorator_1ab6701a003cf2311d71890fa567089024"></a>

This calls [FNTimelineManager::Clear()](#classFNTimelineManager_1ae40ceb3847f6876ddfcd5ce74ba3f2d9).

#### `public TArray< `[`UNEventBase`](#classUNEventBase)` * > `[`GetEvents`](#classUNTimelineManagerDecorator_1a636a2d0ac5950e0aed653f378b04e3c5)`() const` <a id="classUNTimelineManagerDecorator_1a636a2d0ac5950e0aed653f378b04e3c5"></a>

#### `public TArray< `[`UNEventBase`](#classUNEventBase)` * > `[`GetExpiredEvents`](#classUNTimelineManagerDecorator_1a1139775a870015cd3042cca73e036bae)`() const` <a id="classUNTimelineManagerDecorator_1a1139775a870015cd3042cca73e036bae"></a>

#### `public `[`UNEventBase`](#classUNEventBase)` * `[`GetEvent`](#classUNTimelineManagerDecorator_1aa975120fb17b3dc7c455c33e37cac952)`(const FString & InUID) const` <a id="classUNTimelineManagerDecorator_1aa975120fb17b3dc7c455c33e37cac952"></a>

#### `public float `[`GetCurrentTime`](#classUNTimelineManagerDecorator_1adc4d0b50faa76c955cb928750de41352)`() const` <a id="classUNTimelineManagerDecorator_1adc4d0b50faa76c955cb928750de41352"></a>

#### `public FName `[`GetLabel`](#classUNTimelineManagerDecorator_1aed6e9c7e069c9e7637076a7b235adf7f)`() const` <a id="classUNTimelineManagerDecorator_1aed6e9c7e069c9e7637076a7b235adf7f"></a>

#### `public void `[`SetLabel`](#classUNTimelineManagerDecorator_1ab37f83214580022621c695a7180a6b3c)`(const FName & Name)` <a id="classUNTimelineManagerDecorator_1ab37f83214580022621c695a7180a6b3c"></a>

A pass-through for the embedded [FNTimeline::SetLabel()](#classFNTimeline_1a423302167b09a6aa88872110f46171e3)

#### `public  `[`UFUNCTION`](#classUNTimelineManagerDecorator_1a99daa6cdb789cba6b723c5aed78f06e7)`(BlueprintCallable,BlueprintImplementableEvent,Category,meta) const` <a id="classUNTimelineManagerDecorator_1a99daa6cdb789cba6b723c5aed78f06e7"></a>

#### `public `[`UNEventBase`](#classUNEventBase)` * `[`CreateAndAddNewEvent`](#classUNTimelineManagerDecorator_1ae170074f6d2b96af0b3163d42c942b9f)`(FName InName,float InDuration,float InDelay,TSubclassOf< `[`UNEventBase`](#classUNEventBase)` > InClass)` <a id="classUNTimelineManagerDecorator_1ae170074f6d2b96af0b3163d42c942b9f"></a>

Attaches the event to the timeline stream Creates a new Event and use this timeline as the outer for this new object.

#### Parameters
* `Name` - The label of the event, can be useful for user stats & feedback 

* `Duration` - The time this event is active, 0 to almost INFINI (0 means undetermined time) 

* `Delay` - The time before this event start being active, 0 to almost INFINI (0 means "right now")

#### `public virtual void `[`Clear`](#classUNTimelineManagerDecorator_1ab6802b439e1c5aa98b520700c8175de3)`()` <a id="classUNTimelineManagerDecorator_1ab6802b439e1c5aa98b520700c8175de3"></a>

Remove all EventBases and ExpiredEventBases

#### `protected FDateTime `[`StartedAt`](#classUNTimelineManagerDecorator_1a1453e9a6eb62bc4ca4d4a4578b54d8ad) <a id="classUNTimelineManagerDecorator_1a1453e9a6eb62bc4ca4d4a4578b54d8ad"></a>

#### `protected TMap< FString, `[`UNEventBase`](#classUNEventBase)` * > `[`EventBases`](#classUNTimelineManagerDecorator_1a86a56f7689205d237836ee78439dab5e) <a id="classUNTimelineManagerDecorator_1a86a56f7689205d237836ee78439dab5e"></a>

#### `protected TMap< FString, `[`UNEventBase`](#classUNEventBase)` * > `[`ExpiredEventBases`](#classUNTimelineManagerDecorator_1a250fcce6db6fada1f1d0a9f56b7b3073) <a id="classUNTimelineManagerDecorator_1a250fcce6db6fada1f1d0a9f56b7b3073"></a>

#### `protected  `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd)`()` <a id="classUNTimelineManagerDecorator_1a4d5f21dca88b5a9bbe5a66b1e15659fd"></a>

Protected ctor to force instantiation with CreateObject() methods (factory methods). It instantiates the embedded timeline with CreateDefaultSubobject().

# class `UTimelineGameSubsystem` <a id="classUTimelineGameSubsystem"></a>

```
class UTimelineGameSubsystem
  : public UGameInstanceSubsystem
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`Initialize`](#classUTimelineGameSubsystem_1a14a7c2ad73486dfa511b212e26e25d0e)`(FSubsystemCollectionBase & Collection)` | 
`public virtual void `[`Deinitialize`](#classUTimelineGameSubsystem_1a40c6ba9388694f39779cba1b99814a49)`()` | 
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUTimelineGameSubsystem_1a0b2cf740bc7e967b4a2a1807482b9cf1)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Timeline) const` | A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).
`public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUTimelineGameSubsystem_1a4e027e6c612da55bca481f6308cacab5)`(FName Timeline) const` | A blueprint pass-through for UNTimelineClient::GetTimeline(FName Config).
`public `[`UNTimelineClient`](#classUNTimelineClient)` * `[`GetTimelineClient`](#classUTimelineGameSubsystem_1ab728f8a05298af785c36b3c2a2a1d812)`() const` | 

## Members

#### `public virtual void `[`Initialize`](#classUTimelineGameSubsystem_1a14a7c2ad73486dfa511b212e26e25d0e)`(FSubsystemCollectionBase & Collection)` <a id="classUTimelineGameSubsystem_1a14a7c2ad73486dfa511b212e26e25d0e"></a>

#### `public virtual void `[`Deinitialize`](#classUTimelineGameSubsystem_1a40c6ba9388694f39779cba1b99814a49)`()` <a id="classUTimelineGameSubsystem_1a40c6ba9388694f39779cba1b99814a49"></a>

#### `public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUTimelineGameSubsystem_1a0b2cf740bc7e967b4a2a1807482b9cf1)`(`[`FConfiguredTimeline`](#structFConfiguredTimeline)` Timeline) const` <a id="classUTimelineGameSubsystem_1a0b2cf740bc7e967b4a2a1807482b9cf1"></a>

A blueprint pass-through for UNTimelineClient::GetTimeline(FConfiguredTimeline Config).

#### Parameters
* `Timeline` - To allow having a combobox of configured timelines

#### `public `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` * `[`GetTimeline`](#classUTimelineGameSubsystem_1a4e027e6c612da55bca481f6308cacab5)`(FName Timeline) const` <a id="classUTimelineGameSubsystem_1a4e027e6c612da55bca481f6308cacab5"></a>

A blueprint pass-through for UNTimelineClient::GetTimeline(FName Config).

#### Parameters
* `Timeline` - name of the timeline

#### `public `[`UNTimelineClient`](#classUNTimelineClient)` * `[`GetTimelineClient`](#classUTimelineGameSubsystem_1ab728f8a05298af785c36b3c2a2a1d812)`() const` <a id="classUTimelineGameSubsystem_1ab728f8a05298af785c36b3c2a2a1d812"></a>

# struct `FConfiguredTimeline` <a id="structFConfiguredTimeline"></a>

This struct to create Configured Timeline and ease Timeline instantiation. This allows to associated a Timeline Name to a class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) | This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.
`public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimeline_1aa0763505594b494c99c1e616ce95533b) | The Configured Timeline class
`public inline FORCEINLINE void `[`Serialize`](#structFConfiguredTimeline_1a9da6d535a5251f9ca64f0187205d7959)`(FArchive & Ar)` | 
`public inline FORCEINLINE uint32 `[`GetTypeHash`](#structFConfiguredTimeline_1a01d0e1fcd4c07f74d1ac7c37aea4798e)`() const` | 

## Members

#### `public FName `[`Name`](#structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6) <a id="structFConfiguredTimeline_1a47f13a6768b6cf144550a0a3cfb1e6b6"></a>

This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.

#### `public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimeline_1aa0763505594b494c99c1e616ce95533b) <a id="structFConfiguredTimeline_1aa0763505594b494c99c1e616ce95533b"></a>

The Configured Timeline class

#### `public inline FORCEINLINE void `[`Serialize`](#structFConfiguredTimeline_1a9da6d535a5251f9ca64f0187205d7959)`(FArchive & Ar)` <a id="structFConfiguredTimeline_1a9da6d535a5251f9ca64f0187205d7959"></a>

#### `public inline FORCEINLINE uint32 `[`GetTypeHash`](#structFConfiguredTimeline_1a01d0e1fcd4c07f74d1ac7c37aea4798e)`() const` <a id="structFConfiguredTimeline_1a01d0e1fcd4c07f74d1ac7c37aea4798e"></a>

# struct `FConfiguredTimelineConf` <a id="structFConfiguredTimelineConf"></a>

This struct to create Configured Timeline and ease Timeline instantiation. This allows to associated a Timeline Name to a class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FName `[`Name`](#structFConfiguredTimelineConf_1a50b49283e97d44dba511bfe696c818bc) | This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.
`public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimelineConf_1adc85551cc214da691536b3ca60045896) | The Configured Timeline class
`public float `[`TickInterval`](#structFConfiguredTimelineConf_1a237b9ef8f53f8d1dd4072a6befffbf76) | You can use this to add more or less frequency between each tick.
`public bool `[`bDebug`](#structFConfiguredTimelineConf_1a6ea42d3fb2649166a981232d0e139d01) | Will debug this timeline

## Members

#### `public FName `[`Name`](#structFConfiguredTimelineConf_1a50b49283e97d44dba511bfe696c818bc) <a id="structFConfiguredTimelineConf_1a50b49283e97d44dba511bfe696c818bc"></a>

This allows to retrieve easily a timeline. This is used by the [SConfiguredTimelinePin](#classSConfiguredTimelinePin) as a combobox.

#### `public TSubclassOf< `[`UNTimelineManagerDecorator`](#classUNTimelineManagerDecorator)` > `[`TimelineClass`](#structFConfiguredTimelineConf_1adc85551cc214da691536b3ca60045896) <a id="structFConfiguredTimelineConf_1adc85551cc214da691536b3ca60045896"></a>

The Configured Timeline class

#### `public float `[`TickInterval`](#structFConfiguredTimelineConf_1a237b9ef8f53f8d1dd4072a6befffbf76) <a id="structFConfiguredTimelineConf_1a237b9ef8f53f8d1dd4072a6befffbf76"></a>

You can use this to add more or less frequency between each tick.

#### `public bool `[`bDebug`](#structFConfiguredTimelineConf_1a6ea42d3fb2649166a981232d0e139d01) <a id="structFConfiguredTimelineConf_1a6ea42d3fb2649166a981232d0e139d01"></a>

Will debug this timeline

# struct `FEventSlot` <a id="structFEventSlot"></a>

All details about an event to draw

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`PreOffset`](#structFEventSlot_1abaf36b6ee734c1659b16aba9317bf314) | Represents the moment this event has been attached if it has a delay.
`public float `[`PreSize`](#structFEventSlot_1a203f2f9e045aae992c374f1cb3f30bcf) | If there is, the size of the delay.
`public FColor `[`PreColor`](#structFEventSlot_1aa764d4eaa71e5a7ab74e57455f7f1a74) | Color of the delay.
`public float `[`Offset`](#structFEventSlot_1a7e0b414b2548872657e271f37ca9f134) | Represents the moment this event start to play.
`public float `[`Size`](#structFEventSlot_1a676d69f33c99dfdde563e4cd6e2eb784) | Represents the event duration.
`public FColor `[`Color`](#structFEventSlot_1ab5279f3f640d369c4d2bfb7406ecebb2) | Color of the event.
`public const `[`UNEventBase`](#classUNEventBase)` * `[`Event`](#structFEventSlot_1a987afd5388cd7f887b8dca21264354ae) | Event associated to this slot.
`public inline  `[`FEventSlot`](#structFEventSlot_1aa302f91f55b7a5dda20b15efdcb21897)`(const `[`UNEventBase`](#classUNEventBase)` * InEvent)` | 

## Members

#### `public float `[`PreOffset`](#structFEventSlot_1abaf36b6ee734c1659b16aba9317bf314) <a id="structFEventSlot_1abaf36b6ee734c1659b16aba9317bf314"></a>

Represents the moment this event has been attached if it has a delay.

#### `public float `[`PreSize`](#structFEventSlot_1a203f2f9e045aae992c374f1cb3f30bcf) <a id="structFEventSlot_1a203f2f9e045aae992c374f1cb3f30bcf"></a>

If there is, the size of the delay.

#### `public FColor `[`PreColor`](#structFEventSlot_1aa764d4eaa71e5a7ab74e57455f7f1a74) <a id="structFEventSlot_1aa764d4eaa71e5a7ab74e57455f7f1a74"></a>

Color of the delay.

#### `public float `[`Offset`](#structFEventSlot_1a7e0b414b2548872657e271f37ca9f134) <a id="structFEventSlot_1a7e0b414b2548872657e271f37ca9f134"></a>

Represents the moment this event start to play.

#### `public float `[`Size`](#structFEventSlot_1a676d69f33c99dfdde563e4cd6e2eb784) <a id="structFEventSlot_1a676d69f33c99dfdde563e4cd6e2eb784"></a>

Represents the event duration.

#### `public FColor `[`Color`](#structFEventSlot_1ab5279f3f640d369c4d2bfb7406ecebb2) <a id="structFEventSlot_1ab5279f3f640d369c4d2bfb7406ecebb2"></a>

Color of the event.

#### `public const `[`UNEventBase`](#classUNEventBase)` * `[`Event`](#structFEventSlot_1a987afd5388cd7f887b8dca21264354ae) <a id="structFEventSlot_1a987afd5388cd7f887b8dca21264354ae"></a>

Event associated to this slot.

#### `public inline  `[`FEventSlot`](#structFEventSlot_1aa302f91f55b7a5dda20b15efdcb21897)`(const `[`UNEventBase`](#classUNEventBase)` * InEvent)` <a id="structFEventSlot_1aa302f91f55b7a5dda20b15efdcb21897"></a>

# struct `FEventsRow` <a id="structFEventsRow"></a>

Saved data when timeline are paint. 
**See also**: [SNTimeline::OnPaint()](#classSNTimeline_1ac55ba4f82b5f5cc290751e3a83442b50)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TArray< `[`FEventSlot`](#structFEventSlot)` > `[`Slots`](#structFEventsRow_1a1d2ca14268d1dbafa8733ea635f18513) | The slots saved in this row.
`public bool `[`AddSlot`](#structFEventsRow_1a3dbd8e7fa9f695a47b249cfbedf651ef)`(`[`FEventSlot`](#structFEventSlot)` && InSlot)` | Try to add the slot. 
`public `[`FEventSlot`](#structFEventSlot)` * `[`IsEventAdded`](#structFEventsRow_1affb97d5c7b837bef40714c18a6fe5eae)`(const `[`UNEventBase`](#classUNEventBase)` * Event)` | Checks if this event has been already added in any slot.

## Members

#### `public TArray< `[`FEventSlot`](#structFEventSlot)` > `[`Slots`](#structFEventsRow_1a1d2ca14268d1dbafa8733ea635f18513) <a id="structFEventsRow_1a1d2ca14268d1dbafa8733ea635f18513"></a>

The slots saved in this row.

#### `public bool `[`AddSlot`](#structFEventsRow_1a3dbd8e7fa9f695a47b249cfbedf651ef)`(`[`FEventSlot`](#structFEventSlot)` && InSlot)` <a id="structFEventsRow_1a3dbd8e7fa9f695a47b249cfbedf651ef"></a>

Try to add the slot. 
#### Returns
true if added or false if 1. , 2. no places available for it

#### `public `[`FEventSlot`](#structFEventSlot)` * `[`IsEventAdded`](#structFEventsRow_1affb97d5c7b837bef40714c18a6fe5eae)`(const `[`UNEventBase`](#classUNEventBase)` * Event)` <a id="structFEventsRow_1affb97d5c7b837bef40714c18a6fe5eae"></a>

Checks if this event has been already added in any slot.

# struct `FParamsEventChanged` <a id="structFParamsEventChanged"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`InLocalTime`](#structFParamsEventChanged_1a29559444953df366c6dc8f91ab390ab6) | 
`public UWorld * `[`InWorld`](#structFParamsEventChanged_1a267049147edc19505815e88a04c4f570) | 
`public APlayerController * `[`InPlayer`](#structFParamsEventChanged_1a0a701230b8a0ce82cbc6dbb7b90e5ed2) | 

## Members

#### `public float `[`InLocalTime`](#structFParamsEventChanged_1a29559444953df366c6dc8f91ab390ab6) <a id="structFParamsEventChanged_1a29559444953df366c6dc8f91ab390ab6"></a>

#### `public UWorld * `[`InWorld`](#structFParamsEventChanged_1a267049147edc19505815e88a04c4f570) <a id="structFParamsEventChanged_1a267049147edc19505815e88a04c4f570"></a>

#### `public APlayerController * `[`InPlayer`](#structFParamsEventChanged_1a0a701230b8a0ce82cbc6dbb7b90e5ed2) <a id="structFParamsEventChanged_1a0a701230b8a0ce82cbc6dbb7b90e5ed2"></a>

# struct `FTimelineData` <a id="structFTimelineData"></a>

Saved data when timeline are paint. 
**See also**: [SNTimeline::OnPaint()](#classSNTimeline_1ac55ba4f82b5f5cc290751e3a83442b50)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public TArray< `[`FEventsRow`](#structFEventsRow)` > `[`Rows`](#structFTimelineData_1a7dde1d040c858b9c8ab2bf212be0d368) | The rows where event's slot ([FEventSlot](#structFEventSlot)) are saved.
`public float `[`MaxTime`](#structFTimelineData_1aca228abf5a2644ddd44f6a6cb80acd1d) | The current timeline time + events in the future.
`public int32 `[`Owners`](#structFTimelineData_1a2cbb1da2b758d940ca8c8a7e3d8f748a) | Used to know if it can be destroyed.
`public `[`FEventSlot`](#structFEventSlot)` * `[`IsEventAdded`](#structFTimelineData_1aec6fcfc94a52447af00f66b8303abbe2)`(const `[`UNEventBase`](#classUNEventBase)` * Event)` | Checks if this event has been already added in any row's slot.
`public void `[`AddSlot`](#structFTimelineData_1ae2ba91f3be42dca735fef752d761ccf3)`(`[`FEventSlot`](#structFEventSlot)` && Slot)` | Try to put this slot in an available row ([FEventsRow](#structFEventsRow)) or create a new one if not already added in a row.

## Members

#### `public TArray< `[`FEventsRow`](#structFEventsRow)` > `[`Rows`](#structFTimelineData_1a7dde1d040c858b9c8ab2bf212be0d368) <a id="structFTimelineData_1a7dde1d040c858b9c8ab2bf212be0d368"></a>

The rows where event's slot ([FEventSlot](#structFEventSlot)) are saved.

#### `public float `[`MaxTime`](#structFTimelineData_1aca228abf5a2644ddd44f6a6cb80acd1d) <a id="structFTimelineData_1aca228abf5a2644ddd44f6a6cb80acd1d"></a>

The current timeline time + events in the future.

#### `public int32 `[`Owners`](#structFTimelineData_1a2cbb1da2b758d940ca8c8a7e3d8f748a) <a id="structFTimelineData_1a2cbb1da2b758d940ca8c8a7e3d8f748a"></a>

Used to know if it can be destroyed.

#### `public `[`FEventSlot`](#structFEventSlot)` * `[`IsEventAdded`](#structFTimelineData_1aec6fcfc94a52447af00f66b8303abbe2)`(const `[`UNEventBase`](#classUNEventBase)` * Event)` <a id="structFTimelineData_1aec6fcfc94a52447af00f66b8303abbe2"></a>

Checks if this event has been already added in any row's slot.

#### `public void `[`AddSlot`](#structFTimelineData_1ae2ba91f3be42dca735fef752d761ccf3)`(`[`FEventSlot`](#structFEventSlot)` && Slot)` <a id="structFTimelineData_1ae2ba91f3be42dca735fef752d761ccf3"></a>

Try to put this slot in an available row ([FEventsRow](#structFEventsRow)) or create a new one if not already added in a row.

Generated by [Moxygen](https://sourcey.com/moxygen)