/* HEADERS*/
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>


using namespace cv;
using namespace std;
/*----------LE BUT DE CE PROJET ET DE M ENTRAINER SUR LES BASES DE TRAITEMENT D IMAGE------------------*/

/*
Faire attention avec imwrite(): chemin sur l'ordinateur: C:/Users/../Destop
Sauf que ces deux mots sont en francais (dossiers) sur mon PC donc c'est C:/Utilisateur/../Bureau
Les dossiers ou les fichiers ne doivent pas avoir d'espace dans leur nom "Projet IDO" !!!interdit
plutot "ProjetIDO" ou encore "Projet_IDO"
Ce sont ces types erreurs qui entrainent un message d'erreur: permission denied
DOnc soit le fichiers n'ont pas été trouvés (erreurs vu ci-dessus), soit vous n'avez pas la permission d'accéder à ces fichiers
Dans le dernier cas il suffit de faire un clic droit sur le fichiers ou dossiers (tout l'ensemble des ficheirs contenus ds ce dossier
                                                                                  seront affectés par ce changement) ensuite >>propriétés
>>sécurité>>modifier;
A la fin de ce fichier retrouver un exemple d'utilisation de la fonction imwrite fonctionnelle.
*/

//EXO 1:
/*
int main(int argc, char** argv )
{
    String image_phare("phare.png");
    int x, y,i,largeur, hauteur, profondeur, valeur_max=0;
    int histo [256];
    bool result;

    if (argc>1)
    {
        image_phare=argv[1];
    }
    Mat img_phare;

    img_phare=imread(image_phare); //valeur par defaut est couleur

    if (img_phare.empty())
    {
        cout<<"Could not find the picture or open it "<<endl;
        cout<<image_phare<<endl;
        return -1;
    }
    Mat BGR[3];
    split(img_phare,BGR);

    largeur=BGR[0].size().width;
    hauteur=BGR[0].size().height;
    profondeur=BGR[0].depth();

    cout<<"largeur: "<<largeur<<"hauteur: "<<hauteur<<"profondeur: "<<profondeur<<endl;

    for (x=0; x<256;x++)
    {
        histo[x]=0;
    }
    cout<<"fin de l'initialisation de histog"<<endl;

    for (x=0;x<largeur;x++)
    {
        for (y=0;y<hauteur;y++)
        {
            histo[BGR[0].at<uchar>(y,x)]++;
        }
    }

    for (x=0; x<256; x++)
    {
        if (histo[x]>valeur_max)
        {
            valeur_max=histo[x];
        }
    }
    cout<<"valeurMax = "<<valeur_max<<endl;
    Mat histog(256,valeur_max,CV_8UC1, Scalar(0));

    for (x=0; x<256;x++)
    {
        for (y=0; y<histo[x];y++)
        {
            histog.at<uchar>(x,y)=255;
        }
    }


    result = imwrite("C:/imgIDO/phare_histo.png",histog); //ne fct pas ? (permission denied)




    if (result)
    {
        cout<<"The picture was successful saved"<<endl;
    }
    else
    {
        cout<<"Could not save the picture "<<endl;
    }

    namedWindow("HISTOGRAMME PHARE");
    imshow("HISTOGRAMME PHARE",histog);
    waitKey(0);

    Mat dst;
    equalizeHist(BGR[0],dst);


    namedWindow("HISTOGRAMME equal PHARE");
    namedWindow("PICTURE PHARE BLEU");

    imshow("PICTURE PHARE BLEU",BGR[0]);
    imshow("HISTOGRAMME equal PHARE",dst); //resultat: on gagne en contraste et luminosité (changement)

    waitKey(0);

    bool res2=imwrite("C:/imgIDO/histogramme_equalizer_phare_exo1.png",dst);

    cout<<"les fichiers ont bien ete sauvegarde :" <<res2<<endl;


    for (i=0; i<3; i++){
        BGR[i].release();       //deallaouer la mémoire
    }
    img_phare.release();
    histog.release();
    dst.release();

    destroyAllWindows();

    return 0;
}
*/
/*
//EXO 2: FILTRE MOYENNEUR

int main(int argc, char** argv )
{
    String image_phare("phare.png");
    bool resultat;
    if (argc>1)
    {
        image_phare=argv[1];
    }
    Mat img_phare, dst;

    img_phare=imread(image_phare); //valeur par defaut est couleur

    if (img_phare.empty())
    {
        cout<<"Could not find the picture or open it "<<endl;
        cout<<image_phare<<endl;
        return -1;
    }

    //Creation du masque =[111;111;111]

    Mat masque (3,3, CV_32FC1, Scalar(1.0));

    filter2D(img_phare,dst,-1,masque);

    namedWindow("MASQUE PICTURE");
    namedWindow("PHARE PICTURE");
    namedWindow("CONVOLUTION PHARE PICTURE");

    imshow("MASQUE PICTURE", masque);
    imshow("PHARE PICTURE", img_phare);
    imshow("CONVOLUTION PHARE PICTURE", dst);
    // resultat: il y a un lissage (peu de variations de couleur), on ne voit plus les contours
    waitKey(0);

    resultat = imwrite("C:/imgIDO/convo_phare_picture_exo2.png",dst);

    cout<<"les fichiers ont bien ete sauvegarde :" <<resultat<<endl;

    masque.release();
    img_phare.release();
    dst.release();

    destroyAllWindows();

    return 0;
}
*/

/*
//EXO 3: NORMALISATION D UN FILTRE
int main(int argc, char** argv )
{
    String image_phare("phare.png");
    bool resultat;

    if (argc>1)
    {
        image_phare=argv[1];
    }
    Mat img_phare, dst;

    img_phare=imread(image_phare); //valeur par defaut est couleur

    if (img_phare.empty())
    {
        cout<<"Could not find the picture or open it "<<endl;
        cout<<image_phare<<endl;
        return -1;
    }
    //Creation du masque =[111;111;111]

    Mat masque (3,3, CV_32FC1, Scalar(1.0));
    Mat masque_normalize;

    //NOrmailse le masque tel que S=1 (conservation de la luminance) ==NORM_L1
    normalize(masque, masque_normalize,1.0,0,NORM_L1);

    //Application du masuqe par convolution sur l'img

    filter2D(img_phare,dst,-1,masque_normalize);

    namedWindow("MASQUE PICTURE");
    namedWindow("MASQUE_NORMALIZE PICTURE");
    namedWindow("PHARE PICTURE");
    namedWindow("CONVOLUTION PHARE PICTURE");

    imshow("MASQUE PICTURE", masque);
    imshow("MASQUE_NORMALIZE PICTURE", masque_normalize);
    imshow("PHARE PICTURE", img_phare);
    imshow("CONVOLUTION PHARE PICTURE", dst);
    // resultat: On retrouve presque l'image initiale grace à
    //la normalisation du masque. Cependant l'image reste floue (maque encore de luminance
    //ou la luminance d'origine n'est pas complètement récupérée, mais suffisante pour parler
    //de conservation ( on voit tout contrairement au résultat apres utilisation du filtre à l'exo 2)

    waitKey(0);

    resultat = imwrite("C:/imgIDO/convo_phare_picture_3x3Kernel_exo3.png",dst);


    cout<<"les fichiers ont bien été sauvegarde :" <<resultat<<endl;

    masque.release();
    masque_normalize.release();
    img_phare.release();
    dst.release();

    destroyAllWindows();

    return 0;
}
*/
/*
//EXO 4: TAILLE D UN FILTRE
int main(int argc, char** argv )
{
    String image_phare("phare.png");
    bool resultat;

    if (argc>1)
    {
        image_phare=argv[1];
    }
    Mat img_phare, dst;

    img_phare=imread(image_phare); //valeur par defaut est couleur

    if (img_phare.empty())
    {
        cout<<"Could not find the picture or open it "<<endl;
        cout<<image_phare<<endl;
        return -1;
    }
    //Creation du masque =[111;111;111]

    Mat masque (5,5, CV_32FC1, Scalar(1.0));

    Mat masque_normalize;

    //Normailse le masque tel que S=1 (conservation de la luminance) ==NORM_L1  soit (1/25)
    normalize(masque, masque_normalize,1.0,0,NORM_L1);

    //Application du masuqe par convolution sur l'img

    filter2D(img_phare,dst,-1,masque_normalize);

    namedWindow("MASQUE PICTURE");
    namedWindow("MASQUE_NORMALIZE PICTURE 5x5");
    namedWindow("PHARE PICTURE");
    namedWindow("CONVOLUTION PHARE PICTURE WITH 5x5 FILTER");

    imshow("MASQUE PICTURE", masque);
    imshow("MASQUE_NORMALIZE PICTURE 5x5", masque_normalize);
    imshow("PHARE PICTURE", img_phare);
    imshow("CONVOLUTION PHARE PICTURE WITH 5x5 FILTER", dst);
    // resultat: Plus on augmente la taille du filtre
    //plus l'img devient floue, soit plus la somme de coeff est importante
    //plus la normalisation est peu efficace (dans le cas: si on veut obtenir
    // l'img originale)


    waitKey(0);

    resultat = imwrite("C:/imgIDO/phare_picture.png",img_phare);
    bool res2=imwrite("C:/imgIDO/phare_normalize_5x5_Filter_exo4.png",dst);

    cout<<"les fichiers ont bien été sauvegardé :" <<resultat<<"::"<<res2<<endl;


    masque.release();
    masque_normalize.release();
    img_phare.release();
    dst.release();

    destroyAllWindows();

    return 0;

}
*/

//ExO 5: FILTRE MEDIAN
/*
int main(int argc, char** argv )
{
    String image_phare("phare_bruit_ps.png");
    bool resultat;

    if (argc>1)
    {
        image_phare=argv[1];
    }
    Mat img_phare, dst, dst_median;

    img_phare=imread(image_phare); //valeur par defaut est couleur

    if (img_phare.empty())
    {
        cout<<"Could not find the picture or open it "<<endl;
        cout<<image_phare<<endl;
        return -1;
    }
    //Creation du masque_moyenneur =[111;111;111]

    Mat masque (3,3, CV_32FC1, Scalar(1.0));
    Mat masque_normalize;

    //Normailse le masque tel que S=1 (conservation de la luminance) ==NORM_L1
    normalize(masque, masque_normalize,1.0,0,NORM_L1);

    //Application du masque par convolution sur l'img phare bruit

    filter2D(img_phare,dst,-1,masque_normalize);

    //Application d' un masque médian sur l'img phare bruit

    medianBlur(img_phare, dst_median, 3);


    namedWindow("PHARE PICTURE BRUIT");
    namedWindow("PHARE PICTURE BRUIT WITH MEDIAN FILTER");
    namedWindow("PHARE PICTURE BRUIT WITH MEAN FILTER");


    imshow("PHARE PICTURE BRUIT", img_phare);
    imshow("PHARE PICTURE BRUIT WITH MEDIAN FILTER", dst_median);
    imshow("PHARE PICTURE BRUIT WITH MEAN FILTER", dst);
    // resultat: on constate que le filtre moyenneur ne reduit pas
    //le bruit (floutte l'img (remplace certaine zone par du blanc ou gris)),
    //contrairement au filtre median qui reduit fortement
    //le bruit!


    waitKey(0);

    resultat = imwrite("C:/imgIDO/phare_picture_bruit_mean_filter_exo5.png",dst);
    bool res2=imwrite("C:/imgIDO/phare_bruit_median_filter_exo5.png",dst_median);

    cout<<"les fichiers ont bien été sauvegardé :" <<resultat<<"::"<<res2<<endl;

    masque.release();
    masque_normalize.release();
    img_phare.release();
    dst.release();
    dst_median.release();

    destroyAllWindows();

    return 0;
}
*/

//EXO 6: FILTRES DERIVATEURS

/*
void showKernel( Mat &kernel)
{
    int x,y;
    for (x=0;x<kernel.rows;x++)
    {
        for (y=0;y<kernel.cols;y++)
        {
            float& valeur=kernel.at<float>(y,x);
            cout<<valeur<<endl;
        }
    }
    cout<<"-----------------------"<<endl;
}

int main(int argc, char** argv )
{
    //Variables declaration

    String image_phare = argc >1 ? argv[1] : "phare_bruit_ps.png";
    int x, y, kernel_size,kernel2_size,ddepth=-1;
    float valeur;
    const char* wind_name= "filter2D_with_kernel"; //others way to create a wind without using namedWindow, saved line
    const char* wind_name2= "filter2D_with_kernel2";
    const char* wind_phare= "Phare bruit Picture";
    //Matrix
    Mat img_phare, dst,dst2, kernel, kernel2;

    //load img
    img_phare=imread(image_phare); //valeur par defaut est couleur

    if (img_phare.empty())
    {
        cout<<"Could not find the picture or open it "<<endl;
        cout<<image_phare<<endl;
        return -1;
    }

    //Kernel creation

    kernel= Mat::zeros(3,3,CV_32F);
    kernel2= Mat::zeros(3,3,CV_32F);

    for (x=0;x<3;x++)
    {
        for (y=0;y<3;y++)
        {
            if (x==0 && y==1)
            {
                kernel.at<float>(y,x)=-1;
            }
            else if (x==2 && y==1)
            {
                kernel.at<float>(y,x)=1;
            }

        }
    }

    for (x=0;x<3;x++)
    {
        for (y=0;y<3;y++)
        {
            if ((x==0 && y==1) || (x==1 && y==0) || (x==1 && y==2) || (x==2 && y==1) )
            {
                kernel2.at<float>(y,x)=1;
            }
            else if (x==1 && y==1)
            {
                kernel2.at<float>(y,x)=-4;
            }

        }
    }
    //Normalization of both kernel
    kernel_size=2;
    kernel2_size=8;
    kernel=kernel/(float)(kernel_size);
    kernel2=kernel2/(float)(kernel2_size);

    //Show kernel and kernel2 on cmd
    showKernel(kernel);
    showKernel(kernel2);

    //Apply Convolution Filter
    filter2D(img_phare,dst,ddepth,kernel);
    filter2D(img_phare,dst2,ddepth,kernel2);
    imshow(wind_name, dst);
    imshow(wind_name2, dst2);
    imshow(wind_phare, img_phare);

    waitKey(0);

    //Resultat: on constate pour les deux filtres que seule les formes des figures
    //sont conservées. Cependant le bruit est tjrs présent ce qui rend les figures
    //difficilement identifiables. De plus on obs que les contours sont legèrement
    //plus facile à identifier avec l'utilisation du filtre 1 qu'avec le filtre 2.

    bool res=imwrite("C:/imgIDO/kernel_phare_bruit_exo6.png",dst);
    bool res2=imwrite("C:/imgIDO/kernel2_phare_bruit_exo6.png",dst2);

    cout<<"les fichiers sont sauvegardés: "<< res <<"::"<<res2<<endl;


    return 0;
}
*/
//TRYING TO SAVE IMG ON A FILE
/*
int main()
{
    string image_path = samples::findFile("phare_bruit_ps.png");
    Mat img = imread(image_path, IMREAD_COLOR);

    if(img.empty())
    {
        cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        bool res= imwrite("C:/imgIDO/phare_bruit.png", img);
        cout<<"bool value :"<<res<<endl;
    }
    return 0;
}*/

/*----FIN DE L ENTRAINEMENT----*/
