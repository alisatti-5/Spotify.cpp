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

// Spotify.cpp
// Stage 2: Implemented subscription catalog display logic

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct ArtistSongRecord
{
    string trackTitle;
    string artistName;
    long long totalStreamCount;
};

struct SubscriptionPackage
{
    string tierName;
    double monthlyFeeRM;
    bool includesAds;
};

// Display plans for local Spotify subscription.
void displaySubscriptionCatalog()
{
    cout << "\n---------------------------------------------------\n";
    cout << " >>> Spotify Regional Subscription Catalog (MY) <<<\n";
    cout << "---------------------------------------------------\n";

    vector<SubscriptionPackage> catalog =
    {
        {"Free Tier", 0.00, true},
        {"Student Plan", 7.50, false},
        {"Individual Premium", 14.90, false},
        {"Duo Plan", 19.80, false},
        {"Family Plan", 22.90, false}
    };

    for (size_t index = 0; index < catalog.size(); ++index)
    {
        cout << index + 1 << ". Package Name: " << catalog[index].tierName << "\n";
        cout << fixed << setprecision(2);
        cout << "   Monthly Price: RM " << catalog[index].monthlyFeeRM << "\n";
        cout << "   Ad-Supported: " << (catalog[index].includesAds ? "Yes" : "No") << "\n";
        cout << "---------------------------------------------------\n";
    }
}

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
            case 2:
                displaySubscriptionCatalog();
                break;

            case 3:
                cout << "\nExiting program safely.\n";
                break;

            default:
                cout << "\n[Error Alert]: Invalid option selected.\n";
        }

    } while (userMenuSelection != 3);

    return 0;
}

// Spotify.cpp
// Stage 3: Completed artist royalty processing module and finalized main loop[cite: 1]

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct ArtistSongRecord
{
    string trackTitle;
    string artistName;
    long long totalStreamCount;
};

struct SubscriptionPackage
{
    string tierName;
    double monthlyFeeRM;
    bool includesAds;
};

// Calculates an estimated payment based on the number of streams[cite: 1].
void processArtistRoyalties()
{
    ArtistSongRecord currentSong;

    cout << "\n---------------------------------------\n";
    cout << "      Artist Royalty Calculator\n";
    cout << "---------------------------------------\n";

    cout << "Artist or band: ";
    cin.ignore(1000, '\n');
    getline(cin, currentSong.artistName);

    cout << "Enter the music title: ";
    getline(cin, currentSong.trackTitle);

    cout << "Enter total accumulated streams: ";
    cin >> currentSong.totalStreamCount;

    if (currentSong.totalStreamCount < 0)
    {
        cout << "\n[Error Alert]: Stream count cannot be negative.\n";
        return;
    }

    if (currentSong.totalStreamCount < 1000)
    {
        cout << "\nStreams are below 1000.\n";
        cout << "The program will not calculate an estimate for this song.\n";
    }
    else
    {
        double estimatedRevenueUSD = currentSong.totalStreamCount * 0.003;

        cout << fixed << setprecision(2);
        cout << "\nResult:\n";
        cout << "Artist Name: " << currentSong.artistName << "\n";
        cout << "Track Title: \"" << currentSong.trackTitle << "\"\n";
        cout << "Total Streams: " << currentSong.totalStreamCount << "\n";
        cout << "Estimated Payout: $" << estimatedRevenueUSD << " USD\n";
        cout << "This is only an estimated amount.\n";
    }
}

void displaySubscriptionCatalog()
{
    cout << "\n---------------------------------------------------\n";
    cout << " >>> Spotify Regional Subscription Catalog (MY) <<<\n";
    cout << "---------------------------------------------------\n";

    vector<SubscriptionPackage> catalog =
    {
        {"Free Tier", 0.00, true},
        {"Student Plan", 7.50, false},
        {"Individual Premium", 14.90, false},
        {"Duo Plan", 19.80, false},
        {"Family Plan", 22.90, false}
    };

    for (size_t index = 0; index < catalog.size(); ++index)
    {
        cout << index + 1 << ". Package Name: " << catalog[index].tierName << "\n";
        cout << fixed << setprecision(2);
        cout << "   Monthly Price: RM " << catalog[index].monthlyFeeRM << "\n";
        cout << "   Ad-Supported: " << (catalog[index].includesAds ? "Yes" : "No") << "\n";
        cout << "---------------------------------------------------\n";
    }
}

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
            case 1:
                processArtistRoyalties();
                break;

            case 2:
                displaySubscriptionCatalog();
                break;

            case 3:
                cout << "\nThanks for using our Spotify Management Assistant.\n";
                cout << "Exiting program safely.\n";
                break;

            default:
                cout << "\n[Error Alert]: Invalid option selected. "
                     << "Please select between 1 and 3.\n";
        }

    } while (userMenuSelection != 3);

    return 0;
}
