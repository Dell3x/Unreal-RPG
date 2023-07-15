//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.10.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef LIVECODINGMODEL_GENERATED_H
#define LIVECODINGMODEL_GENERATED_H


#include "protocol/Protocol.h"
#include "types/DateTime.h"
#include "impl/RdSignal.h"
#include "impl/RdProperty.h"
#include "impl/RdList.h"
#include "impl/RdSet.h"
#include "impl/RdMap.h"
#include "base/ISerializersOwner.h"
#include "base/IUnknownInstance.h"
#include "serialization/ISerializable.h"
#include "serialization/Polymorphic.h"
#include "serialization/NullableSerializer.h"
#include "serialization/ArraySerializer.h"
#include "serialization/InternedSerializer.h"
#include "serialization/SerializationCtx.h"
#include "serialization/Serializers.h"
#include "ext/RdExtBase.h"
#include "task/RdCall.h"
#include "task/RdEndpoint.h"
#include "task/RdSymmetricCall.h"
#include "std/to_string.h"
#include "std/hash.h"
#include "std/allocator.h"
#include "util/enum.h"
#include "util/gen_util.h"

#include <cstring>
#include <cstdint>
#include <vector>
#include <ctime>

#include "thirdparty.hpp"
#include "instantiations_RdEditorRoot.h"

#include "RdEditorModel/RdEditorModel.Generated.h"

#include "UE4TypesMarshallers.h"


#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
#pragma warning( disable:4100 )
#endif

/// <summary>
/// <p>Generated from: LiveCodingModel.kt:6</p>
/// </summary>
namespace JetBrains {
namespace EditorPlugin {

class RIDERLINK_API LiveCodingModel : public rd::RdExtBase {

public:
    struct LiveCodingModelSerializersOwner final : public rd::ISerializersOwner {
        void registerSerializersCore(rd::Serializers const& serializers) const override;
    };
    
    static const LiveCodingModelSerializersOwner serializersOwner;
    
    

public:
    
    // extension
    static LiveCodingModel const & getOrCreateExtensionOf(RdEditorModel & pointcut);

private:
    // custom serializers

public:
    // constants

protected:
    // fields
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_IsEnabledByDefault_;
    rd::RdSignal<bool, rd::Polymorphic<bool>> lC_EnableByDefault_;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_IsEnabledForSession_;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_CanEnableForSession_;
    rd::RdSignal<bool, rd::Polymorphic<bool>> lC_EnableForSession_;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_IsCompiling_;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_HasStarted_;
    rd::RdSignal<rd::Void, rd::Polymorphic<rd::Void>> lC_Compile_;
    rd::RdSignal<rd::Void, rd::Polymorphic<rd::Void>> lC_OnPatchComplete_;
    

private:
    // initializer
    void initialize();

public:
    // primary ctor
    LiveCodingModel(rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_IsEnabledByDefault_, rd::RdSignal<bool, rd::Polymorphic<bool>> lC_EnableByDefault_, rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_IsEnabledForSession_, rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_CanEnableForSession_, rd::RdSignal<bool, rd::Polymorphic<bool>> lC_EnableForSession_, rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_IsCompiling_, rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> lC_HasStarted_, rd::RdSignal<rd::Void, rd::Polymorphic<rd::Void>> lC_Compile_, rd::RdSignal<rd::Void, rd::Polymorphic<rd::Void>> lC_OnPatchComplete_);
    
    // default ctors and dtors
    
    LiveCodingModel();
    
    LiveCodingModel(LiveCodingModel &&) = delete;
    
    LiveCodingModel& operator=(LiveCodingModel &&) = delete;
    
    virtual ~LiveCodingModel() = default;
    
    // reader
    
    // writer
    
    // virtual init
    void init(rd::Lifetime lifetime) const override;
    
    // identify
    void identify(const rd::Identities &identities, rd::RdId const &id) const override;
    
    // getters
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> const & get_lC_IsEnabledByDefault() const;
    rd::ISource<bool> const & get_lC_EnableByDefault() const;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> const & get_lC_IsEnabledForSession() const;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> const & get_lC_CanEnableForSession() const;
    rd::ISource<bool> const & get_lC_EnableForSession() const;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> const & get_lC_IsCompiling() const;
    rd::RdEndpoint<rd::Void, bool, rd::Polymorphic<rd::Void>, rd::Polymorphic<bool>> const & get_lC_HasStarted() const;
    rd::ISource<rd::Void> const & get_lC_Compile() const;
    rd::ISignal<rd::Void> const & get_lC_OnPatchComplete() const;
    
    // intern

private:
    // equals trait

public:
    // equality operators
    friend bool operator==(const LiveCodingModel &lhs, const LiveCodingModel &rhs);
    friend bool operator!=(const LiveCodingModel &lhs, const LiveCodingModel &rhs);
    // hash code trait
    // type name trait
    // static type name trait

private:
    // polymorphic to string
    std::string toString() const override;

public:
    // external to string
    friend std::string to_string(const LiveCodingModel & value);
};

}
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif



#endif // LIVECODINGMODEL_GENERATED_H
