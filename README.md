# nearest_points
This program will find two points in a set A consisting of n pairwise different points on a plane, between which the distance is the smallest. 

`input specification`  
The input data starts with a positive integer n ∈ [2, 106], which is the number of points in set A. Each of the next n lines contains the coordinates of the next point, which are a pair of integers xi, yi separated by a single space, where −107 ≤ xi, yi ≤ 107. 


`output specification`  
The program will output two lines describing the pair of closest points from A: each line will contain the description of one of these points (a pair of its coordinates separated by a space, as in the input data). If there are more such pairs, the program will output any of them.


To compile: `g++ -std=gnu++17 -static -DSPRAWDZACZKA main.cpp`  
To run: `./a.out`  
