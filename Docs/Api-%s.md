# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FNansTimelineSystemCoreModule`](#classFNansTimelineSystemCoreModule) | 
`class `[`FNansTimelineSystemModuleUE4`](#classFNansTimelineSystemModuleUE4) | 
`class `[`INTimelineEventInterface`](#classINTimelineEventInterface) | 
`class `[`NansTimelineSystemCore`](#classNansTimelineSystemCore) | 
`class `[`NansTimelineSystemUE4`](#classNansTimelineSystemUE4) | 
`class `[`NTimelineAbstract`](#classNTimelineAbstract) | 
`class `[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract) | 

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

# class `FNansTimelineSystemModuleUE4` <a id="classFNansTimelineSystemModuleUE4"></a>

```
class FNansTimelineSystemModuleUE4
  : public IModuleInterface
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual void `[`StartupModule`](#classFNansTimelineSystemModuleUE4_1af26900e53efda38264ba0fe700e6068c)`()` | IModuleInterface implementation
`public virtual void `[`ShutdownModule`](#classFNansTimelineSystemModuleUE4_1a5d8c14dfb067608d561639f2107f72d7)`()` | 

## Members

#### `public virtual void `[`StartupModule`](#classFNansTimelineSystemModuleUE4_1af26900e53efda38264ba0fe700e6068c)`()` <a id="classFNansTimelineSystemModuleUE4_1af26900e53efda38264ba0fe700e6068c"></a>

IModuleInterface implementation

#### `public virtual void `[`ShutdownModule`](#classFNansTimelineSystemModuleUE4_1a5d8c14dfb067608d561639f2107f72d7)`()` <a id="classFNansTimelineSystemModuleUE4_1a5d8c14dfb067608d561639f2107f72d7"></a>

# class `INTimelineEventInterface` <a id="classINTimelineEventInterface"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual bool `[`IsExpired`](#classINTimelineEventInterface_1a69d086b7833e47fe3fc8f6d58f4d5236)`() const` | 
`public const float `[`GetCurrentTime`](#classINTimelineEventInterface_1a3a233bf12d0f1e6f96f820df8494b26a)`() const` | Should be great to have a doc
`public const float `[`GetStartedAt`](#classINTimelineEventInterface_1a268cf627a8ff503feaf9fcca18ecc439)`() const` | 
`public float `[`GetDuration`](#classINTimelineEventInterface_1a7a6466302e5d9c7ff8d5d28d5dfebd77)`() const` | 
`public float `[`GetDelay`](#classINTimelineEventInterface_1ac101339301e10a704bb0dfd1b4b289b4)`() const` | 
`public void `[`SetStartedAt`](#classINTimelineEventInterface_1a0c84052dc13ee3877c604f909b215ebe)`(float StartTime)` | 
`public void `[`NotifyAddTime`](#classINTimelineEventInterface_1ab60fc9df42167e03a8a83fd1cac9b8b7)`(float StartTime)` | 
`public const FName `[`GetEventLabel`](#classINTimelineEventInterface_1a1269ee20c8491567cfdd06b0179bc24a)`()` | 

## Members

#### `public inline virtual bool `[`IsExpired`](#classINTimelineEventInterface_1a69d086b7833e47fe3fc8f6d58f4d5236)`() const` <a id="classINTimelineEventInterface_1a69d086b7833e47fe3fc8f6d58f4d5236"></a>

#### `public const float `[`GetCurrentTime`](#classINTimelineEventInterface_1a3a233bf12d0f1e6f96f820df8494b26a)`() const` <a id="classINTimelineEventInterface_1a3a233bf12d0f1e6f96f820df8494b26a"></a>

Should be great to have a doc

#### `public const float `[`GetStartedAt`](#classINTimelineEventInterface_1a268cf627a8ff503feaf9fcca18ecc439)`() const` <a id="classINTimelineEventInterface_1a268cf627a8ff503feaf9fcca18ecc439"></a>

#### `public float `[`GetDuration`](#classINTimelineEventInterface_1a7a6466302e5d9c7ff8d5d28d5dfebd77)`() const` <a id="classINTimelineEventInterface_1a7a6466302e5d9c7ff8d5d28d5dfebd77"></a>

#### `public float `[`GetDelay`](#classINTimelineEventInterface_1ac101339301e10a704bb0dfd1b4b289b4)`() const` <a id="classINTimelineEventInterface_1ac101339301e10a704bb0dfd1b4b289b4"></a>

#### `public void `[`SetStartedAt`](#classINTimelineEventInterface_1a0c84052dc13ee3877c604f909b215ebe)`(float StartTime)` <a id="classINTimelineEventInterface_1a0c84052dc13ee3877c604f909b215ebe"></a>

#### `public void `[`NotifyAddTime`](#classINTimelineEventInterface_1ab60fc9df42167e03a8a83fd1cac9b8b7)`(float StartTime)` <a id="classINTimelineEventInterface_1ab60fc9df42167e03a8a83fd1cac9b8b7"></a>

#### `public const FName `[`GetEventLabel`](#classINTimelineEventInterface_1a1269ee20c8491567cfdd06b0179bc24a)`()` <a id="classINTimelineEventInterface_1a1269ee20c8491567cfdd06b0179bc24a"></a>

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

# class `NTimelineAbstract` <a id="classNTimelineAbstract"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`~NTimelineAbstract`](#classNTimelineAbstract_1a9d57093f7bd3bb5d2f4923d1c602cdb3)`()` | 
`public void `[`Attached`](#classNTimelineAbstract_1a935dc10a9a4f272036491da8aed76db9)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event)` | 
`protected FName `[`Label`](#classNTimelineAbstract_1a1dd5ccb4375fa004149b24a72c4f30f4) | The name of this timeline
`protected TUniquePtr< `[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract)` > `[`Timer`](#classNTimelineAbstract_1acefddbc5b6ef2b93b6a1a7e6833f940f) | This is by this object we can control time behavior (play, stop, etc,..). But it also garanty to tick the timeline when itself it ticks.
`protected void `[`SaveTimer`](#classNTimelineAbstract_1a946b329212a7864368fd70b06fc7c9a2)`(`[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract)` * Timer)` | Timer is owned by the timeline doing this. BTW this should be the only way to save a timer for this timeline to garanty the behavior consistancy between them.
`protected inline virtual bool `[`BeforeOnAttached`](#classNTimelineAbstract_1a1423abdbb2ae8678ab78f68295ad0b91)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event,const float AttachedTime)` | 
`protected virtual void `[`AfterOnAttached`](#classNTimelineAbstract_1a27dc2aacb9cea21c34f4d80ce9d1556b)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event,const float AttachedTime)` | 
`protected inline virtual const float & `[`GetTickDelta`](#classNTimelineAbstract_1a19cabbb9c3100180ce999ae2c9b5d9df)`() const` | This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.
`protected virtual void `[`OnExpired`](#classNTimelineAbstract_1ad00c021816f9a86a5618b8d82dd5cee9)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event,const float AttachedTime)` | Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference
`protected inline const TArray< FEventTuple > `[`GetEvents`](#classNTimelineAbstract_1a27ed62e86f3a403e8804b547c5f94408)`() const` | 
`protected void `[`Reset`](#classNTimelineAbstract_1a50f5e6140fec9968a0096f2f856b266d)`()` | This completely reset every events. Is should be used internally, a timeline should manage its duration itself.

## Members

#### `public  `[`~NTimelineAbstract`](#classNTimelineAbstract_1a9d57093f7bd3bb5d2f4923d1c602cdb3)`()` <a id="classNTimelineAbstract_1a9d57093f7bd3bb5d2f4923d1c602cdb3"></a>

#### `public void `[`Attached`](#classNTimelineAbstract_1a935dc10a9a4f272036491da8aed76db9)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event)` <a id="classNTimelineAbstract_1a935dc10a9a4f272036491da8aed76db9"></a>

#### `protected FName `[`Label`](#classNTimelineAbstract_1a1dd5ccb4375fa004149b24a72c4f30f4) <a id="classNTimelineAbstract_1a1dd5ccb4375fa004149b24a72c4f30f4"></a>

The name of this timeline

#### `protected TUniquePtr< `[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract)` > `[`Timer`](#classNTimelineAbstract_1acefddbc5b6ef2b93b6a1a7e6833f940f) <a id="classNTimelineAbstract_1acefddbc5b6ef2b93b6a1a7e6833f940f"></a>

This is by this object we can control time behavior (play, stop, etc,..). But it also garanty to tick the timeline when itself it ticks.

#### `protected void `[`SaveTimer`](#classNTimelineAbstract_1a946b329212a7864368fd70b06fc7c9a2)`(`[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract)` * Timer)` <a id="classNTimelineAbstract_1a946b329212a7864368fd70b06fc7c9a2"></a>

Timer is owned by the timeline doing this. BTW this should be the only way to save a timer for this timeline to garanty the behavior consistancy between them.

#### `protected inline virtual bool `[`BeforeOnAttached`](#classNTimelineAbstract_1a1423abdbb2ae8678ab78f68295ad0b91)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event,const float AttachedTime)` <a id="classNTimelineAbstract_1a1423abdbb2ae8678ab78f68295ad0b91"></a>

#### `protected virtual void `[`AfterOnAttached`](#classNTimelineAbstract_1a27dc2aacb9cea21c34f4d80ce9d1556b)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event,const float AttachedTime)` <a id="classNTimelineAbstract_1a27dc2aacb9cea21c34f4d80ce9d1556b"></a>

#### `protected inline virtual const float & `[`GetTickDelta`](#classNTimelineAbstract_1a19cabbb9c3100180ce999ae2c9b5d9df)`() const` <a id="classNTimelineAbstract_1a19cabbb9c3100180ce999ae2c9b5d9df"></a>

This is the value required by a timer to know the tick frequency for this timeline. The NotifyTick use this method to add time on CurrentTime at each call.

#### `protected virtual void `[`OnExpired`](#classNTimelineAbstract_1ad00c021816f9a86a5618b8d82dd5cee9)`(TSharedPtr< `[`INTimelineEventInterface`](#classINTimelineEventInterface)` > Event,const float AttachedTime)` <a id="classNTimelineAbstract_1ad00c021816f9a86a5618b8d82dd5cee9"></a>

Use Event SharedPtr with caution, it's pointer is reset just after this method is called. the Event should be used internally only to avoid nullptr reference

#### `protected inline const TArray< FEventTuple > `[`GetEvents`](#classNTimelineAbstract_1a27ed62e86f3a403e8804b547c5f94408)`() const` <a id="classNTimelineAbstract_1a27ed62e86f3a403e8804b547c5f94408"></a>

#### `protected void `[`Reset`](#classNTimelineAbstract_1a50f5e6140fec9968a0096f2f856b266d)`()` <a id="classNTimelineAbstract_1a50f5e6140fec9968a0096f2f856b266d"></a>

This completely reset every events. Is should be used internally, a timeline should manage its duration itself.

# class `NTimelineTimerAbstract` <a id="classNTimelineTimerAbstract"></a>

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`~NTimelineTimerAbstract`](#classNTimelineTimerAbstract_1a0d7f1ceb8feeb9073e31745df204722c)`()` | 
`public void `[`Pause`](#classNTimelineTimerAbstract_1abbe80fa80ab7cae1850dc39bcc340b11)`()` | 
`public void `[`Play`](#classNTimelineTimerAbstract_1aab017ff366e54808391d836b3ca13b44)`()` | 
`public void `[`Stop`](#classNTimelineTimerAbstract_1a75c9f8069c77ab05e331ef6935e35c7d)`()` | 
`public void `[`TimerTick`](#classNTimelineTimerAbstract_1a1dd5970d46ccca6e03bb137f7714b2d2)`()` | 
`protected TSharedPtr< `[`NTimelineAbstract`](#classNTimelineAbstract)` > `[`Timeline`](#classNTimelineTimerAbstract_1a962a9b2592a7a5a58df134bc9872cf32) | 
`protected inline  `[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract_1a1adcd0209bc8c76a8e6a3aa838dbb275)`(`[`NTimelineAbstract`](#classNTimelineAbstract)` * _Timeline)` | Only accept friend to instanciate it. This to force its instanciation in derived class of [NTimelineAbstract](#classNTimelineAbstract).
`protected void `[`Clear`](#classNTimelineTimerAbstract_1a6394747479f31e0a8a45278ddf489073)`()` | 
`protected void `[`Start`](#classNTimelineTimerAbstract_1a647657f7878a3b8e311af0b111f30c7e)`()` | 
`protected void `[`SetDeltaTick`](#classNTimelineTimerAbstract_1adeda6e415a6e1de5da91622fcb055949)`(float TickDelta)` | 

## Members

#### `public  `[`~NTimelineTimerAbstract`](#classNTimelineTimerAbstract_1a0d7f1ceb8feeb9073e31745df204722c)`()` <a id="classNTimelineTimerAbstract_1a0d7f1ceb8feeb9073e31745df204722c"></a>

#### `public void `[`Pause`](#classNTimelineTimerAbstract_1abbe80fa80ab7cae1850dc39bcc340b11)`()` <a id="classNTimelineTimerAbstract_1abbe80fa80ab7cae1850dc39bcc340b11"></a>

#### `public void `[`Play`](#classNTimelineTimerAbstract_1aab017ff366e54808391d836b3ca13b44)`()` <a id="classNTimelineTimerAbstract_1aab017ff366e54808391d836b3ca13b44"></a>

#### `public void `[`Stop`](#classNTimelineTimerAbstract_1a75c9f8069c77ab05e331ef6935e35c7d)`()` <a id="classNTimelineTimerAbstract_1a75c9f8069c77ab05e331ef6935e35c7d"></a>

#### `public void `[`TimerTick`](#classNTimelineTimerAbstract_1a1dd5970d46ccca6e03bb137f7714b2d2)`()` <a id="classNTimelineTimerAbstract_1a1dd5970d46ccca6e03bb137f7714b2d2"></a>

#### `protected TSharedPtr< `[`NTimelineAbstract`](#classNTimelineAbstract)` > `[`Timeline`](#classNTimelineTimerAbstract_1a962a9b2592a7a5a58df134bc9872cf32) <a id="classNTimelineTimerAbstract_1a962a9b2592a7a5a58df134bc9872cf32"></a>

#### `protected inline  `[`NTimelineTimerAbstract`](#classNTimelineTimerAbstract_1a1adcd0209bc8c76a8e6a3aa838dbb275)`(`[`NTimelineAbstract`](#classNTimelineAbstract)` * _Timeline)` <a id="classNTimelineTimerAbstract_1a1adcd0209bc8c76a8e6a3aa838dbb275"></a>

Only accept friend to instanciate it. This to force its instanciation in derived class of [NTimelineAbstract](#classNTimelineAbstract).

#### `protected void `[`Clear`](#classNTimelineTimerAbstract_1a6394747479f31e0a8a45278ddf489073)`()` <a id="classNTimelineTimerAbstract_1a6394747479f31e0a8a45278ddf489073"></a>

#### `protected void `[`Start`](#classNTimelineTimerAbstract_1a647657f7878a3b8e311af0b111f30c7e)`()` <a id="classNTimelineTimerAbstract_1a647657f7878a3b8e311af0b111f30c7e"></a>

#### `protected void `[`SetDeltaTick`](#classNTimelineTimerAbstract_1adeda6e415a6e1de5da91622fcb055949)`(float TickDelta)` <a id="classNTimelineTimerAbstract_1adeda6e415a6e1de5da91622fcb055949"></a>

Generated by [Moxygen](https://sourcey.com/moxygen)