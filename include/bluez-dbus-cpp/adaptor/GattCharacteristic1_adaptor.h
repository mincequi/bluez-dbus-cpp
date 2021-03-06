//
// Copyright Audiofile LLC 2019 - 2020.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//

#ifndef __sdbuscpp_____adaptor_GattCharacteristic1_adaptor_h__adaptor__H__
#define __sdbuscpp_____adaptor_GattCharacteristic1_adaptor_h__adaptor__H__

#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

namespace org {
namespace bluez {

class GattCharacteristic1_adaptor
{
public:
    static constexpr const char* INTERFACE_NAME = "org.bluez.GattCharacteristic1";

protected:
    GattCharacteristic1_adaptor(sdbus::IObject& object)
        : object_(object)
    {
        object_.registerMethod("ReadValue").onInterface(INTERFACE_NAME).implementedAs([this](const std::map<std::string, sdbus::Variant>& options){ return this->ReadValue(options); });
        object_.registerMethod("WriteValue").onInterface(INTERFACE_NAME).implementedAs([this](const std::vector<uint8_t>& value, const std::map<std::string, sdbus::Variant>& options){ return this->WriteValue(value, options); });
        //object_.registerMethod("AcquireWrite").onInterface(INTERFACE_NAME).implementedAs([this](const std::map<std::string, sdbus::Variant>& options){ return this->AcquireWrite(options); });
        //object_.registerMethod("AcquireNotify").onInterface(INTERFACE_NAME).implementedAs([this](const std::map<std::string, sdbus::Variant>& options){ return this->AcquireNotify(options); });
        object_.registerMethod("StartNotify").onInterface(INTERFACE_NAME).implementedAs([this](){ return this->StartNotify(); });
        object_.registerMethod("StopNotify").onInterface(INTERFACE_NAME).implementedAs([this](){ return this->StopNotify(); });
        object_.registerMethod("Confirm").onInterface(INTERFACE_NAME).implementedAs([this](){ return this->Confirm(); });
        object_.registerProperty("UUID").onInterface(INTERFACE_NAME).withGetter([this](){ return this->UUID(); });
        object_.registerProperty("Service").onInterface(INTERFACE_NAME).withGetter([this](){ return this->Service(); });
        object_.registerProperty("Value").onInterface(INTERFACE_NAME).withGetter([this](){ return this->Value(); });
        object_.registerProperty("Notifying").onInterface(INTERFACE_NAME).withGetter([this](){ return this->Notifying(); });
        object_.registerProperty("Flags").onInterface(INTERFACE_NAME).withGetter([this](){ return this->Flags(); });
        object_.registerProperty("Descriptors").onInterface(INTERFACE_NAME).withGetter([this](){ return this->Descriptors(); });
        //object_.registerProperty("WriteAcquired").onInterface(INTERFACE_NAME).withGetter([this](){ return this->WriteAcquired(); });
        //object_.registerProperty("NotifyAcquired").onInterface(INTERFACE_NAME).withGetter([this](){ return this->NotifyAcquired(); });
    }

    ~GattCharacteristic1_adaptor() = default;

private:
    virtual std::vector<uint8_t> ReadValue(const std::map<std::string, sdbus::Variant>& options) = 0;
    virtual void WriteValue(const std::vector<uint8_t>& value, const std::map<std::string, sdbus::Variant>& options) = 0;
    virtual void AcquireWrite(const std::map<std::string, sdbus::Variant>& options) = 0;
    virtual void AcquireNotify(const std::map<std::string, sdbus::Variant>& options) = 0;
    virtual void StartNotify() = 0;
    virtual void StopNotify() = 0;
    virtual void Confirm() = 0;

private:
    virtual std::string UUID() = 0;
    virtual sdbus::ObjectPath Service() = 0;
    virtual std::vector<uint8_t> Value() = 0;
    virtual bool Notifying() = 0;
    virtual std::vector<std::string> Flags() = 0;
    virtual std::vector<sdbus::ObjectPath> Descriptors() = 0;
    virtual bool WriteAcquired() = 0;
    virtual bool NotifyAcquired() = 0;

private:
    sdbus::IObject& object_;
};

}} // namespaces

#endif
