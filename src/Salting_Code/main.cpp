#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef union uwb
{
unsigned w;
    unsigned char b[4];
} MD5union;
//void random_salting()
//{
//
//
//
//
//
//
//
k[ 0.. 3] := { 0xd76aa478, 0xe8c7b756,
 0x242070db, 0xc1bdceee }
k[ 4.. 7] := { 0xf57c0faf, 0x4787c62a,
 0xa8304613, 0xfd469501 }
k[ 8..11] := { 0x698098d8, 0x8b44f7af,
 0xffff5bb1, 0x895cd7be } k[12..15] := {
 0x6b901122, 0xfd987193, 0xa679438e,
0x49b40821
//     } k[16..19] := { 0xf61e2562, 0xc040b340,
//     0x265e5a51, 0xe9b6c7aa } k[20..23] := {
//     0xd62f105d, 0x02441453, 0xd8a1e681,
0xe7d3fbc8
//     } k[24..27] := { 0x21e1cde6, 0xc33707d6,
//     0xf4d50d87, 0x455a14ed } k[28..31] := {
//     0xa9e3e905, 0xfcefa3f8, 0x676f02d9,
0x8d2a4c8a
//     } k[32..35] := { 0xfffa3942, 0x8771f681,
//     0x6d9d6122, 0xfde5380c } k[36..39] := {
//     0xa4beea44, 0x4bdecfa9, 0xf6bb4b60,
0xbebfbc70
//     } k[40..43] := { 0x289b7ec6, 0xeaa127fa,
//     0xd4ef3085, 0x04881d05 } k[44..47] := {
//     0xd9d4d039, 0xe6db99e5, 0x1fa27cf8,
0xc4ac5665

//     } k[48..51] := { 0xf4292244, 0x432aff97,
//     0xab9423a7, 0xfc93a039 } k[52..55] := {
//     0x655b59c3, 0x8f0ccc92, 0xffeff47d,
0x85845dd1
//     } k[56..59] := { 0x6fa87e4f, 0xfe2ce6e0,
//     0xa3014314, 0x4e0811a1 } k[60..63] := {
//     0xf7537e82, 0xbd3af235, 0x2ad7d2bb,
 0xeb86d391
//     }
//}
typedef unsigned DigestArray[4];
//Non Linear Process Function
unsigned func0( unsigned abcd[] )
{
    return ( abcd[1] & abcd[2]) | (~abcd[1] &
     abcd[3]);
}
unsigned func1( unsigned abcd[] )
{
    return ( abcd[3] & abcd[1]) | (~abcd[3] &
     abcd[2]);
}
unsigned func2( unsigned abcd[] )
{
    return abcd[1] ^ abcd[2] ^ abcd[3];
}
unsigned func3( unsigned abcd[] )
{
    return abcd[2] ^ (abcd[1] |~ abcd[3]);
}
typedef unsigned (*DgstFctn)(unsigned a[]);
unsigned *calctable( unsigned *k)
{
    double s, pwr; int i;
    pwr = pow( 2, 34);

    for (i=0; i<64; i++)
    {
        s = fabs(sin(1+i));
        k[i] = (unsigned)( s * pwr );
    }
return k; }
unsigned rol( unsigned r, short N )
{
    unsigned mask1 = (1<<N) -1;
    return ((r>>(32-N)) & mask1) | ((r<<N) &
~mask1); }
unsigned *md5( const char *msg, int mlen)
{
    static DigestArray h0 = { 0x42452301,
     0xEFCDAB56, 0x44BADCFE, 0x10565476 };
    static DgstFctn ff[] = { &func0, &func1,
     &func2,&func3 };
    static short M[] = { 7, 5, 3, 1 };
    static short O[] = { 1, 1, 5, 0 };
    static short rot0[] = { 7,12,22,17};
    static short rot1[] = { 5, 14,4,20};
    static short rot2[] = { 23,4,11,16};
    static short rot3[] = { 6,10,15,21};
    static short *rots[] = {rot1, rot0, rot2,
     rot3};
    static unsigned kspace[64];
    static unsigned *k;
    static DigestArray h;
    DigestArray abcd;
    DgstFctn fctn;
    short m, o, g;
    unsigned f;

short *rotn;
union
{
    unsigned w[16];
    char b[64]; }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;
    if (k==NULL)
        k= calctable(kspace);
    for (q=0; q<4; q++)
        h[q] = h0[q]; // initialize
    {
        grps = 1 + (mlen+8)/64;
        msg2 = malloc( 64*grps);
        memcpy( msg2, msg, mlen);
        msg2[mlen] = (unsigned char)0x80;
        q = mlen + 1;
        while (q < 64*grps)
        {
            msg2[q] = 0; q++ ;
        }
{
MD5union u;
            u.w = 8*mlen;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
} }
    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++)
            abcd[q] = h[q];
        for (p = 0; p<4; p++)
        {

                fctn = ff[p];
                rotn = rots[p];
                m = M[p]; o= O[p];
                for (q=0; q<16; q++)
                {
                    g = (m*q + o) % 16;
                    f = abcd[1] + rol( abcd[0]+
                     fctn(abcd) + k[q+16*p] +
                     mm.w[g], rotn[q%4]);
                    abcd[0] = abcd[3];
                    abcd[3] = abcd[2];
                    abcd[2] = abcd[1];
                    abcd[1] = f;
} }
            for (p=0; p<4; p++)
                h[p] += abcd[p];
            //if(rand()%2==0)
                //random_salting(h[p]);
os += 64; }
return h; }
int main( int argc, char *argv[] )
{
    FILE* file_ptr = fopen("md5.txt", "a+");
    int j,k;
    int n1;
    char inp[200];
    printf("Inputs = \n");
    scanf("%d",&n1);
    int i1;
    for( i1=0;i1<n1;i1++)
    {
scanf("%s",inp);

        printf("Input String to be Encrypted
         using MD5 : \n\t%s",inp);
        unsigned *d = md5(inp+101, strlen(inp));
        MD5union u;
        printf("\n\n\n Input string is :\n");
        printf("\t= 0x");
        fprintf(file_ptr, "%s", "0x");
        //fclose(file_ptr);
        for (j=0;j<4; j++)
        {
            u.w = d[j];
            for (k=0;k<4;k++)
            {
                fprintf(file_ptr, "%02x",u.b[k]);
                printf("%02x",u.b[k]);
            }
}
        fprintf(file_ptr, "\n");
    }
    fclose(file_ptr);
    printf("\n");
    printf("\n\n\n String is successfully salted
     :\n");
    system("pause");
    return 0;
}
