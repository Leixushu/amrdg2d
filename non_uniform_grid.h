#ifndef NS_AMR_H
#define NS_AMR_H  

#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<vector>
#include<set>
#include<list>
#include<map>
#include<utility>
#include<algorithm>

#include"vec2d.h"
#include"vec3d.h"
#include"vec4d.h"

using namespace std;

#define DEBUG

#define WALL_BNDRY
//#define PERIODIC_BNDRY          //periodic boundary
//#define DOUBLE_MA_BNDRY // double mach reflection problem
//#define RIEMANN2_BNDRY

//#define SHBL_LIM
#define TZBL_LIM
const int HLLCFLUX=0; //1 hllc,0 global Lax-Friedrichs flux

//#define DUICHEN  
//#define ILWILW

//#define RES_SMOOTH  //residual smoothing
//#define LOCAL_TIME //�ֲ�ʱ�䲽����
//#define FIXED_DT  //fixed time step
const double fixed_dt=1e-5;
#define FILE_PROX  "dg"

//const double CFL= 0.10444;  //0.4

const double t_print=0.245;//ָ��ʱ�䴦�����

const int Limiter01=1; 
const double M4TVBM =1.010;
#define KXRCF_LIM
const int PosLimiter=1;// 1 with positive preserving, 0 no 
const int NLBpt=3; //3 Gauss LB pts, 4 gass LB pts, others is illegal
//const double lim_muscl=1.0;  //=0.5 or 1.0

const int nDOF=6; //6: for p2, 3 for p1 �������ݳ���
//#define NORMAL_DIR_MOD  //�߽編��������ʱ������������������
const int qvlvModify=1; //0ֱ��ʹ�öԳƱ߽磬1ʹ����������

const bool b_ARS=true;//do use riemann soleve to set wall bound
const int qvlvRie=0;
const int mv_qvlvModify=0;//��ֵ�㸽��ֻ�ǶԳƱ߽�����
const double xLeft= -3.3;
const double xRight= 5.3;
const double yLow= -2.2;
const double yUpper= 2.2; 

const double xInlet=-3.0;
const double xOutlet=5.0;
const double PI = 3.14159265358979;

const int Nx=123;  //total cell number in x direction ������������Լ��ұ��������ڱ߽�����
const int Ny=65;//��ϸ˵��Ҳ���Բο�formlist.cpp
const int max_time_steps=80000;
const bool isOutVorM=false;
//**********************************************************
const bool SwAMR=true; //�Ƿ���������Ӧ 
const int Nr= 3;  // ��ʼ�����ʼ���μ���Nr��
const int Nar=4; //������Ӧ����
const int MaxAMR=4;
#define NAR_MAXAMR 0   //1 use Nar to assure the number of AMR
//0 use MaxAMR to make sure the number of AMR
//#define KXRCF_AMR
const int AMRP=4; //solution AMR refine control:
const short COAR=4;//amr indicator choose for coase 
//0:cur div, 1:div, 2:curl, 3:pio, others, 4:other combination
//AMRP=5 KXRCF with div
//����3:other ����Ӧ���
#define ADAPTIVE_INDICATOR 0 //0:den,1:press, 2:entropy
const double coarse_coe=0.3; //amr coarse coefficient can be changed
const double coarse_coe1=0.4; //amr coarse coefficient can be changed
const double refine_coe=1.2;
const double refine_coe1=1.60; //��Ҫ�������ò���
const int localRefine=0; //һ�㲻��������Ǿ���ֱ��ʹ��
//�ֲ�����Nr=1,2,3,4,5������ֵҪ����д�ⲿ������ܵĳ���??

const int adp_begin=7;//������Ӧ��ÿ�����귽���adp_begin+1����ʼ,��һ����Է�ֹԶ���߽����û�����ڵ㲻��Ҷ�ӽڵ������
//*************************************************************
#define GRID_FILE  "IN//naca0012Grid2.in"
//#define WALL_POINT_FILE  ("IN//RAE2822.dat")
//#define WALL_POINT_FILE  ("IN//halfCircle")
#define WALL_POINT_FILE  ("IN//tri_Pro")
//#define WALL_POINT_FILE  "IN//wallpoint1.dat"
#define WALL_POINT_FILE1  "IN//wallpoint2.dat"
#define WALL_POINT_FILE2  "IN//naca0012wall.in"
//#define WALL_POINT_FILE  "IN//scramjet_point"
#define ExtWALL_POINT_FILE  "IN//quad01_point"
#define IS_TUBE 1 //1 yes 0 no
#define N_BODY 1 //!=0,  1:  one body 2:  two bodies, 3: three bodies and so on. 
#define HAVE_MV 1// 1 with multi value points, 0 no
//��ֵ���������
const int n_sharp_point[N_BODY+3][8]={{0,100,200},{78}};
const int MVptNum[N_BODY+3]={3};
//#define WALL_POINT_FILE  ("IN//naca0012bd.dat")
/*+++++++++++++++++++++++++++++++++++++++++++++++++
  circleGrid.in : Nx=298+2, Ny=338+2, NPOINT=102641, NCELL=102000
  circleGrid1.in : Nx=445+2, Ny=255+2, NPOINT=115584, NCELL=114879
  circleGrid2.in : Nx=535+2, Ny=325+2, NPOINT=176464, NCELL=175599
  naca0012Grid.in : Nx=285+2, Ny=296+2 , NPOINT= 86112, NCELL=85526
  naca0012Grid2.in : Nx=285+2, Ny=296+2 , NPOINT= 86112, NCELL=85526
  naca0012Grid3.in : Nx = 535+2 Ny = 716+2, NPOINT= 386822, NCELL=385566
  +++++++++++++++++++++++++++++++++++++++++++++++++*/
const int NPOINT= 86112;
const int NCELL= 85526;

const int NPOINTCIRCLE = 300;  // the point at the wall for circel =360,
const int NPOINTCIRCLE1 = 154;  // the point at the wall for circel =360,
const int NPOINTCIRCLE2 = 154;  // the point at the wall for circel =360,
// for naca0012 = 154, no point is same. for RAE2822:118
const int NPT_EXT_WALL=312;//points at external compuatianial domain 

const double FreeMa =10.0; //���������

const double AOA=0.0;   //incidence or angle of attack��λ��
//��ʱ�ٶȵķ���ı䣬��������ϵ
//������ת�Ƕ� ��λ����
const double rotate_deg=AOA;//���ɷ���ϵ

//dimensionless constant �����ù��ʵ�λ
const double FreeD=1.225;  // free density use d,q to denote
const double FreeT=288.15;     //free temperature

const double GAMMA=1.4;
const double GAM11=GAMMA-1.0;

const double Rconst = 287.04;
const double Rstar=1.0/GAMMA; //ʹ��������Ϊ�ٶȵ������ٷ�ʽ�����Բο��ֳ�����
const double FreeP=FreeD*Rconst*FreeT; //�����ù��ʵ�λ
const double FreeV=FreeMa*340.29;        //free velocity�����ù��ʵ�λ
const double FreeA=sqrt(GAMMA*FreeP/FreeD);

const double initP = FreeP/(FreeD*FreeA*FreeA);   //---�����ٱ�׼����ѹ ����a=340.29-
const double initQ = 1.0;   //---�����ٱ�׼�����ܶ�---
const double initT=initP/initQ/Rstar;

const double uFree=FreeMa;  //�������ٶ�
const double vFree=0.0;
//const double uFree=FreeMa*cos(PI/180.0 * AOA);  //�������ٶ�
//const double vFree=FreeMa*sin(PI/180.0 * AOA);

const double hx=(xRight-xLeft) / (Nx-4.0);  //�Ⱦ�����//����������ʾ�ȼ�����������
const double hy=(yUpper-yLow) / (Ny-4.0);

const double RADII= 0.300;  //�����ٺ����  Բ�İ뾶
const double x_o=0.8;
const double y_o=0.0;//Բ������

const double Ellipse_x=-0.02; //�ֲ����ܵ�λ��ָ����ʼ���ܼ���,�ֲ�ָ��λ�ü���ʱ��Ҫʹ��Nr=0
const double Ellipse_x1=1.02; //�ֲ����ܵ�λ��ָ����ʼ���ܼ���,�ֲ�ָ��λ�ü���ʱ��Ҫʹ��Nr=0
const double Ellipse_y=-0.58;
const double Ellipse_y1=0.58;

const double ERRS = 1.0e-8;

const double gspt[3]={-0.774596669241483, 0.00000000000, 0.774596669241483};
const double wei[3]={0.555555555555556, 0.888888888888889, 0.555555555555556};  

const double gsLB3pt[3]={-1.0,0.0,1.0};
const double weiLB3[3]={1.0/3.0, 4.0/3.0, 1.0/3.0};

const double gsLB4pt[4]={-1.0, -0.447213595499958,
    0.447213595499958, 1.0};
const double weiLB4[4]={1.0/6.0, 5.0/6.0, 5.0/6.0, 1.0/6.0};

//const double rk_coe[4]={};
//#define VTK_OUTPUT
const double RXMIN = 1.5;
const double RXMAX =7.5;

const double RYMIN = 0.15; //-0.065 for airfoil
const double RYMAX =0.7;   //0.065 for airfoil
#define TECPLOT_OUTPUT

#define max2(a,b) ((a)>(b)?(a):(b))
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a)<(b)?(a):(b))
#define min3(a,b,c) min2(min2(a,b),c)
//#define diffU(a,b) ((a)-(b))

//Ŀǰ���ò�����
#define LEN sizeof(OctCell)
#define NpointForOutput 800000
#define NcellForOutput 800000
#define NneedRefineGrid 800000
#define NMAX 40   //���ڶ�ά���������ĳ���
const int reserve_num=400000;
typedef struct conservedvariables{
    double q;
    double qu;
    double qv;
    double te;   //---��λ�������E=q*(e+0.5*V*V), e=p/(gama-1)q---

    conservedvariables() {q=qu=qv=te=0.0;}

}SHBL;

typedef struct privariables{
    //	double T;
    double q;
    double u;
    double v;
    double p; //--total specific enthalpy ����H=h+0.5*V*V,h=e+p/q---

    privariables(){u=v=q=p=0.0;}
}JBBL;

typedef class pointxy{
public:
    double x;
    double y;
    pointxy(){x=y=0.0;}
}PXYZ;

class bodygridclass;

typedef class wallp
{
public:
    Vec2D normS;
    double pre;
    //   int iy;
    // int ix;
    bodygridclass *incell;
    double cp;
    double cf;
    double T;
    wallp()
    {
        pre=0.0;
        incell=NULL;
        cp=cf=0.0;
        T=0.0;
    }
}WALLP;


//typedef struct flux{
//	double fq;
//	double fqu;
//	double fqv;
//	double fte;
//}Flux;

class node;

class BndryNode;

typedef class bodygridclass
{ 
public:
    double invM[6]; //local mass matrix
    double dof[4][6];
    double dof0[4][6];
    short flag; //��������ͣ�0-fluid cell, -1-solid cell, 2-interface cell 
    short exflag;//���������̱ڱ߽�����������0-fluid, -1 solid, 2 interface cell 
    //flag:�����������ڹ����ڲ���Ϊ��������1���cell��Ϊ2�����������ñ߽�������
    // �����ڹ����ڲ�������������Ϊ-1,��������������㣬������
    //������������������Ϊ0  2011-9-8
    //---------------------------------------
//multi value flag ���ܵĲ�һ������
    bool mvflg;
    double Ux[4],Uy[4];//gradient
    short level;//�������ڵĲ��� 
    short level0;//����������Ӧ֮ǰ�ĳ�ʼ����
    short reflag;//�Ƿ����;0-δ����,1-�Ѽ���
    bool coflag;//�ж������Ƿ�ֻ���0-δ�ֻ�,1-�Ѵֻ�

    unsigned NOparent;//��ʼ��������

    short NOchildren;//������Ԫ���������еı��

    bool bAvg;//����˵���Ƿ������˵�Ԫƽ��
    double vorM; //vortex

    //����Ӧ�о�
    bool trb;//trouble cell true or false
    bool trbamr;//trouble cell true or false for AMR
    double kxrcf;
    double kxq;
    double maxqp;
    double inlen;
    double tcur;
    double tdiv;
    double pio;//all other adaptive indicator
//limiter for positive preserving

    bodygridclass *parent; 
    bodygridclass *children[4];
	/*---------------------------------
			         3     2
			         0     1
	              7     6
		     4     5
    ---------------------------------*/

    double xc1,yc1;//����Ԫ���ĵ�����
    double dx,dy; //���񲽳�

    double dt1;   //local time step

    double residual[4][6];
#ifdef RES_SMOOTH
    double resd0[4][6];
    double resd1[4][6];
#endif

 //   node *p_node;
    //---------------------------------------------------

// BndryNode *pnode;  //���Ƚ���Щ���Ƕ�ֵ���cell�����ú�,�߽�������ʱ��������Ƕ�ֵcellֱ��ȡֵ,��ʱpnode=NULL
    //Ҫ�Ƕ�ֵcell��ʱ���ƽ������м���ghost������ֵpnode!=NULL

public:
    bodygridclass();
    bodygridclass(double,double);

    void set_invM() {
        invM[0]=1.0/dx/dy;   
        invM[1]=3.0/dx/dy;
        invM[2]=3.0/dx/dy;
        invM[3]=9.0/dx/dy;
        invM[4]=45.0/4.0/dx/dy;
        invM[5]=45.0/4.0/dx/dy;
    }

    void set_invM(double dsx, double dsy) {
        invM[0]=1.0/dsx/dsy;   
        invM[1]=3.0/dsx/dsy;
        invM[2]=3.0/dsx/dsy;
        invM[3]=9.0/dsx/dsy;
        invM[4]=45.0/4.0/dsx/dsy;
        invM[5]=45.0/4.0/dsx/dsy;
    }

}OctCell;  

typedef OctCell *ptrOctCell;

typedef class node
{
public:
    node();
    short flg;  //flg=6 farfied cell�������ñ߽�������, 
    //flg=2 ���˿�������Ӧ��cell�����һ����������Ҫ�����cell
    //flg=0 cell can be adaptive

    OctCell *cell;        
    node *next;
    node *prev;              
#ifdef RES_SMOOTH
    short n_nb;
#endif
/*    ~node()
    { 
        if(cell!=NULL) cell->p_node=NULL;
    }
    */
}Node;  

class BndryNode {
public:
    BndryNode()
    {
        cell=NULL;
        next=NULL;
        prev=NULL;
     //   incell=NULL;
        //    flg=0;    
    }

    //   short flg; //flg=2һ������ڲ�cell����һ��߽�����, flg=4��ֵ��cell                  
    OctCell *cell; 

    BndryNode *next;
    BndryNode *prev;  

   // PXYZ smtrc_pt;//symmetrical point

    //OctCell *incell; //symmetrical point ���ڵ�cell
    //vector<OctCell*> nbcell; //symmetrical point �ھӲ�ֵcell

};

class Face {
public:
    OctCell *parent; 
    OctCell *neighbor; 
    //parent is the id of the cell owning this face
    // A cell owns a face if the face normal is pointing outwards from it
    // The other cell is called the neighbor
    // Vec2D nml;
    double nml[2];
    double gs_pt[3][2];//���gauss���ֵ�����
    double faceflux[3][4]; //face flux at 3 gauss points
    double area; //the area of the face in 3d or lenth in 2d
    bool bHang;
    Face();
};

class cellEdgeBool {
public:
    bool bEdge[4];
    cellEdgeBool();

};    

//cell�����ĸ������
class cellPointIndex {
public:
    int iPoint[4];  //initial��ʼ��Ϊ 0 ��ʾ�����Ŵ�1��ʼ��
    cellPointIndex();
};

//��for output
class pointInCell {
public:
    Vec2D pt;
    OctCell *mcell[4];//����������cell,���4��,���ʱ�õ�
    short nmc;
    pointInCell();
};

inline void shblToJbbl(SHBL *ush, JBBL *jbu)
{
    jbu->q=ush->q;
    jbu->u=ush->qu/ush->q;
    jbu->v=ush->qv/ush->q;

    jbu->p = (ush->te - 0.5 * ush->q * (jbu->u * jbu->u
            + jbu->v * jbu->v)) * GAM11;

}

inline void shbl2jbbl(double ush[],double ujb[])
{
    ujb[0]=ush[0];
    ujb[1]=ush[1]/ush[0];
    ujb[2]=ush[2]/ush[0];
    ujb[3]=(ush[3]-0.5*ush[0]*(ujb[1]*ujb[1]+ujb[2]*ujb[2]))*GAM11;
}

inline void jbblToShbl(JBBL *jbu, SHBL *ush)
{
    ush->q=jbu->q;
    ush->qu=jbu->u * jbu->q;
    ush->qv=jbu->v * jbu->q;

    ush->te=jbu->p/GAM11+ 0.5 * ush->q * ( jbu->u * jbu->u
        + jbu->v * jbu->v );

}
inline void jbbl2shbl(double ujb[],double ush[])
{
    ush[0]=ujb[0];
    ush[1]=ush[0]*ujb[1];
    ush[2]=ujb[0]*ujb[2];
    ush[3]=ujb[3]/GAM11+0.5*ujb[0]*(ujb[1]*ujb[1]+ujb[2]*ujb[2]);
}

// base function
inline double  phix(double x, double xc1,  double dx)
{
    return (2.0*(x-xc1)/dx);
}

inline double psiy(double y, double yc1, double dy)
{
    return (2.0*(y-yc1)/dy);
} 

inline double phix_psiy(double x,double y, double xc1, double yc1, double dx, double dy)
{
    return (4.0*(y-yc1)*(x-xc1)/(dx*dy));
}   

inline double phix2m(double x, double xc1, double dx)
{
    return (4.0*(x-xc1)*(x-xc1)/(dx*dx)-1.0/3.0);
}

inline double psiy2m(double y,  double yc1, double dy)
{
    return (4.0*(y-yc1)*(y-yc1)/(dy*dy)-1.0/3.0);
}

inline double distance2p(const PXYZ &p1, const PXYZ &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

#endif

