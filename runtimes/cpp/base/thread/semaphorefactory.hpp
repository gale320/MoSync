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

/* 
 * File:   semaphorefactory.hpp
 * Author: Ali Mosavian
 *
 * Created on July 14, 2009
 */

#ifndef __SEMAPHOREFACTORY_HPP__
#define	__SEMAPHOREFACTORY_HPP__

#include <list>
#include "semaphore.hpp"
#include "../allocationfailedexception.hpp"


namespace Base
{
    namespace Thread
    {
        /**
         * This singleton class creates new semaphores in a platform
         * independent fashion. To create an implementation for
         * a new platform you need to:
         *
         * 1. Create a seperate file for the implementation
         *
         * 2. Implement the methods
         *      - createSemaphore method
         *      - Thread safe getInstance method
         *
         * 3. Add the call to YourImplementation::getInstance in the
         *    getInstance method of this class by using the preprocessor.
         *
         * 4. Include that implementation when compiled for the new
         *    platform by using the build system.
         *
         */
        class SemaphoreFactory
        {
            friend class Semaphore;

        protected:
            static SemaphoreFactory*    m_instance;
            std::list<Semaphore *>	m_liveSemaphoreList;


            /**
             * Constructor
             *
             */
            SemaphoreFactory ( void );

            /**
             * Removes a semaphore from the live list
             *
             * @param m     The semaphore to remove
             *
             */
            void deleteSemaphore ( Semaphore *m );

            /**
             * Deletes all the semaphores
             *
             */
            void deleteSemaphores ( void );

        public:
            /**
             * Destructor
             *
             * @internal Do not forget to call deleteSemaphores in
             *           the destructor of the implementation.
             */
            virtual ~SemaphoreFactory ( void );

            /**
             * Creates a platform independent Semaphore
             *
             * @param v     Initial value (defualt is 0)
             *
             * @return Pointer to semaphore if allocation was succesful,
             *         NULL otherwise.
             *
             * @internal Do not forget to add the newly created semaphore
             *           to the live list before returning.
             */
            virtual Semaphore * createSemaphore ( int v = 0 ) = 0;


            /**
             * Returns the singleton instance of the factory.
             * the method is thread safe.
             *
             */
            static SemaphoreFactory * getInstance ( void );
        };

    }
}

#endif	/* _SEMAPHOREFACTORY_HPP */

