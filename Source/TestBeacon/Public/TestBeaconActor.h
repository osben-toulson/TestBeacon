//Copyright 2020 Osben Toulson. MIT License.

#pragma once

//Beacon Includes
#include "OnlineBeaconHost.h"
#include "TestBeaconHost.h"
#include "TestBeaconClient.h"

//GConfig Include (Can be excluded if port will be determined alternatively)
#include "Misc/ConfigCacheIni.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestBeaconActor.generated.h"

UCLASS()
class TESTBEACON_API ATestBeaconActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestBeaconActor();

private:
	AOnlineBeaconHost* OnlineBeaconHost;
	ATestBeaconHost* TestBeaconHost;
	ATestBeaconClient* TestBeaconClient;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
