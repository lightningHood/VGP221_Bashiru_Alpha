// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSEnemy.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"

// Sets default values
AFPSEnemy::AFPSEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.0f;

	MySphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	MySphereComponent->InitSphereRadius(100.f);
	MySphereComponent->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = MySphereComponent;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MY MESH"));
	MyMesh->SetupAttachment(RootComponent);


	MySphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSEnemy::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AFPSEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

void AFPSEnemy::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}