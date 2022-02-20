/*
ON A CUBE

Problem Description:

A solid cube of 10 cm x 10cm x 10 cm rests on the ground.  It has a beetle on it, and some sweet honey spots at various 
locations on the surface of the cube.  The beetle starts at a point on the surface of the cube, and goes to the honey 
spots in order along the surface of the cube.

1. If it goes from a point to another point on the same face (say X to Y), it goes in an arc of a circle that subtends 
   an angle of 60 degrees at the centre of the circle
2. If it goes from one point to another on a different face, it goes by the shortest path on the surface of the cube,
   except that it never travels along the bottom of the cube

The beetle is a student of Cartesian geometry, and knows the coordinates (x, y, z) of all the points it needs to go to.  
The origin of coordinates it uses is one corner of the cube on the ground, and the z axis points up.  Hence, the bottom 
surface (on which it does not crawl) is z=0, and the top surface is z=10.  The beetle keeps track of all the distances 
travelled, and rounds the distance travelled to two decimal places once it reaches the next spot, so that the final 
distance is a sum of the rounded distances from point to point.

Input:

1.The first line gives an integer N, the total number of points (including the starting point) the beetle visits
2.The second line is a set of 3N comma separated non-negative numbers, with up to two decimal places each.  
  These are to be interpreted in groups of three as the x, y, z coordinates of the points the beetle needs to visit in 
  the given order.

Output:

One line with a number giving the total distance travelled by the beetle accurate to two decimal places.  
Even if the distance travelled is an integer, the output should have two decimal places.

Constraints:

None of the points the beetle visits is on the bottom face (z=0) or on any of the edges of the cube 
(the lines where two faces meet)
2<=N<=10

                Y
                |
                |(0,0,10)
                |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ (10,0,10)
               /|                                           /|
             /  |                                         /  |
 (0,10,10) /    |                          (10,10,10)   /    |
        _/_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /      |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |                                   |        |
        |       |(0,0,0)                            |        |(10,0,0)
        |       |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|_ _ _ _ |____________X
        |      /                                    |       / 
        |    /                                      |     /
        |  /                                        |   /
        |/_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ | /
       /(0,10,0)                                     (10,10,0)
     /
   /
 /
Z      
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//||||||||||||||||||||||||||||||GLOBAL DECLARATION||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
int check_coplanar_points(int nop); // ex:(1,1,10),(2,1,10)
int temp_a, temp_b, temp_c;// dummy variables
int cppts_fake = 0, cppts = 0, temp_cppts; 

void check_metaplanar_points(int u_arr[], int pcount); // ex:(1,1,10),(0,5,5)
int mpt[10], temp, possibility_arr[10];
int valid = 0;
int nop_temp, u_temp, m_temp;

int check_paraplanar_points(int pcount); // ex:(0,5,5),(10,5,5)
int temp_d, temp_e, temp_f;// dummy variables
int pppts_fake = 0, pppts = 0, temp_pppts;

void convert_struct_to_array(); //to represent each points in an array to be addressed easily

struct coordinate{
    float x, y, z;//variables for each axis
};
struct coordinate p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
float co_ordinates[30];
int i, j, k, l, x; //dummy variables
int u_m, u_n; // u -> union
int cpt[10], ppt[10]; //cpt -> coplanar points, ppt -> paraplanar points

int convert_int_to_array(int pts);//to address each digit of any number individually
int pt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, digit;// dummy variables

void find_union_of_array(int arr1[], int arr2[], int m, int n);//to find the union of any two arrays
int union_array[20], u_array[10];

//int number_of_points = 0;
//int coplanar_points, paraplanar_points;

//process variables
float calculate_coplanar_distance();
const float pi = 3.14;
float dist = 0, temp_dist = 0, temp_rad_dist = 0;
float temp_x_dist, temp_y_dist, temp_z_dist;//dummy

float calculate_metaplanar_distance();
float m_dist = 0;

float calculate_paraplanar_distance();
float path1, path2, path3;//all possible eucledian paths
float p_dist = 0;

//float distance , m_distance, p_distance, c_distance;
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int main(){
    
    //|||||||||||||||||||||||||||LOCAL DECLARATION||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    int number_of_points = 0;
    int coplanar_points, paraplanar_points;
    float distance , m_distance, p_distance, c_distance;
    /*char reply; //if you wish to repeat the process over, uncomment do...while part.
    int dummy;*/
    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    //do{
    scanf("%d", &x);//no use
    //get the input coordinates
    number_of_points = scanf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &p1.x, &p1.y, &p1.z, &p2.x, &p2.y, &p2.z, &p3.x, &p3.y, &p3.z, &p4.x, &p4.y, &p4.z, &p5.x, &p5.y, &p5.z, &p6.x, &p6.y, &p6.z, &p7.x, &p7.y, &p7.z, &p8.x, &p8.y, &p8.z, &p9.x, &p9.y, &p9.z, &p10.x, &p10.y, &p10.z);
    number_of_points = number_of_points / 3;

    convert_struct_to_array();//convert the coordinates to array
    
    coplanar_points = check_coplanar_points(number_of_points);
    convert_int_to_array(coplanar_points);
    for(i = 0; i < 10; i++){
        //convert_int_to_array stores the values in dummy pt[] array...
        //to permanently store the array, cpt[] is used
        cpt[i] = pt[i];
    } 

    paraplanar_points = check_paraplanar_points(number_of_points);
    convert_int_to_array(paraplanar_points);
    for(i = 0; i < 10; i++){
        //similar to coplanar points
        ppt[i] = pt[i];
    }

    u_m = sizeof(cpt) / sizeof(cpt[0]);//to determine the number of elements in an array
    u_n = sizeof(ppt) / sizeof(ppt[0]);//similar to u_m
    find_union_of_array(cpt, ppt, u_m, u_n);//to find union of coplanar and paraplanar points

    check_metaplanar_points(u_array, number_of_points);

    c_distance = calculate_coplanar_distance();
    m_distance = calculate_metaplanar_distance();
    p_distance = calculate_paraplanar_distance();
    distance = c_distance + m_distance + p_distance;//total distance
    printf("%.2f", distance);
/*
    printf("\nDo you want to repeat [y/n]? ");
    scanf("%d", &dummy);
    scanf("%c", &reply);
    }while(reply == 'y');*/

    return 0;
}

int check_coplanar_points(int nop){
    temp_b = (nop * 3) - 3;
    for(i = 0; i < temp_b; i++){
        temp_c = i + 3;
        temp_cppts = cppts_fake;
        if(((co_ordinates[i] == 0) || (co_ordinates[i] == 10)) && (co_ordinates[i] == co_ordinates[temp_c])){
            temp_a = i/3;
            cppts_fake = temp_a + 1; 
        } 
        if(cppts_fake != temp_cppts){
            cppts = (cppts + cppts_fake) * 10;
        }
    }
    return cppts;
}

int check_paraplanar_points(int pcount){
    temp_d  = (pcount * 3) - 3;
    for(i = 0; i < temp_d; i++){
        temp_e = i + 3;
        temp_pppts = pppts_fake;
        if(((co_ordinates[i] == 0) && (co_ordinates[temp_e] == 10)) || ((co_ordinates[i] == 10) && (co_ordinates[temp_e] == 0))){
            temp_f = i / 3;
            pppts_fake = temp_f + 1;
        }
        if(pppts_fake != temp_pppts){
            pppts = (pppts + pppts_fake) * 10;
        }
    }
    return pppts;
}

void check_metaplanar_points(int u_arr[], int nop){
    j = 1;
    for(i = 0; i < 10;i++){
        possibility_arr[i] = j;
        j++;
    }
    l = 0;
    for(i = 0; i < 10; i++){
        if(possibility_arr[i] != u_arr[i]){
            valid = 0;
            for(k = 0; k < 10; k++){
                if(possibility_arr[i] == u_arr[k]){
                    valid = 0;
                    break;
                }
                else if(possibility_arr[i] != u_arr[k]){
                    valid = 1;
                }
                else{}
            }
            if(valid == 1){
                mpt[l] = possibility_arr[i];
                l++;
            }
            else{}
        }
        else{}
    }

    nop_temp = nop - 1;
    u_temp = 0;
    for(i = 0; i < 10; i++){
        if(u_arr[i] != 0){
            u_temp++;
        }
        else{}
    }
    m_temp = nop_temp - u_temp;
    
    for(i = m_temp; i < 10; i++){
        mpt[i] = 0;
    }
}

int convert_int_to_array(int pts){
    pts = pts / 10;
    for(i = 0; i < 10; i++){
        digit = pts % 10;
        pt[i] = digit;
        pts = pts / 10;
    }
}

void find_union_of_array(int arr1[], int arr2[], int m, int n){
    j = 0;
    for(i = 0; i < m; i++){
       union_array[j] = arr1[i];
       j++;       
    }
    for(i = 0; i < n; i++){
        union_array[j] = arr2[i];
        j++;
    }
    k = 0;
    for(i = 0; i < 10; i++){
        if((union_array[i] != 0) && (union_array[i + 10] != 0) && (union_array[i] != union_array[i + 10])){
            u_array[k] = union_array[i];
            k++;
            u_array[k] = union_array[i + 10];
            k++;
        }
        else if((union_array[i] != 0) && (union_array[i + 10] == 0)){
            u_array[k] = union_array[i];
            k++;
        }
        else if((union_array[i] == 0) && (union_array[i + 10] != 0)){
            u_array[k] = union_array[i + 10];
            k++;
        }
        else{
            u_array[k] = 0;
            k++;
        }
    }
}

float calculate_paraplanar_distance(){
    for(i = 0; i < 10; i++){
        switch(ppt[i]){
            case 0:
                break;
            case 1:
                if(((p1.y == 10) && (p2.y == 0)) || ((p1.y == 0) && (p2.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p1.z) + 10 + fabs(10 - p2.z)), 2) + powf(fabs(p1.x - p2.x), 2));
                    path2 = sqrtf(powf((fabs(p1.x) + 10 + fabs(p2.x)), 2) + powf(fabs(p1.z - p2.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p1.x) + 10 + fabs(10 - p2.x)), 2) + powf(fabs(p1.z - p2.z), 2));
                }
                else if(((p1.x == 10) && (p2.x == 0)) || ((p1.x == 0) && (p2.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p1.z) + 10 + fabs(10 - p2.z)), 2) + powf(fabs(p1.y - p2.y), 2));
                    path2 = sqrtf(powf((fabs(p1.y) + 10 + fabs(p2.y)), 2) + powf(fabs(p1.z - p2.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p1.y) + 10 + fabs(10 - p2.y)), 2) + powf(fabs(p1.z - p2.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                } 
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 2:
                if(((p2.y == 10) && (p3.y == 0)) || ((p2.y == 0) && (p3.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p2.z) + 10 + fabs(10 - p3.z)), 2) + powf(fabs(p2.x - p3.x), 2));
                    path2 = sqrtf(powf((fabs(p2.x) + 10 + fabs(p3.x)), 2) + powf(fabs(p2.z - p3.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p2.x) + 10 + fabs(10 - p3.x)), 2) + powf(fabs(p2.z - p3.z), 2));
                }
                else if(((p2.x == 10) && (p3.x == 0)) || ((p2.x == 0) && (p3.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p2.z) + 10 + fabs(10 - p3.z)), 2) + powf(fabs(p2.y - p3.y), 2));
                    path2 = sqrtf(powf((fabs(p2.y) + 10 + fabs(p3.y)), 2) + powf(fabs(p2.z - p3.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p2.y) + 10 + fabs(10 - p3.y)), 2) + powf(fabs(p2.z - p3.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 3:
                if(((p3.y == 10) && (p4.y == 0)) || ((p3.y == 0) && (p4.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p3.z) + 10 + fabs(10 - p4.z)), 2) + powf(fabs(p3.x - p4.x), 2));
                    path2 = sqrtf(powf((fabs(p3.x) + 10 + fabs(p4.x)), 2) + powf(fabs(p3.z - p4.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p3.x) + 10 + fabs(10 - p4.x)), 2) + powf(fabs(p3.z - p4.z), 2));
                }
                else if(((p3.x == 10) && (p4.x == 0)) || ((p3.x == 0) && (p4.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p3.z) + 10 + fabs(10 - p4.z)), 2) + powf(fabs(p3.y - p4.y), 2));
                    path2 = sqrtf(powf((fabs(p3.y) + 10 + fabs(p4.y)), 2) + powf(fabs(p3.z - p4.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p3.y) + 10 + fabs(10 - p4.y)), 2) + powf(fabs(p3.z - p4.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 4:
                if(((p4.y == 10) && (p5.y == 0)) || ((p4.y == 0) && (p5.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p4.z) + 10 + fabs(10 - p5.z)), 2) + powf((p4.x - p5.x), 2));
                    path2 = sqrtf(powf((fabs(p4.x) + 10 + fabs(p5.x)), 2) + powf((p4.z - p5.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p4.x) + 10 + fabs(10 - p5.x)), 2) + powf((p4.z - p5.z), 2));
                }
                else if(((p4.x == 10) && (p5.x == 0)) || ((p4.x == 0) && (p5.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p4.z) + 10 + fabs(10 - p5.z)), 2) + powf(fabs(p4.y - p5.y), 2));
                    path2 = sqrtf(powf((fabs(p4.y) + 10 + fabs(p5.y)), 2) + powf(fabs(p4.z - p5.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p4.y) + 10 + fabs(10 - p5.y)), 2) + powf(fabs(p4.z - p5.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 5:
                if(((p5.y == 10) && (p6.y == 0)) || ((p5.y == 0) && (p6.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p5.z) + 10 + fabs(10 - p6.z)), 2) + powf((p5.x - p6.x), 2));
                    path2 = sqrtf(powf((fabs(p5.x) + 10 + fabs(p6.x)), 2) + powf((p5.z - p6.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p5.x) + 10 + fabs(10 - p6.x)), 2) + powf((p5.z - p6.z), 2));
                }
                else if(((p5.x == 10) && (p6.x == 0)) || ((p5.x == 0) && (p6.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p5.z) + 10 + fabs(10 - p6.z)), 2) + powf(fabs(p5.y - p6.y), 2));
                    path2 = sqrtf(powf((fabs(p5.y) + 10 + fabs(p6.y)), 2) + powf(fabs(p5.z - p6.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p5.y) + 10 + fabs(10 - p6.y)), 2) + powf(fabs(p5.z - p6.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 6:
                if(((p6.y == 10) && (p7.y == 0)) || ((p6.y == 0) && (p7.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p6.z) + 10 + fabs(10 - p7.z)), 2) + powf((p6.x - p7.x), 2));
                    path2 = sqrtf(powf((fabs(p6.x) + 10 + fabs(p7.x)), 2) + powf((p6.z - p7.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p6.x) + 10 + fabs(10 - p7.x)), 2) + powf((p6.z - p7.z), 2));
                }
                else if(((p6.x == 10) && (p7.x == 0)) || ((p6.x == 0) && (p7.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p6.z) + 10 + fabs(10 - p7.z)), 2) + powf(fabs(p6.y - p7.y), 2));
                    path2 = sqrtf(powf((fabs(p6.y) + 10 + fabs(p7.y)), 2) + powf(fabs(p6.z - p7.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p6.y) + 10 + fabs(10 - p7.y)), 2) + powf(fabs(p6.z - p7.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 7:
                if(((p7.y == 10) && (p8.y == 0)) || ((p7.y == 0) && (p8.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p7.z) + 10 + fabs(10 - p8.z)), 2) + powf((p7.x - p8.x), 2));
                    path2 = sqrtf(powf((fabs(p7.x) + 10 + fabs(p8.x)), 2) + powf((p7.z - p8.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p7.x) + 10 + fabs(10 - p8.x)), 2) + powf((p7.z - p8.z), 2));
                }
                else if(((p7.x == 10) && (p8.x == 0)) || ((p7.x == 0) && (p8.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p7.z) + 10 + fabs(10 - p8.z)), 2) + powf(fabs(p7.y - p8.y), 2));
                    path2 = sqrtf(powf((fabs(p7.y) + 10 + fabs(p8.y)), 2) + powf(fabs(p7.z - p8.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p7.y) + 10 + fabs(10 - p8.y)), 2) + powf(fabs(p7.z - p8.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 8:
                if(((p8.y == 10) && (p9.y == 0)) || ((p8.y == 0) && (p9.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p8.z) + 10 + fabs(10 - p9.z)), 2) + powf((p8.x - p9.x), 2));
                    path2 = sqrtf(powf((fabs(p8.x) + 10 + fabs(p9.x)), 2) + powf((p8.z - p9.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p8.x) + 10 + fabs(10 - p9.x)), 2) + powf((p8.z - p9.z), 2));
                }
                else if(((p8.x == 10) && (p9.x == 0)) || ((p8.x == 0) && (p9.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p8.z) + 10 + fabs(10 - p9.z)), 2) + powf(fabs(p8.y - p9.y), 2));
                    path2 = sqrtf(powf((fabs(p8.y) + 10 + fabs(p9.y)), 2) + powf(fabs(p8.z - p9.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p8.y) + 10 + fabs(10 - p9.y)), 2) + powf(fabs(p8.z - p9.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
            case 9:
                if(((p9.y == 10) && (p10.y == 0)) || ((p9.y == 0) && (p10.y == 10))){
                    path1 = sqrtf(powf((fabs(10 - p9.z) + 10 + fabs(10 - p10.z)), 2) + powf((p9.x - p10.x), 2));
                    path2 = sqrtf(powf((fabs(p9.x) + 10 + fabs(p10.x)), 2) + powf((p9.z - p10.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p9.x) + 10 + fabs(10 - p10.x)), 2) + powf((p9.z - p10.z), 2));
                }
                else if(((p9.x == 10) && (p10.x == 0)) || ((p9.x == 0) && (p10.x == 10))){
                    path1 = sqrtf(powf((fabs(10 - p9.z) + 10 + fabs(10 - p10.z)), 2) + powf(fabs(p9.y - p10.y), 2));
                    path2 = sqrtf(powf((fabs(p9.y) + 10 + fabs(p10.y)), 2) + powf(fabs(p9.z - p10.z), 2));
                    path3 = sqrtf(powf((fabs(10 - p9.y) + 10 + fabs(10 - p10.y)), 2) + powf(fabs(p9.z - p10.z), 2));
                };

                if(path1 <= path2 && path1 <= path3){
                    p_dist = p_dist + path1;
                }
                else if(path2 <= path3){
                    p_dist = p_dist + path2;
                }
                else{
                    p_dist = p_dist + path3;
                }
                break;
        }
    }
    return p_dist;
}

float calculate_metaplanar_distance(){
    for(i = 0; i < 10; i++){
        switch(mpt[i]){
            case 0:
                break;
            case 1:
                if((p1.x != 10) && (p2.x != 10) && (p1.x != 0) && (p2.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p1.y - p2.y) + fabs(p1.z - p2.z)), 2) + powf((fabs(p1.x - p2.x)), 2));
                }
                else if((p1.y != 10) && (p2.y != 10) && (p1.y != 0) && (p2.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p1.x - p2.x) + fabs(p1.z - p2.z)), 2) + powf((fabs(p1.y - p2.y)), 2));
                }
                else if((p1.z != 10) && (p2.z != 10) && (p1.z != 0) && (p2.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p1.x - p2.x) + fabs(p1.y - p2.y)), 2) + powf((fabs(p1.z - p2.z)), 2));
                }
                else{}
                break;
            case 2:
                if((p2.x != 10) && (p3.x != 10) && (p2.x != 0) && (p3.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p2.y - p3.y) + fabs(p2.z - p3.z)), 2) + powf((fabs(p2.x - p3.x)), 2));
                }
                else if((p2.y != 10) && (p3.y != 10) && (p2.y != 0) && (p3.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p2.x - p3.x) + fabs(p2.z - p3.z)), 2) + powf((fabs(p2.y - p3.y)), 2));
                }
                else if((p2.z != 10) && (p3.z != 10) && (p2.z != 0) && (p3.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p2.x - p3.x) + fabs(p2.y - p3.y)), 2) + powf((fabs(p2.z - p3.z)), 2));
                }
                else{}
                break;
            case 3:
                if((p3.x != 10) && (p4.x != 10) && (p3.x != 0) && (p4.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p3.y - p4.y) + fabs(p3.z - p4.z)), 2) + powf((fabs(p3.x - p4.x)), 2));
                }
                else if((p3.y != 10) && (p4.y != 10) && (p3.y != 0) && (p4.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p3.x - p4.x) + fabs(p3.z - p4.z)), 2) + powf((fabs(p3.y - p4.y)), 2));
                }
                else if((p3.z != 10) && (p4.z != 10) && (p3.z != 0) && (p4.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p3.x - p4.x) + fabs(p3.y - p4.y)), 2) + powf((fabs(p3.z - p4.z)), 2));
                }
                else{}
                break;
            case 4:
                if((p4.x != 10) && (p5.x != 10) && (p4.x != 0) && (p5.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p4.y - p5.y) + fabs(p4.z - p5.z)), 2) + powf((fabs(p4.x - p5.x)), 2));
                }
                else if((p4.y != 10) && (p5.y != 10) && (p4.y != 0) && (p5.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p4.x - p5.x) + fabs(p4.z - p5.z)), 2) + powf((fabs(p4.y - p5.y)), 2));
                }
                else if((p4.z != 10) && (p5.z != 10) && (p4.z != 0) && (p5.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p4.x - p5.x) + fabs(p4.y - p5.y)), 2) + powf((fabs(p4.z - p5.z)), 2));
                }
                else{}
                break;
            case 5:
                if((p5.x != 10) && (p6.x != 10) && (p5.x != 0) && (p6.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p5.y - p6.y) + fabs(p5.z - p6.z)), 2) + powf((fabs(p5.x - p6.x)), 2));
                }
                else if((p5.y != 10) && (p6.y != 10) && (p5.y != 0) && (p6.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p5.x - p6.x) + fabs(p5.z - p6.z)), 2) + powf((fabs(p5.y - p6.y)), 2));
                }
                else if((p5.z != 10) && (p6.z != 10) && (p5.z != 0) && (p6.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p5.x - p6.x) + fabs(p5.y - p6.y)), 2) + powf((fabs(p5.z - p6.z)), 2));
                }
                else{}
                break;
            case 6:
                if((p6.x != 10) && (p7.x != 10) && (p6.x != 0) && (p7.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p6.y - p7.y) + fabs(p6.z - p7.z)), 2) + powf((fabs(p6.x - p7.x)), 2));
                }
                else if((p6.y != 10) && (p7.y != 10) && (p6.y != 0) && (p7.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p6.x - p7.x) + fabs(p6.z - p7.z)), 2) + powf((fabs(p6.y - p7.y)), 2));
                }
                else if((p6.z != 10) && (p7.z != 10) && (p6.z != 0) && (p7.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p6.x - p7.x) + fabs(p6.y - p7.y)), 2) + powf((fabs(p6.z - p7.z)), 2));
                }
                else{}
                break;
            case 7:
                if((p7.x != 10) && (p8.x != 10) && (p7.x != 0) && (p8.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p7.y - p8.y) + fabs(p7.z - p8.z)), 2) + powf((fabs(p7.x - p8.x)), 2));
                }
                else if((p7.y != 10) && (p8.y != 10) && (p7.y != 0) && (p8.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p7.x - p8.x) + fabs(p7.z - p8.z)), 2) + powf((fabs(p7.y - p8.y)), 2));
                }
                else if((p7.z != 10) && (p8.z != 10) && (p7.z != 0) && (p8.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p7.x - p8.x) + fabs(p7.y - p8.y)), 2) + powf((fabs(p7.z - p8.z)), 2));
                }
                else{}
                break;
            case 8:
                if((p8.x != 10) && (p9.x != 10) && (p8.x != 0) && (p9.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p8.y - p9.y) + fabs(p8.z - p9.z)), 2) + powf((fabs(p8.x - p9.x)), 2));
                }
                else if((p8.y != 10) && (p9.y != 10) && (p8.y != 0) && (p9.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p8.x - p9.x) + fabs(p8.z - p9.z)), 2) + powf((fabs(p8.y - p9.y)), 2));
                }
                else if((p8.z != 10) && (p9.z != 10) && (p8.z != 0) && (p9.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p8.x - p9.x) + fabs(p8.y - p9.y)), 2) + powf((fabs(p8.z - p9.z)), 2));
                }
                else{}
                break;
            case 9:
                if((p9.x != 10) && (p10.x != 10) && (p9.x != 0) && (p10.x != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p9.y - p10.y) + fabs(p9.z - p10.z)), 2) + powf((fabs(p9.x - p10.x)), 2));
                }
                else if((p9.y != 10) && (p10.y != 10) && (p9.y != 0) && (p10.y != 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p9.x - p10.x) + fabs(p9.z - p10.z)), 2) + powf((fabs(p9.y - p10.y)), 2));
                }
                else if((p9.z != 10) && (p10.z != 10) && (p9.z != 0) && (p10.z!= 0)){
                    m_dist = m_dist + sqrtf(powf((fabs(p9.x - p10.x) + fabs(p9.y - p10.y)), 2) + powf((fabs(p9.z - p10.z)), 2));
                }
                else{}
                break;
        }
    }
    return m_dist;
}

float calculate_coplanar_distance(){
    for(i = 0; i < 9; i++){
        switch(cpt[i]){
            case 0:
                break;
            case 1:
                if(p1.z == p2.z){
                    temp_x_dist = fabs(p1.x - p2.x) * fabs(p1.x - p2.x);
                    temp_y_dist = fabs(p1.y - p2.y) * fabs(p1.y - p2.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p1.x == p2.x){
                    temp_y_dist = fabs(p1.y - p2.y) * fabs(p1.y - p2.y);
                    temp_z_dist = fabs(p1.z - p2.z) * fabs(p1.z - p2.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p1.y == p2.y){
                    temp_x_dist = fabs(p1.x - p2.x) * fabs(p1.x - p2.x);
                    temp_z_dist = fabs(p1.z - p2.z) * fabs(p1.z - p2.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 2:
                if(p2.z == p3.z){
                    temp_x_dist = fabs(p2.x - p3.x) * fabs(p2.x - p3.x);
                    temp_y_dist = fabs(p2.y - p3.y) * fabs(p2.y - p3.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p2.x == p3.x){
                    temp_y_dist = fabs(p2.y - p3.y) * fabs(p2.y - p3.y);
                    temp_z_dist = fabs(p2.z - p3.z) * fabs(p2.z - p3.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p2.y == p3.y){
                    temp_x_dist = fabs(p2.x - p3.x) * fabs(p2.x - p3.x);
                    temp_z_dist = fabs(p2.z - p3.z) * fabs(p2.z - p3.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 3:
                if(p3.z == p4.z){
                    temp_x_dist = fabs(p3.x - p4.x) * fabs(p3.x - p4.x);
                    temp_y_dist = fabs(p3.y - p4.y) * fabs(p3.y - p4.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p3.x == p4.x){
                    temp_y_dist = fabs(p3.y - p4.y) * fabs(p3.y - p4.y);
                    temp_z_dist = fabs(p3.z - p4.z) * fabs(p3.z - p4.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p3.y == p4.y){
                    temp_x_dist = fabs(p3.x - p4.x) * fabs(p3.x - p4.x);
                    temp_z_dist = fabs(p3.z - p4.z) * fabs(p3.z - p4.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 4:
                if(p4.z == p5.z){
                    temp_x_dist = fabs(p4.x - p5.x) * fabs(p4.x - p5.x);
                    temp_y_dist = fabs(p4.y - p5.y) * fabs(p4.y - p5.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p4.x == p5.x){
                    temp_y_dist = fabs(p4.y - p5.y) * fabs(p4.y - p5.y);
                    temp_z_dist = fabs(p4.z - p5.z) * fabs(p4.z - p5.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p4.y == p5.y){
                    temp_x_dist = fabs(p4.x - p5.x) * fabs(p4.x - p5.x);
                    temp_z_dist = fabs(p4.z - p5.z) * fabs(p4.z - p5.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 5:
                if(p5.z == p6.z){
                    temp_x_dist = fabs(p5.x - p6.x) * fabs(p5.x - p6.x);
                    temp_y_dist = fabs(p5.y - p6.y) * fabs(p5.y - p6.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p5.x == p6.x){
                    temp_y_dist = fabs(p5.y - p6.y) * fabs(p5.y - p6.y);
                    temp_z_dist = fabs(p5.z - p6.z) * fabs(p5.z - p6.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p5.y == p6.y){
                    temp_x_dist = fabs(p5.x - p6.x) * fabs(p5.x - p6.x);
                    temp_z_dist = fabs(p5.z - p6.z) * fabs(p5.z - p6.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 6:
                if(p6.z == p7.z){
                    temp_x_dist = fabs(p6.x - p7.x) * fabs(p6.x - p7.x);
                    temp_y_dist = fabs(p6.y - p7.y) * fabs(p6.y - p7.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p6.x == p7.x){
                    temp_y_dist = fabs(p6.y - p7.y) * fabs(p6.y - p7.y);
                    temp_z_dist = fabs(p6.z - p7.z) * fabs(p6.z - p7.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p6.y == p7.y){
                    temp_x_dist = fabs(p6.x - p7.x) * fabs(p6.x - p7.x);
                    temp_z_dist = fabs(p6.z - p7.z) * fabs(p6.z - p7.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 7:
                if(p7.z == p8.z){
                    temp_x_dist = fabs(p7.x - p8.x) * fabs(p7.x - p8.x);
                    temp_y_dist = fabs(p7.y - p8.y) * fabs(p7.y - p8.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p7.x == p8.x){
                    temp_y_dist = fabs(p7.y - p8.y) * fabs(p7.y - p8.y);
                    temp_z_dist = fabs(p7.z - p8.z) * fabs(p7.z - p8.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p7.y == p8.y){
                    temp_x_dist = fabs(p7.x - p8.x) * fabs(p7.x - p8.x);
                    temp_z_dist = fabs(p7.z - p8.z) * fabs(p7.z - p8.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 8:
                if(p8.z == p9.z){
                    temp_x_dist = fabs(p8.x - p9.x) * fabs(p8.x - p9.x);
                    temp_y_dist = fabs(p8.y - p9.y) * fabs(p8.y - p9.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p8.x == p9.x){
                    temp_y_dist = fabs(p8.y - p9.y) * fabs(p8.y - p9.y);
                    temp_z_dist = fabs(p8.z - p9.z) * fabs(p8.z - p9.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p8.y == p9.y){
                    temp_x_dist = fabs(p8.x - p9.x) * fabs(p8.x - p9.x);
                    temp_z_dist = fabs(p8.z - p9.z) * fabs(p8.z - p9.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
            case 9:
                if(p9.z == p10.z){
                    temp_x_dist = fabs(p9.x - p10.x) * fabs(p9.x - p10.x);
                    temp_y_dist = fabs(p9.y - p10.y) * fabs(p9.y - p10.y);
                    temp_dist = (sqrtf(temp_x_dist + temp_y_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }  
                else if(p9.x == p10.x){
                    temp_y_dist = fabs(p9.y - p10.y) * fabs(p9.y - p10.y);
                    temp_z_dist = fabs(p9.z - p10.z) * fabs(p9.z - p10.z);
                    temp_dist = (sqrtf(temp_y_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                else if(p9.y == p10.y){
                    temp_x_dist = fabs(p9.x - p10.x) * fabs(p9.x - p10.x);
                    temp_z_dist = fabs(p9.z - p10.z) * fabs(p9.z - p10.z);
                    temp_dist = (sqrtf(temp_x_dist + temp_z_dist));
                    temp_rad_dist = (2 * pi * temp_dist) / 6;
                    dist = dist + temp_rad_dist;
                }
                break;
        }
    }
    return dist;
}

void convert_struct_to_array(){
    for(i = 0; i < 30; i ++){
        switch(i){
            case 0:
                co_ordinates[i] = p1.x;
                break;
            case 1:
                co_ordinates[i] = p1.y;
                break;
            case 2:
                co_ordinates[i] = p1.z;
                break;
            case 3:
                co_ordinates[i] = p2.x;
                break;
            case 4:
                co_ordinates[i] = p2.y;
                break;
            case 5:
                co_ordinates[i] = p2.z;
                break;
            case 6:
                co_ordinates[i] = p3.x;
                break;
            case 7:
                co_ordinates[i] = p3.y;
                break;
            case 8:
                co_ordinates[i] = p3.z;
                break;
            case 9:
                co_ordinates[i] = p4.x;
                break;
            case 10:
                co_ordinates[i] = p4.y;
                break;
            case 11:
                co_ordinates[i] = p4.z;
                break;
            case 12:
                co_ordinates[i] = p5.x;
                break;
            case 13:
                co_ordinates[i] = p5.y;
                break;
            case 14:
                co_ordinates[i] = p5.z;
                break;
            case 15:
                co_ordinates[i] = p6.x;
                break;
            case 16:
                co_ordinates[i] = p6.y;
                break;
            case 17:
                co_ordinates[i] = p6.z;
                break;
            case 18:
                co_ordinates[i] = p7.x;
                break;
            case 19:
                co_ordinates[i] = p7.y;
                break;
            case 20:
                co_ordinates[i] = p7.z;
                break;
            case 21:
                co_ordinates[i] = p8.x;
                break;
            case 22:
                co_ordinates[i] = p8.y;
                break;
            case 23:
                co_ordinates[i] = p8.z;
                break;
            case 24:
                co_ordinates[i] = p9.x;
                break;
            case 25:
                co_ordinates[i] = p9.y;
                break;
            case 26:
                co_ordinates[i] = p9.z;
                break;
            case 27:
                co_ordinates[i] = p10.x;
                break;
            case 28:
                co_ordinates[i] = p10.y;
                break;
            case 29:
                co_ordinates[i] = p10.z;
                break;
        }   
    }
}