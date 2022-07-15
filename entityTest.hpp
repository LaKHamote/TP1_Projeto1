#ifndef entityTestHppIncluded
#define entityTestHppIncluded

#include "entity.hpp"
#include "domainTest.hpp"
#include <string>

using namespace std;

/**
 * Parent template class of all tests for entities
 * 
 * Template Params:
 * -Any declared Entity 
 * 
 * Author: 211038262
 */
template <class EntityName>
class UTEntity {
    protected:
        EntityName *entity;
        virtual ~UTEntity() {};
        bool response = SUCCESS;
    private:
        void setUp();
        virtual void successScenario() = 0;
        void tearDown();
    public:
        const static int SUCCESS = 1;
        const static int FAILURE = 0;
        virtual int run();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * Unity Test for Entity User
 * Author: 211038262
 */
class UTUser:public UTEntity<User> {
    private:
        void successScenario();
        const static string VALID_NAME;
        const static string VALID_EMAIL;
        const static string VALID_PASSWORD;
        const static string VALID_LANGUAGE;
        const static string VALID_DATE;
        const static string VALID_DESCRIPTION;
};

/**
 * Unity Test for Entity Accommodation
 * Author: 211038262
 */
class UTAccommodation:public UTEntity<Accommodation> {
    private:
        void successScenario(); 
        const static string VALID_CODE;
        const static string VALID_CITY;
        const static string VALID_COUNTRY;
        const static string VALID_GRADE;
        const static string VALID_DESCRIPTION;
};

/**
 * Unity Test for Entity Rating
 * Author:
 */
class UTRating:public UTEntity<Rating> {
    private:
        void successScenario(); 
        const static string VALID_CODE;
        const static string VALID_GRADE;
        const static string VALID_DESCRIPTION;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
