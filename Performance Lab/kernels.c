/********************************************************
 * Kernels to be optimized for the Metu Ceng Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "solo",                     /* Team name */

    "Mehmet Tokgöz",            /* First member full name */
    "e2528784",                 /* First member id */

    "",                         /* Second member full name (leave blank if none) */
    "",                         /* Second member id (leave blank if none) */

    "",                         /* Third member full name (leave blank if none) */
    ""                          /* Third member id (leave blank if none) */
};

/****************
 * EXPOSURE FUSION KERNEL *
 ****************/

/*******************************************************
 * Your different versions of the exposure fusion kernel go here 
 *******************************************************/

/* 
 * naive_fusion - The naive baseline version of exposure fusion
 */
char naive_fusion_descr[] = "naive_fusion: Naive baseline exposure fusion";
void naive_fusion(int dim, int *img, int *w, int *dst) {
  
    int i, j, k; 
    for(k = 0; k < 4; k++){
        for(i = 0; i < dim; i++) {
            for(j = 0; j < dim; j++) {
                    dst[i*dim+j] += w[k*dim*dim+i*dim+j] * img[k*dim*dim+i*dim+j];
            }
        }
    }
}

/* 
 * fusion - Your current working version of fusion
 * IMPORTANT: This is the version you will be graded on
 */

char fusion_descr[] = "fusion: Current working version";
void fusion(int dim, int *img, int *w, int *dst) 
{
    int i, j;
    int *w1 = w, *img1 = img;

    int dimq = dim*dim, dimq2 = 2*dim*dim, dimq3 = 3*dim*dim;

        for(i = 0; i < dim; i++) {

            for(j = 0; j < dim; j+=32){ 
               		
                dst[0]  = w1[0] * img1[0]+ w1[dimq+0]*img1[dimq+0] +  w1[dimq2+0]*img1[dimq2+0] +  w1[dimq3+0]*img1[dimq3+0];
                dst[1]  = w1[1] * img1[1]+ w1[dimq+1]*img1[dimq+1] +  w1[dimq2+1]*img1[dimq2+1] +  w1[dimq3+1]*img1[dimq3+1];
                dst[2]  = w1[2] * img1[2]+ w1[dimq+2]*img1[dimq+2] +  w1[dimq2+2]*img1[dimq2+2] +  w1[dimq3+2]*img1[dimq3+2];
                dst[3]  = w1[3] * img1[3]+ w1[dimq+3]*img1[dimq+3] +  w1[dimq2+3]*img1[dimq2+3] +  w1[dimq3+3]*img1[dimq3+3];
                dst[4]  = w1[4] * img1[4]+ w1[dimq+4]*img1[dimq+4] +  w1[dimq2+4]*img1[dimq2+4] +  w1[dimq3+4]*img1[dimq3+4];
                dst[5]  = w1[5] * img1[5]+ w1[dimq+5]*img1[dimq+5] +  w1[dimq2+5]*img1[dimq2+5] +  w1[dimq3+5]*img1[dimq3+5];
                dst[6]  = w1[6] * img1[6]+ w1[dimq+6]*img1[dimq+6] +  w1[dimq2+6]*img1[dimq2+6] +  w1[dimq3+6]*img1[dimq3+6];
                dst[7]  = w1[7] * img1[7]+ w1[dimq+7]*img1[dimq+7] +  w1[dimq2+7]*img1[dimq2+7] +  w1[dimq3+7]*img1[dimq3+7];
                dst[8]  = w1[8] * img1[8]+ w1[dimq+8]*img1[dimq+8] +  w1[dimq2+8]*img1[dimq2+8] +  w1[dimq3+8]*img1[dimq3+8];
                dst[9]  = w1[9] * img1[9]+ w1[dimq+9]*img1[dimq+9] +  w1[dimq2+9]*img1[dimq2+9] +  w1[dimq3+9]*img1[dimq3+9];
                dst[10] = w1[10] * img1[10]+ w1[dimq+10]*img1[dimq+10] +  w1[dimq2+10]*img1[dimq2+10] +  w1[dimq3+10]*img1[dimq3+10];
                dst[11] = w1[11] * img1[11]+ w1[dimq+11]*img1[dimq+11] +  w1[dimq2+11]*img1[dimq2+11] +  w1[dimq3+11]*img1[dimq3+11];
                dst[12] = w1[12] * img1[12]+ w1[dimq+12]*img1[dimq+12] +  w1[dimq2+12]*img1[dimq2+12] +  w1[dimq3+12]*img1[dimq3+12];
                dst[13] = w1[13] * img1[13]+ w1[dimq+13]*img1[dimq+13] +  w1[dimq2+13]*img1[dimq2+13] +  w1[dimq3+13]*img1[dimq3+13];
                dst[14] = w1[14] * img1[14]+ w1[dimq+14]*img1[dimq+14] +  w1[dimq2+14]*img1[dimq2+14] +  w1[dimq3+14]*img1[dimq3+14];
                dst[15] = w1[15] * img1[15]+ w1[dimq+15]*img1[dimq+15] +  w1[dimq2+15]*img1[dimq2+15] +  w1[dimq3+15]*img1[dimq3+15];
		dst[16] = w1[16] * img1[16]+ w1[dimq+16]*img1[dimq+16] +  w1[dimq2+16]*img1[dimq2+16] +  w1[dimq3+16]*img1[dimq3+16];
		dst[17] = w1[17] * img1[17]+ w1[dimq+17]*img1[dimq+17] +  w1[dimq2+17]*img1[dimq2+17] +  w1[dimq3+17]*img1[dimq3+17];
                dst[18] = w1[18] * img1[18]+ w1[dimq+18]*img1[dimq+18] +  w1[dimq2+18]*img1[dimq2+18] +  w1[dimq3+18]*img1[dimq3+18];
                dst[19] = w1[19] * img1[19]+ w1[dimq+19]*img1[dimq+19] +  w1[dimq2+19]*img1[dimq2+19] +  w1[dimq3+19]*img1[dimq3+19];
                dst[20] = w1[20] * img1[20]+ w1[dimq+20]*img1[dimq+20] +  w1[dimq2+20]*img1[dimq2+20] +  w1[dimq3+20]*img1[dimq3+20];
                dst[21] = w1[21] * img1[21]+ w1[dimq+21]*img1[dimq+21] +  w1[dimq2+21]*img1[dimq2+21] +  w1[dimq3+21]*img1[dimq3+21];
                dst[22] = w1[22] * img1[22]+ w1[dimq+22]*img1[dimq+22] +  w1[dimq2+22]*img1[dimq2+22] +  w1[dimq3+22]*img1[dimq3+22];
                dst[23] = w1[23] * img1[23]+ w1[dimq+23]*img1[dimq+23] +  w1[dimq2+23]*img1[dimq2+23] +  w1[dimq3+23]*img1[dimq3+23];
                dst[24] = w1[24] * img1[24]+ w1[dimq+24]*img1[dimq+24] +  w1[dimq2+24]*img1[dimq2+24] +  w1[dimq3+24]*img1[dimq3+24];
                dst[25] = w1[25] * img1[25]+ w1[dimq+25]*img1[dimq+25] +  w1[dimq2+25]*img1[dimq2+25] +  w1[dimq3+25]*img1[dimq3+25];
                dst[26] = w1[26] * img1[26]+ w1[dimq+26]*img1[dimq+26] +  w1[dimq2+26]*img1[dimq2+26] +  w1[dimq3+26]*img1[dimq3+26];
                dst[27] = w1[27] * img1[27]+ w1[dimq+27]*img1[dimq+27] +  w1[dimq2+27]*img1[dimq2+27] +  w1[dimq3+27]*img1[dimq3+27];
                dst[28] = w1[28] * img1[28]+ w1[dimq+28]*img1[dimq+28] +  w1[dimq2+28]*img1[dimq2+28] +  w1[dimq3+28]*img1[dimq3+28];
                dst[29] = w1[29] * img1[29]+ w1[dimq+29]*img1[dimq+29] +  w1[dimq2+29]*img1[dimq2+29] +  w1[dimq3+29]*img1[dimq3+29];
                dst[30] = w1[30] * img1[30]+ w1[dimq+30]*img1[dimq+30] +  w1[dimq2+30]*img1[dimq2+30] +  w1[dimq3+30]*img1[dimq3+30];
                dst[31] = w1[31] * img1[31]+ w1[dimq+31]*img1[dimq+31] +  w1[dimq2+31]*img1[dimq2+31] +  w1[dimq3+31]*img1[dimq3+31];  
                w1+= 32;
                img1 += 32;
                dst+=32;
       }
    
    }
}
/*********************************************************************
 * register_fusion_functions - Register all of your different versions
 *     of the fusion kernel with the driver by calling the
 *     add_fusion_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_fusion_functions() 
{
    add_fusion_function(&naive_fusion, naive_fusion_descr);  
    add_fusion_function(&fusion, fusion_descr);    
    /* ... Register additional test functions here */
}

/***************************
 * GAUSSIAN BLUR KERNEL *
 ***************************/

/******************************************************
 * Your different versions of the Gaussian blur functions go here
 ******************************************************/

/* 
 * naive_blur - The naive baseline version of Gussian blur
 */
char naive_blur_descr[] = "naive_blur The naive baseline version of Gaussian blur";
void naive_blur(int dim, float *img, float *flt, float *dst) {
  
    int i, j, k, l;

    for(i = 0; i < dim-5+1; i++){
        for(j = 0; j < dim-5+1; j++) {
            for(k = 0; k < 5; k++){
                for(l = 0; l < 5; l++) {
                    dst[i*dim+j] = dst[i*dim+j] + img[(i+k)*dim+j+l] * flt[k*dim+l];
                }
            }
        }
    }
}

/* 
 * blur - Your current working version of Gaussian blur
 * IMPORTANT: This is the version you will be graded on
 */
char blur_descr[] = "blur: Current working version";
void blur(int dim, float *img, float *flt, float *dst) 
{
    int i, j, i_dim = 0, index = 0, bound = dim-4;   
    float s1=0,s2=0,s3=0,s4=0,s5=0, kernArray[25];

    for (int m = 0; m < 25; m+=5){
	    for (int n = 0; n < 5; n++){
		kernArray[m+n] = flt[n];		    
	    }
	    flt+=dim;
    }


    int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
   
    for(i = 0; i < bound; i++){

	
	    for(j = 0; j < bound; j++) {
	
		index = i_dim+j;

		s1 = 0;s2 =0;s3 =0;s4 = 0;s5 = 0;

		// for k = 0 and all l values
		s1 += img[index]   * kernArray[0];
		s2 += img[index+1] * kernArray[1];
		s3 += img[index+2] * kernArray[2];
		s4 += img[index+3] * kernArray[3];
		s5 += img[index+4] * kernArray[4];
            
		index1 = index+dim;
		// for k = 1 and all l values
	        s1 += img[index1]   * kernArray[5];
                s2 += img[index1+1] * kernArray[6];
                s3 += img[index1+2] * kernArray[7];
                s4 += img[index1+3] * kernArray[8];
                s5 += img[index1+4] * kernArray[9];

		index2 = index1+dim;

                s1 += img[index2]   * kernArray[10];
                s2 += img[index2+1] * kernArray[11];
                s3 += img[index2+2] * kernArray[12];
                s4 += img[index2+3] * kernArray[13];
                s5 += img[index2+4] * kernArray[14];

		index3 = index2 + dim;
                s1 += img[index3]   * kernArray[15];
                s2 += img[index3+1] * kernArray[16];
                s3 += img[index3+2] * kernArray[17];
                s4 += img[index3+3] * kernArray[18];
                s5 += img[index3+4] * kernArray[19];

		index4 = index3 +dim;
                s1 += img[index4]   * kernArray[20];
                s2 += img[index4+1] * kernArray[21];
                s3 += img[index4+2] * kernArray[22];
                s4 += img[index4+3] * kernArray[23];
                s5 += img[index4+4] * kernArray[24];

		dst[index] = s1+s2+s3+s4+s5;

      

        }

	i_dim += dim;
    }
}

/*********************************************************************
 * register_blur_functions - Register all of your different versions
 *     of the gaussian blur kernel with the driver by calling the
 *     add_blur_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_blur_functions() 
{
    add_blur_function(&naive_blur, naive_blur_descr); 
    add_blur_function(&blur, blur_descr);
    /* ... Register additional test functions here */
}

