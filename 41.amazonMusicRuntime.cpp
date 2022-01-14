// end exactly 30 seconds before the listener reachers their stop
// song unique id 0 to N-1 
// Assumptions:
// 1. you will pick exactly two songs
// 2. you cannot pick the same song twice.
// 3. if you have multiple pairs with the same total time, select the pair with the longest song.
// 4. there are at least two songs available. 
#include <vector>
#include <iostream>
#include <climits>

std::vector<int> findSongs(int rideDuration, std::vector<int> songDurations) {
    std::vector<int> songs;
    
    // Assumption 4
    if (songDurations.size()<2){
        return {-1,-1}; // return {-1,-1} vector when there are less than two songs available to indicate that error has occured.
    }
    // Requirement 1 
    int targetTime = rideDuration - 30; // end exactly 30 seconds before destination
    // Assumption 3 
    int longestSong = 0; // keeps track of longestSong for assumption 3
    int longerSong = 0 ; // keeps track of longer song of the 2 currently selected
    for (size_t i = 0; i < songDurations.size()-1; ++i)
    {
        //std::cout << (i + 1) << " - " << songDurations[i] << '\n';

        for(size_t j = i+1; j < songDurations.size(); ++j){
            //std::cout << "i : " << i << "     j : " << j << std::endl;
            // check if time difference is exactly 0
            if( targetTime - songDurations[i]- songDurations[j] == 0 ){
                // check if longest song is updated
                if(songDurations[i] > songDurations[j]){
                    longerSong = songDurations[i];
                }else {
                    longerSong = songDurations[j];
                }
                if(longestSong < longerSong){
                    longestSong = longerSong;
                    songs = {(int)i,(int)j};
                }
            }
            
        }
    }
    return songs;

}



int main () {
    int rideDuration = 90;
    std::vector<int> songDurations = { 1, 10, 25, 35, 60}; 

    std::vector<int> songs = findSongs(rideDuration, songDurations);

    std::cout << "songs[0] : " << songs[0] << "   song[1] : " << songs[1];
}