// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBeaconActor.h"

// Sets default values
ATestBeaconActor::ATestBeaconActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestBeaconActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (this->HasAuthority())
	{
		// Spawn Online Beacon and TestBeaconHost (child of AOnlineBeaconHostObject)
		OnlineBeaconHost = World->SpawnActor<AOnlineBeaconHost>(AOnlineBeaconHost::StaticClass());
		TestBeaconHost = World->SpawnActor<ATestBeaconHost>(ATestBeaconHost::StaticClass());

		
		OnlineBeaconHost->InitHost();
		OnlineBeaconHost->RegisterHost(TestBeaconHost);
		OnlineBeaconHost->PauseBeaconRequests(false);

	}
	else
	{
		TestBeaconClient = World->SpawnActor<ATestBeaconClient>(ATestBeaconClient::StaticClass());
		FURL url(nullptr, *FString("127.0.0.1"), ETravelType::TRAVEL_Absolute);
		int32 portConfig;
		GConfig->GetInt(TEXT("/Script/OnlineSubsystemUtils.OnlineBeaconHost"), TEXT("ListenPort"), portConfig, GEngineIni);
		url.Port = portConfig;

		//Starts the Ping/Pong calls
		TestBeaconClient->InitClient(url);
	}
}

// Called every frame
void ATestBeaconActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

