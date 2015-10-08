/*
   Copyright (C) 2015 Preet Desai (preet.desai@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef KS_DEFERRED_PROPERTY_HPP
#define KS_DEFERRED_PROPERTY_HPP

#include <ks/KsSignal.hpp>

namespace ks
{
    template<typename T>
    class DeferredProperty
    {
    public:
        DeferredProperty() = default;

        DeferredProperty(T value) :
            m_value(std::move(value))
        {

        }

        T const & Get() const
        {
            return m_value;
        }

        void Set(T value)
        {
            signal_set.Emit(std::move(value));
        }

        void Notify(T value)
        {
            m_value = std::move(value);
            signal_changed.Emit(m_value);
        }

        mutable Signal<T> signal_set;
        mutable Signal<T> signal_changed;

    private:
        T m_value;
    };
}

#endif // KS_DEFERRED_PROPERTY_HPP
