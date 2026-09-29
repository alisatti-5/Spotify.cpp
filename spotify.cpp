// Spotify.cpp
// Stage 1: Setup project structure, libraries, structs, and main menu loop

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Stores information about a song and its streams.
struct ArtistSongRecord
{
    string trackTitle;
    string artistName;
    long long totalStreamCount;
};

// This contains the name, price and ad status of a subscription plan.
struct SubscriptionPackage
{
    string tierName;
    double monthlyFeeRM;
    bool includesAds;
};

int main()
{
    int userMenuSelection = 0;

    cout << "==================================================\n";
    cout << "        WELCOME TO SPOTIFY SYSTEM ASSISTANT\n";
    cout << "==================================================\n";

    do
    {
        cout << "\nMain Menu Options:\n";
        cout << "1. Calculate Artist Royalties\n";
        cout << "2. View Subscription Catalog & Pricing\n";
        cout << "3. Exit Program\n";
        cout << "Choose option (1-3): ";

        cin >> userMenuSelection;

        switch (userMenuSelection)
        {
            case 3:
                cout << "\nExiting program safely.\n";
                break;
            default:
                cout << "\n[Error Alert]: Invalid option selected.\n";
        }

    } while (userMenuSelection != 3);

    return 0;
}
