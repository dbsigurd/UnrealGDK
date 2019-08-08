// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "TypeStructure.h"
#include "Utils/SchemaDatabase.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSchemaGenerator, Log, All);

class FCodeWriter;
struct FComponentIdGenerator;

extern TArray<FString> SchemaGeneratedClassPaths;
extern TMap<FString, FActorSchemaData> ActorClassPathToSchema;
extern TMap<FString, FSubobjectSchemaData> SubobjectClassPathToSchema;
extern TMap<FString, uint32> LevelPathToComponentId;

// Generates schema for an Actor
void GenerateActorSchema(FComponentIdGenerator& IdGenerator, TSharedPtr<FUnrealType> TypeInfo, FString SchemaPath);
// Generates schema for a Subobject class - the schema type and the dynamic schema components
void GenerateSubobjectSchema(FComponentIdGenerator& IdGenerator, TSharedPtr<FUnrealType> TypeInfo, FString SchemaPath);
// Generates schema for all statically attached subobjects on an Actor.
void GenerateSubobjectSchemaForActor(FComponentIdGenerator& IdGenerator, TSharedPtr<FUnrealType> TypeInfo,
	FString SchemaPath, FActorSchemaData& ActorSchemaData, const FActorSchemaData* ExistingSchemaData);
// Generates schema for a statically attached subobject on an Actor - called by GenerateSubobjectSchemaForActor.
FActorSpecificSubobjectSchemaData GenerateSchemaForStaticallyAttachedSubobject(FCodeWriter& Writer, FComponentIdGenerator& IdGenerator,
	FString PropertyName, TSharedPtr<FUnrealType>& TypeInfo, TSharedPtr<FUnrealType>& ActorTypeInfo, int MapIndex,
	const FActorSpecificSubobjectSchemaData* ExistingSchemaData);
// Output the includes required by this schema file.
void GenerateSubobjectSchemaForActorIncludes(FCodeWriter& Writer, TSharedPtr<FUnrealType>& TypeInfo);
