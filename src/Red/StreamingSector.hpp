#pragma once

namespace Red
{
struct __declspec(align(0x10)) CompiledNodeInstanceSetupInfo
{
    Transform transform;               // 00
    Vector3 scale;                     // 20
    Vector3 secondaryRefPointPosition; // 2C
    Vector3 streamingRefPoint;         // 38
    Vector3 unk44;                     // 44
    worldNode* node;                   // 50
    uint64_t globalNodeID;             // 58
    uint64_t proxyNodeID;              // 60
    ResourcePath unk68;                // 68
    uint64_t nodeIndex : 19;           // 70
    uint64_t unk70 : 45;               // 70
    float secondaryRefPointDistance;   // 78
    float streamingDistance;           // 7C
    uint32_t unk80;                    // 80
    uint32_t unk84;                    // 84
    uint64_t unk88;                    // 88
};
RED4EXT_ASSERT_SIZE(CompiledNodeInstanceSetupInfo, 0x90);
RED4EXT_ASSERT_OFFSET(CompiledNodeInstanceSetupInfo, node, 0x50);
RED4EXT_ASSERT_OFFSET(CompiledNodeInstanceSetupInfo, globalNodeID, 0x58);
RED4EXT_ASSERT_OFFSET(CompiledNodeInstanceSetupInfo, secondaryRefPointDistance, 0x78);

struct CompiledNodeInstanceSetupInfoBuffer : DataBuffer
{
    [[nodiscard]] inline CompiledNodeInstanceSetupInfo* begin() const
    {
        return reinterpret_cast<CompiledNodeInstanceSetupInfo*>(buffer.data);
    }

    [[nodiscard]] inline CompiledNodeInstanceSetupInfo* end() const
    {
        return reinterpret_cast<CompiledNodeInstanceSetupInfo*>(reinterpret_cast<uintptr_t>(buffer.data) +
                                                                buffer.size);
    }

    CompiledNodeInstanceSetupInfo* GetInstance(int64_t aIndex)
    {
        return begin() + aIndex;
    }

    uint32_t GetInstanceCount()
    {
        return buffer.size / sizeof(CompiledNodeInstanceSetupInfo);
    }
};
RED4EXT_ASSERT_SIZE(CompiledNodeInstanceSetupInfoBuffer, 0x28);

struct StreamingSectorNodeBuffer
{
    CompiledNodeInstanceSetupInfoBuffer nodeSetups; // 00
    uint32_t version;                               // 28
    DynArray<Handle<worldNode>> nodes;              // 30
    DynArray<NodeRef> nodeRefs;                     // 40
};
RED4EXT_ASSERT_OFFSET(StreamingSectorNodeBuffer, nodes, 0x30);
RED4EXT_ASSERT_OFFSET(StreamingSectorNodeBuffer, nodeRefs, 0x40);
RED4EXT_ASSERT_SIZE(StreamingSectorNodeBuffer, 0x50);
}

namespace Raw::StreamingSector
{
using NodeBuffer = Core::OffsetPtr<0x40, Red::StreamingSectorNodeBuffer>;
}
