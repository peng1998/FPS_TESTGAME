// This code was written by 康子秋

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPS_TESTGAMEGameState.generated.h"

UENUM(BlueprintType)
enum class EWaveState : uint8
{
	WaitingToStart,

	WaveInProgress,

	WaitingToComplete,

	WaveComplete,

	GamePause,

	GameWin,

	GameLose,

};

UCLASS()
class FPS_TESTGAME_API AFPS_TESTGAMEGameState : public AGameStateBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_WaveState,Category = "GameState")
		EWaveState WaveState;

	UFUNCTION(BlueprintImplementableEvent, Category = "GameState")
		void WaveStateChanged(EWaveState NawState, EWaveState OldState);

	UFUNCTION()
		void OnRep_WaveState(EWaveState OldState);
private:

public:

	void SetWaveState(EWaveState NewState);

};
