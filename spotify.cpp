# Spotify.cpp
// Spotify Management Assistant
// This program has two main features:
// 1. Calculate an estimated artist payment from streams.
// 2. Display Spotify subscription plans.

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

// Calculates an estimated payment based on the number of streams.
void processArtistRoyalties()
{
    ArtistSongRecord currentSong;

    cout << "\n---------------------------------------\n";
    cout << "      Artist Royalty Calculator\n";
    cout << "---------------------------------------\n";

    // Ask for the artist or band name.
    cout << "Artist or band: ";
    cin.ignore(1000, '\n');
    getline(cin, currentSong.artistName);

    // Get the song title.
    cout << "Enter the music title: ";
    getline(cin, currentSong.trackTitle);

    // Get the total number of streams.
    cout << "Enter total accumulated streams: ";
    cin >> currentSong.totalStreamCount;

    // Check if the stream number is valid.
    if (currentSong.totalStreamCount < 0)
    {
        cout << "\n[Error Alert]: Stream count cannot be negative.\n";
        return;
    }

    // See if the streams are below 1000.
    if (currentSong.totalStreamCount < 1000)
    {
        cout << "\nStreams are below 1000.\n";
        cout << "The program will not calculate an estimate for this song.\n";
    }
    else
    {
        // Use an example rate for the calculation.
        double estimatedRevenueUSD =
            currentSong.totalStreamCount * 0.003;

        cout << fixed << setprecision(2);

        cout << "\nResult:\n";
        cout << "Artist Name: " << currentSong.artistName << "\n";
        cout << "Track Title: \"" << currentSong.trackTitle << "\"\n";
        cout << "Total Streams: " << currentSong.totalStreamCount << "\n";
        cout << "Estimated Payout: $" << estimatedRevenueUSD << " USD\n";
        cout << "This is only an estimated amount.\n";
    }
}

// Display plans for local Spotify subscription.
void displaySubscriptionCatalog()
{
    cout << "\n---------------------------------------------------\n";
    cout << " >>> Spotify Regional Subscription Catalog (MY) <<<\n";
    cout << "---------------------------------------------------\n";

    // Example subscription data for the program.
    vector<SubscriptionPackage> catalog =
    {
        {"Free Tier", 0.00, true},
        {"Student Plan", 7.50, false},
        {"Individual Premium", 14.90, false},
        {"Duo Plan", 19.80, false},
        {"Family Plan", 22.90, false}
    };

    // Loop over all packages to display them.
    for (size_t index = 0; index < catalog.size(); ++index)
    {
        cout << index + 1 << ". Package Name: "
             << catalog[index].tierName << "\n";

        cout << fixed << setprecision(2);

        cout << "   Monthly Price: RM "
             << catalog[index].monthlyFeeRM << "\n";

        cout << "   Ad-Supported: "
             << (catalog[index].includesAds ? "Yes" : "No") << "\n";

        cout << "---------------------------------------------------\n";
    }
}

int main()
{
    int userMenuSelection = 0;

    cout << "==================================================\n";
    cout << "       WELCOME TO SPOTIFY SYSTEM ASSISTANT\n";
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
