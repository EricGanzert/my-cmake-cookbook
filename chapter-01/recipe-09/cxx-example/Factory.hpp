#pragma once

#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>
#include <type_traits>

// Macro to be used to signal error conditions
#define ERROR(message)                                                                  \
    {                                                                                   \
        std::ostringstream _err;                                                        \
        _err << "Fatal error.\n"                                                        \
             << " In function " << __func__ << " at line " << __LINE__ << " of file "   \
             << __FILE__ << "\n"                                                        \
             << message << std::endl;                                                   \
        std::fprintf(stderr, "%s\n", _err.str().c_str());                               \
        std::exit(EXIT_FAILURE);                                                        \
    }

namespace detail {
template <typename CreateObject> class BaseFactory {
private:
    typedef std::map<std::string, CreateObject> CallbackMap;
    typedef typename CallbackMap::value_type CallbackPair;
    typedef typename CallbackMap::const_iterator CallbackConstIter;

protected:
    CallbackMap callbacks_;

    CallbackConstIter retrieve(const std::string& objID) const {
        if (objID.empty())
        {
            ERROR("No object identification string provided to the Factory.");
        }
        CallbackConstIter i = callbacks_.find(objID);
        if (i == callbacks_.end())
        {
            ERROR("The unknown object ID " + objID + " occurred in the Factory")
        }
        return i;
    }

private:
    bool registerObject(const std::string& objID, const CreateObject& functor) {
        return callbacks_.insert(CallbackPair(objID, functor)).second;
    }

    bool unRegisterObject(const std::string& objID) {
        return callbacks_.erase(objID) == 1;
    }

public:
    void subscribe(const std::string& objID, const CreateObject& functor) {
        bool done = this->registerObject(objID, functor);
        if (!done)
        {
            ERROR("Subscription of Object ID " + objID + " to factory failed!");
        }
    }

    void unsubscribe(const std::string& objID) {
        bool done = this->unRegisterObject(objID);
        if (!done)
        {
            ERROR("Unsubscription of Object ID " + objID + " to factory failed!");
        }
    }
};
}

template <typename CreateObject>
class Factory final : public detail::BaseFactory<CreateObject> {
public:
    template <typename... ObjectInputArgs>
    typename std::result_of<CreateObject(ObjectInputArgs...)>::type create(
        const std::string& objID,
        ObjectInputArgs... data) const {
            return (this->retrieve(objID)->second)(data...);
        }
};