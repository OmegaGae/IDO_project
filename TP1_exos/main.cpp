/* HEADERS*/
#include <opencv2/core/core.hpp>
//#include <opencv2/imgcodecs.hpp> //pas besoin au final
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> // utile pour threshold

#include <iostream>
#include <string>


using namespace cv;
using namespace std;

//EXO1____TP1:

//ouverture de la image "Lenna.jpg" en 3 affichage diff
/*
int main( int argc, char** argv )
{
    //On verifie qu'il y a plus de 2 arguments (chemin exe et l'image)
    //soit on s'assure que le compilateur a trouve l'image (si il trouve le nom de l'image
    //nom qui sera stocke dans argv[1])
    String image_name("Lenna.jpg");                   //par defaut
    if( argc > 1)                                   // soit "!=" si on attend qu'1 arg si plus "<"
    {
     image_name=argv[1];

    }

    Mat image, image2, image3;                                      //creation d'un objet Mat (soit une matrice) qui devra stocker les donnees de notre img
    image = imread(image_name, IMREAD_COLOR);                       // Chargement de l'img (lecture de l'img)
    image2 = imread(image_name, IMREAD_GRAYSCALE);
    image3 = imread(image_name, IMREAD_UNCHANGED);
    if(! image.data )                                       // ou image.empty() et verifier si la lecture s'est bien passee (donc on a des donnees)
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window",WINDOW_AUTOSIZE );     // creation d'une fen de taille non modifiable et nommee "display window".
    namedWindow( "Display window2",WINDOW_AUTOSIZE );
    namedWindow( "Display window3",WINDOW_AUTOSIZE );
    imshow( "Display window", image );                      // afficher l'img (image) dans la fen nommee "Display window".
    imshow( "Display window2", image2 );
    imshow( "Display window3", image3 );

    waitKey(0);                                          // attendre l'appuie d une touche (affichage de l img indefiniment)
    return 0;
}*/

/*
int main( int argc, char** argv )
{
    int dimension, largeur, hauteur, profondeur, cano, poids;     //taille (octet), profondeur (bits) poids= largeur * hauteur * nbre de cano
    String image_name("Lenna.jpg");
    if( argc > 1)
    {
     image_name=argv[1];
    }

    Mat image;
    image=imread(image_name,IMREAD_ANYCOLOR);

    //Nbre de canaux
    cano=image.channels();

    //Hauteur et larheur d el'image (2 maniere)
    cout << "la largeur ou colog est "<<image.cols<<" Pixels"<< endl;
    cout << "la ligne ou hauteur est "<<image.rows<<" Pixels"<< endl;

    cout<<"la dimension est "<<image.rows<<" * "<<image.cols<< "Pixels"<<endl;

    cout<<"Deuxieme methode"<<endl;

    largeur=image.size().width;
    hauteur=image.size().height;
    dimension=largeur*hauteur;
    cout<<" la dimension = "<<largeur<<" * "<<hauteur<<" = "<< dimension<<" pixels"<<endl;

    //Poids
    poids=largeur*hauteur*cano;
    cout<< "Le poids = "<<largeur<<" * "<<hauteur<<" * "<<"3 = "<<poids<< " Pixels"<< endl;

    //Profondeur (2 manieres)
    profondeur=image.depth();
    cout<<"la profondeur de l'image (nbre de bits pr chq canal) est "<< profondeur <<endl;
    cout<<"la profondeur est : "<<image.type()<<endl; // les deux disent la même chose sauf que le format est diff  il faut retranscrire voir favoris sur internet
                                                     // c'est donc du CV_8UC3 soit 3 cano code sur 8 bits soit 24 bits/pixels
    //taille en octet
    dimension= (largeur*hauteur)*24; // ou poids
    cout<<"La dimension de  l'image est de "<<dimension<<" bits soit "<<dimension/8<<" Octets"<< endl;


    if ( !(image.data) )
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Lenna window",WINDOW_AUTOSIZE );
    imshow( "Lenna window", image );
    waitKey(0);

    return 0;
}
*/


//EXO 2:
/*
int main( int argc, char** argv )
{
    String image_name("Lenna.jpg");
    Mat image;

    if (argc >1)
    {
        image_name=argv[1];
    }

    image= imread(image_name);

    if (image.empty())
    {
        cout<< "Could not open or find the image "<<endl;
        cout<< image_name <<endl;
        return -1;
    }
    //SEPARATION DES CANAUX DE L IMAGE SOIT 3 CANAUX
    Mat BGR[3];
    split(image,BGR);               //BGR[3] canaux (channels) couleurs bleu vert rouge

    namedWindow("IMAGE INITIALE");
    imshow("IMAGE INITIALE",image);

    namedWindow("COMPOSANT R");
    imshow("COMPOSANT R", BGR[2]);

    namedWindow("COMPOSANT G");
    imshow("COMPOSANT G", BGR[1]);

    namedWindow("COMPOSANT B");
    imshow("COMPOSANT B", BGR[0]);

    Mat image_merge;
    merge(BGR,3,image_merge);

    namedWindow("MULTIPLEXAGE");
    imshow("MULTIPLEXAGE",image_merge);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
*/
/*
int main (int argc, char** argv )
{
    //CREATION D UNE IMAGE DEGRADEE

    Mat image_degradee(200,256,CV_8UC1,255); //ça fct aussi avec Scalar(255)

    for (int x=0;x<256;x++)
    {
        for (int y=0;y<200;y++)
        {
            image_degradee.at<uchar>(y,x)=x;

        }
    }

    namedWindow("IMAGE DEGRADEE CREEE");
    imshow("IMAGE DEGRADEE CREEE", image_degradee);
    waitKey(0);
    destroyAllWindows();

    //CREATION DE L IMAGE 0000120255120000 (CARREE 9X9)
    Mat img (9,9,CV_8UC1,Scalar(0));        //FAUT UTILISER Scalar sinon bug au dessus (tjrs a utiliser)!!

    cout<<"debut"<<endl;
    for ( int x=2; x<7; x++)
    {
        for (int y=2; y<7; y++)
        {
            img.at<uchar>(y,x)=120;
        }
    }
    for ( int x=3; x<6; x++)
    {
        for (int y=3; y<6; y++)
        {
            img.at<uchar>(y,x)=255;
        }
    }
    cout<<"milieu"<<endl;
    namedWindow("IMAGE DEGRADEE CENTREE", WINDOW_FREERATIO);
    imshow("IMAGE DEGRADEE CENTREE", img);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
*/

//EXO 4

/*
void imageNiveauDeGrisMax(Mat &gris)
{
    int rg, colg, valeur,x,y;
    rg=gris.size().width;
    colg=gris.size().height;

    for (x=0; x<rg; x++)
    {
        for (y=0; y<colg; y++)
        {
            if(valeur< gris.at<uchar>(y,x))
            {
                valeur=gris.at<uchar>(y,x);
            }
        }
    }

    cout<<"Le niveau de gris Max de l'image est : "<<valeur<<endl;
}

int main (int argc, char** argv)
{
    String image_filename("Lenna.jpg");
    if (argc > 1)
    {
        image_filename=argv[1];

        cout<< argv[1]<<endl;
    }
    Mat img_lenna, img_nivgris;
    img_lenna=imread(image_filename);

    if(! img_lenna.data )                                       // ou image.empty() et verifier si la lecture s'est bien passee (donc on a des donnees)
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    cvtColor(img_lenna,img_nivgris,COLOR_BGR2GRAY, 0);

    imageNiveauDeGrisMax(img_nivgris);

    namedWindow("IMAGE INITIALE");
    namedWindow("IMAGE CONVERTIE");
    imshow("IMAGE INITIALE",img_lenna);
    imshow("IMAGE CONVERTIE",img_nivgris);
    waitKey(0);

    return 0;

}*/

//EXO 5



int main (int argc, char** argv)
{
    String img_filenamelenna("Lenna.jpg"), img_filenamegris("Gris.jpg");
    if (argc > 2)
    {
        img_filenamelenna=argv[1];
        img_filenamegris=argv[2];
    }
    Mat img_lenna, img_gris;


    img_lenna=imread(img_filenamelenna);
    img_gris=imread(img_filenamegris);

    if(!(img_gris.data) || !(img_lenna.data) )                                       // ou image.empty() et verifier si la lecture s'est bien passee (donc on a des donnees)
    {
        cout <<  "Could not open or find one of the image " << std::endl ;
        return -1;
    }
    //SEPARATION DES CANAUX DE L IMAGE LENNA SOIT 3 CANAUX
    Mat BGR[3];
    split(img_lenna,BGR);

    namedWindow("IMAGE INITIALE");
    imshow("IMAGE INITIALE",img_lenna);

    namedWindow("IMAGE GRIS INITIALE");
    imshow("IMAGE GRIS INITIALE",img_gris);

    namedWindow("COMPOSANT R");
    imshow("COMPOSANT R", BGR[2]);

    namedWindow("COMPOSANT G");
    imshow("COMPOSANT G", BGR[1]);

    namedWindow("COMPOSANT B");
    imshow("COMPOSANT B", BGR[0]);
    waitKey(0);


    int rg, colg, rg_gris, colg_gris,x,y; //rg for rangee and colg for colonne
    colg=img_lenna.size().width;
    rg=img_lenna.size().height;
    cout<<rg<<"et"<<colg<<endl;

    colg_gris=img_gris.size().width;
    rg_gris=img_gris.size().height;
    cout<<rg_gris<<"et"<<colg_gris<<endl;
   /* int profondeur= img_gris.type();

    //I want to switch the colonn and the width of img_gris
    Mat img_gris_inversee (colg_gris,rg_gris,profondeur,Scalar(0));

    for (x=0; x<colg_gris;x++)
    {
        for (y=0;y<rg_gris;y++)
        {

           img_gris_inversee.at<uchar>(y,x)=img_gris.at<uchar>(y,x);

        }
    }*/

    //CONVERTION DE L IMAGE EN NEGATIF
    for (x=0; x<colg;x++)
    {
        for (y=0;y<rg;y++)
        {
            BGR[0].at<uchar>(y,x)=255-BGR[0].at<uchar>(y,x);    //application de la fct inverse sur la composant rouge
            BGR[1].at<uchar>(y,x)=255-BGR[1].at<uchar>(y,x);    //G
            BGR[2].at<uchar>(y,x)=255-BGR[2].at<uchar>(y,x);    //R
        }
    }


    for (x=0; x<colg_gris;x++)
    {
        for (y=0;y<rg_gris;y++)
        {
            try
            {

                img_gris.at<uchar>(y,x)=255-img_gris.at<uchar>(y,x);    //application de la fct inverse sur le composant rouge

            }
            catch (exception &exp)
            {
                cout << "Exception occured"<< endl;
                return -1;
            }

        }
    }

    namedWindow("IMAGE GRIS INVERSE");
    imshow("IMAGE GRIS INVERSE",img_gris);

    namedWindow("COMPOSANT R INVERSE");
    imshow("COMPOSANT R INVERSE", BGR[2]);

    namedWindow("COMPOSANT G INVERSE");
    imshow("COMPOSANT G INVERSE", BGR[1]);

    namedWindow("COMPOSANT B INVERSE");
    imshow("COMPOSANT B INVERSE", BGR[0]);

    Mat image_merge;
    merge(BGR,3,image_merge);

    namedWindow("IMAGE NEGATIVE LENNA");
    imshow("IMAGE NEGATIVE LENNA", image_merge);

    waitKey(0);
    destroyAllWindows();

    return 0;

}

//EXO 6 SEUILLAGE
/*
void histogramme(Mat img) {

int largeur, hauteur, valeur =0, x,y,histo[256],cumul[256];
    largeur = img.size().width;
    hauteur = img.size().height;
    Mat histog,cumu;
    //INITIALISATION DES TABLEAUX A 0
    for (valeur=0; valeur<256 ;valeur++){
        histo[valeur]=0;
        cumul[valeur]=0;
    }
    //A CHQ APPARITION D UN NIV D INTENSITE IDENTIQUE SUR UN PIXEL ON AJOUTE +1 DANS LE TAB HISTO A INDICE CORRESPONDANT
    for (x=0; x<largeur; x++){
        for(y=0; y<hauteur; y++){
            histo[img.at<uchar>(y,x)]++;
        }
    }
    //ON FAIT LE CUMUL CAD ON REGARDE TJRS LES VALEURS DES PIXELS PRECEDENT ET CELA DEPUIS LE PIXEL DE DEPART
    /*for (valeur=0; valeur<255 ;valeur++){
        y=0;
        for (x=0;x<valeur+1;x++){
            y=y+histo[x];
        }
        cumul[valeur]=y;
    }*/
    //ON CREE UNE IMAGE QUI VA TRADUIRE NOTRE HISTO (POINT NOIR OU BLANC)
    /*histog = Mat(256,256,CV_8UC1,Scalar(0));
    for (x=0; x<256; x++){
        for(y=0; y<256; y++){
            if (y==histo[x]){
                histog.at<uchar>(y,x)=255;}
            else
            {   histog.at<uchar>(y,x)=0;}

        }
    }*/
    //ON CREE UNE IMAGE QUI VA TRADUIRE NOTRE HISTO CUMULE (POINT NOIR OU BLANC)
    /*cumu = Mat(256,cumul[255],CV_8UC1,Scalar(0));
    for (x=0; x<256; x++){
        for(y=0; y<cumul[255]; y++){
            if (y==cumul[x]){
                cumu.at<uchar>(y,x)=255;
            }
        }
    }*/
    //namedWindow( "Display window : histogramme"); // Create a window for display.
    //imshow( "Display window : histogramme", histog );
    //namedWindow( "Display window : cumul"); // Create a window for display.
    //imshow( "Display window : cumul", cumu );               // Show our image inside it.







/*



void trackseuillage (int T, void* gris){
    Mat img;
//    threshold(*(Mat*)(gris), img, T, 255, THRESH_BINARY);
    threshold(*(Mat*)(gris), img, T, 255, THRESH_TRUNC);
//    threshold(*(Mat*)(gris), img, T, 255, THRESH_OTSU+THRESH_BINARY);
    imshow( "Display window : seuillage gris", img );
}

int main (int argc, char** argv)
{
    String img_filenamelenna("Lenna.jpg"), img_filenamegris("Lenna_gris.jpg");
    int T, rg,colg, x, y,i;
    if (argc > 2)
    {
        img_filenamelenna=argv[1];
        img_filenamegris=argv[2];
    }
    Mat img_lenna, img_gris, img_nivgris, BGR[3];

    img_lenna=imread(img_filenamelenna);
    img_gris=imread(img_filenamegris);

    if (!(img_gris.data) || !(img_lenna.data) )                                       // ou image.empty() et verifier si la lecture s'est bien passee (donc on a des donnees)
    {
        cout <<  "Could not open or find one of the image " << std::endl ;
        return -1;
    }

    //SEUILLAGE EN NIV DE GRIS

    rg=img_gris.size().width;
    colg=img_gris.size().height;

    cvtColor(img_gris,img_nivgris,COLOR_BGR2GRAY, 0);       //img couleur mais en gris, donc ca ne fct pas, d ou le passage en niv de gris

    namedWindow("IMAGE LENNA GRIS");
    imshow("IMAGE LENNA GRIS",img_gris);
    namedWindow("IMAGE LENNA EN NIVEAU DE GRIS");
    imshow("IMAGE LENNA EN NIVEAU DE GRIS",img_nivgris);
    waitKey(0);
    destroyAllWindows();

    cout<<"Veuillez choisir la valeur du seuillage : "<<endl;
    cin>>T;

    for (x=0;x<rg;x++)
    {
        for (y=0;y<colg;y++)
        {
            if (img_nivgris.at<uchar>(y,x)>T)
            {
                img_nivgris.at<uchar>(y,x)=0;
            }
            else
            {
                img_nivgris.at<uchar>(y,x)=255;
            }
        }
    }

    namedWindow("IMAGE LENNA EN NIVEAU DE GRIS APRES SEUILLAGE T");
    imshow("IMAGE LENNA EN NIVEAU DE GRIS APRES SEUILLAGE T",img_nivgris);
    waitKey(0);
    destroyAllWindows();

    //SEUILLAGE AVEC UNE IMAGE COULEUR
    rg=img_lenna.size().width;
    colg=img_lenna.size().height;

    split(img_lenna,BGR);

    for (x=0;x<rg;x++)
    {
        for (y=0;y<colg;y++)
        {
            if (BGR[0].at<uchar>(y,x)>T)
            {
                BGR[0].at<uchar>(y,x)=0;
            }
            else
            {
                BGR[0].at<uchar>(y,x)=255;
            }

            if (BGR[1].at<uchar>(y,x)>T)
            {
                BGR[1].at<uchar>(y,x)=0;
            }
            else
            {
                BGR[1].at<uchar>(y,x)=255;
            }

            if (BGR[2].at<uchar>(y,x)>T)
            {
                BGR[2].at<uchar>(y,x)=0;
            }
            else
            {
                BGR[2].at<uchar>(y,x)=255;
            }
        }
    }

    namedWindow("IMAGE LENNA COULEUR");
    imshow("IMAGE LENNA COULEUR",img_lenna);

    namedWindow("IMAGE LENNA COMPOSANT B AVEC SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANT B AVEC SEUILLAGE T",BGR[0]);

    namedWindow("IMAGE LENNA COMPOSANT G AVEC SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANT G AVEC SEUILLAGE T",BGR[1]);

    namedWindow("IMAGE LENNA COMPOSANT R AVEC SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANT R AVEC SEUILLAGE T",BGR[2]);

    waitKey(0);
    destroyAllWindows();

    //ON FAIT LA MEME CHOSE QU4AU DESSUS MAIS AVEC UNE FCT DEJA PRETE
    threshold(img_lenna,img_lenna,T,255,THRESH_BINARY);
    threshold(img_gris,img_gris,T,255,THRESH_BINARY);       //Mauvaise representation
    threshold(img_nivgris,img_nivgris,T,255,THRESH_BINARY); //Bonne represnetation

    namedWindow("IMAGE LENNA SEUILLAGE T");
    imshow("IMAGE LENNA SEUILLAGE T",img_lenna);

    namedWindow("IMAGE LENNA GRIS SEUILLAGE T");
    imshow("IMAGE LENNA GRIS SEUILLAGE T",img_gris);

    namedWindow("IMAGE LENNA NIV GRIS SEUILLAGE T");
    imshow("IMAGE LENNA NIV GRIS SEUILLAGE T",img_nivgris);
    /*threshold permet d' appliquer le seuil sur toute img
    pas besoin que celle ci soit en niv de gris (monochrome)
    contrairement à la méthode de seuillage avec une boucle for.
    Mais il y a des erreurs ou bugs (sorte de coupure de traitement (ligne)
    lorsque le niv de gris n'est pas appliqué )Ex:
    lorsqu'on appliquait le seuil sur l'img lenna_gris directement
    (sans la convertion en niv de gris)on observait aucune application
    du seuil sur l'image.
    Cependant avec la fct threshold, on obs l'application du seuil
    meme avec l'img initiale. Mais l'application du seuil sur la même image
    passée en niv de gris, on observe un résultat inverse ou identique avec une coupure. CAD les pixels
    noirs sur l'img intiale sont blanc sur l'img en niveau de gris
    (observe ce phenomene avec lenna gris (sans niv de gris) et avec niv de gris grace
     a cvtColor)*/

     /*

    threshold(BGR[0],BGR[0],T,255,THRESH_BINARY);
    threshold(BGR[1],BGR[1],T,255,THRESH_BINARY);
    threshold(BGR[2],BGR[2],T,255,THRESH_BINARY);


    namedWindow("IMAGE LENNA COMPOSANTE B SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANTE B SEUILLAGE T",BGR[0]);

    namedWindow("IMAGE LENNA COMPOSANTE G SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANTE G SEUILLAGE T",BGR[1]);

    namedWindow("IMAGE LENNA COMPOSANTE R SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANTE R SEUILLAGE T",BGR[2]);

    threshold(BGR[2],BGR[1],T,255,THRESH_BINARY);       //Le 2eme parametre n'est qu'une matrice de destination, on peut mettre ce que l'on veut tant que la matrice de dest à la mm taille,nbre de channel, et mm type que la matrice src
    namedWindow("IMAGE LENNA COMPOSANTE G TRY SEUILLAGE T");
    imshow("IMAGE LENNA COMPOSANTE G TRY SEUILLAGE T",BGR[1]);      //donne la meme chose que ligne 544 (ce qui est normal)

    waitKey(0);
    destroyAllWindows();

    namedWindow( "Display window : seuillage gris", WINDOW_AUTOSIZE ); // Create a window for display.
    createTrackbar("seuil", "Display window : seuillage gris",&T, 255, trackseuillage,&BGR[0]);
    trackseuillage(T, &BGR[0]);                                         // fonctionne pas vraiment ..pas de chnagement lorsqu'on change le seuil avec le joystick

    histogramme(img_nivgris);

    waitKey(0);

    for (i=0; i<3; i++){
        BGR[i].release();       //deallaouer la mémoire
    }
    img_gris.release();
    img_nivgris.release();
    img_lenna.release();

    destroyAllWindows();

    return 0;
}*/
