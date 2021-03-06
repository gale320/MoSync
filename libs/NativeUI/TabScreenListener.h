/* Copyright 2013 David Axmark

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

/*! \addtogroup NativeUILib
 *  @{
 */

/**
 *  @defgroup NativeUILib Native UI Library
 *  @{
 */

/**
 * @file TabScreenListener.h
 * @author Bogdan Iusco
 *
 * \brief Listener for TabScreen events.
 */

#ifndef NATIVEUI_TAB_SCREEN_LISTENER_H_
#define NATIVEUI_TAB_SCREEN_LISTENER_H_

namespace NativeUI
{
    // Forward declaration.
    class TabScreen;

    /**
     * \brief Interface for tab screen event listeners.
     */
    class TabScreenListener
    {
    public:
        /**
         * This method is called when a tab screen has changed to a new tab.
         * @param tabScreen The tab screen object that generated the event.
         * @param tabScreenIndex The index of the new tab.
         */
        virtual void tabScreenTabChanged(
            TabScreen* tabScreen,
            const int tabScreenIndex) = 0;
    };

} // namespace NativeUI

#endif /* NATIVEUI_TAB_SCREEN_LISTENER_H_ */

/*! @} */
