#ifndef __OCTET__
#define __OCTET__
struct Octet{};

Octet creerOctet();
Octet ajouter(Octet o, CodeBinaire cd);
Octet supprimer(Octet o, CodeBinaire cd);
char* encoder(Octet o,CodeBinaire cb);
Octet decoder(char* c,CodeBinaire cb);
Octet obtenirOctet(char* chaine);


#endif