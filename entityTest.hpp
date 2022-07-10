#ifndef entityTestHppIncluded
#define entityTestHppIncluded

#include "entity.hpp"
#include "domainTest.hpp"
#include <string>

using namespace std;

template <class Entity>
class UTEntity {
    protected:
        bool response = SUCCESS;
        Entity *entity;
        //virtual ~UTEntity() {};
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

class UTAccommodation:public UTEntity<Accommodation> {
    private:
        void successScenario(); 
        const static string VALID_CODE;
        const static string VALID_CITY;
        const static string VALID_COUNTRY;
        const static string VALID_GRADE;
        const static string VALID_DESCRIPTION;
};

class UTRating:public UTEntity<Rating> {
    private:
        void successScenario(); 
        const static string VALID_CODE;
        const static string VALID_GRADE;
        const static string VALID_DESCRIPTION;
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
