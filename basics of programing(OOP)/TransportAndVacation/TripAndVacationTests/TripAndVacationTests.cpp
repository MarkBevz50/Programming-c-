#include "pch.h"
#include "CppUnitTest.h"
#include "../TransportAndVacation/ClassesUttilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TripAndVacationTests
{
    TEST_CLASS(TripAndVacationTests)
    {
    public:
        TEST_METHOD_INITIALIZE(Initialize)
        {
            size = 3; // Задаємо кількість поїздок для тестування
            trips = new Trip * [size];
            trips[0] = new CarTrip();
            trips[1] = new FamilyBeachVacation();
            trips[2] = new FamilyBeachVacation();
        }

        TEST_METHOD_CLEANUP(Cleanup)
        {
            for (size_t i = 0; i < size; ++i) {
                delete trips[i];
            }
            delete[] trips;
        }

        TEST_METHOD(TestReadTripFromFile)
        {
            // Arrange
            const std::string filename = "test_trips.txt";

            // Act
            Trip** tripsFromFile = readTripFromFile(filename, size);

            // Assert
            Assert::IsNotNull(tripsFromFile);
            Assert::AreEqual(size, size); // Assuming there are 3 trips in the file

            // Clean up
            for (size_t i = 0; i < size; ++i) {
                delete tripsFromFile[i];
            }
            delete[] tripsFromFile;
        }

        //TEST_METHOD(TestPrintTrips)
        //{
        //    // Act & Assert
        //    Assert::ExpectException<std::exception>([] { printTrips(trips, size); });
        //}

        //TEST_METHOD(TestCalculateTotalPrice)
        //{
        //    // Act
        //    int totalPrice = calculateTotalPrice(trips, size);

        //    // Assert
        //    Assert::AreEqual( /* expected total price */, totalPrice);
        //}

        TEST_METHOD(TestFindMostExpensive)
        {
            // Act
            Trip* mostExpensive = findMostExpensive(trips, size);

            // Assert
            Assert::IsNotNull(mostExpensive);
        }

        TEST_METHOD(TestFindMostExpensiveWithRequiredType)
        {
            // Act
            Trip* mostExpensive = findMostExpensive(trips, size, 'A'); // Assuming there's no trip with type 'A'

            // Assert
            Assert::IsNull(mostExpensive);
        }

        TEST_METHOD(TestSplitTripsByType)
        {
            // Arrange
            Trip** carTrips;
            size_t carTripsCount;
            Trip** planeTrips;
            size_t planeTripsCount;

            // Act
            splitTripsByType(trips, size, carTrips, carTripsCount, planeTrips, planeTripsCount);

            // Assert
            Assert::IsNotNull(carTrips);
            Assert::IsTrue(carTripsCount > 0);
            Assert::IsNotNull(planeTrips);
            Assert::IsTrue(planeTripsCount > 0);

            // Clean up
            delete[] carTrips;
            delete[] planeTrips;
        }

        TEST_METHOD(TestFindCheapestTrip)
        {
            // Act
            Trip* cheapestTrip = findCheapestTrip(trips, size);

            // Assert
            Assert::IsNotNull(cheapestTrip);
        }

    private:
        size_t size;
        Trip** trips;
    };
}
