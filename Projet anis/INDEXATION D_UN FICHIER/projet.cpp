#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;

typedef struct Tree {
	char*  mot;
	int    position[100];        //the position of paragraphe
	struct Tree *tleft, *tright;
} Tree;

bool Tree_exist(Tree *R) {
	if (R==NULL) return 0;
	else 		 return 1;
} 

Tree *new_tree(std::string word, int index) {
	Tree *tr = (Tree*)malloc(sizeof(*tr));
	if (tr == NULL) cout << "Error in allocation!\n";
	tr->mot          = strdup(word.c_str());
	tr->position[1]  = index;
	tr->tleft        = NULL;
	tr->tright       = NULL;
	tr->position[0]  = 1;
	cout << "- Tree is created| word:" << tr->mot << "  \t\t--> index: " << tr->position[1] <<"- \n";
	return tr;
}

void add_index(Tree *tr, int index) {
	if (index != 0) tr->position[0]++;
	if (index != tr->position[tr->position[0]-1] && index != 0) tr->position[tr->position[0]] = index;
	//cout << tr->mot << "---> " << index << " ------ " << tr->position[tr->position[0]] << "\n";	
}
/*
Tree *join_tree(Tree *L, Tree *R, std::string word, int index) {  // node = racine
	Tree *tr = new_tree(word, index);
	tr->tleft = L;
	tr->tright =R;
	return tr;
}*/

Tree *where(Tree *tr, std::string word) {
	std::string str=tr->mot;
	if (tr==NULL) return 0;	
	else {
		if (str > word && tr->tleft  != NULL)  return where(tr->tleft, word);
		if (str < word && tr->tright != NULL)  return where(tr->tright, word);
	}
	return tr;
}

Tree *creating(const char* file_name) {
	int i=1, set=0;
	Tree *tr;
	Tree *tree;
	std::string  word, c, str;
	char *compare;
    ifstream file;
	file.open(file_name);
    if (!file.is_open()) cout << "file doesn't exist - please be sure that the name is correct!\n";
    else {
		file >> word;
		c=word[word.size()-1];
		if (c == "." || c == "," || c ==";" || c =="?" || c == "!") word[word.size()-1] = '\0';
		tr = new_tree(word, i);
		if (c == ".") i++;
		tree = tr;
		while (file >> word) {
			c=word[word.size()-1];
			if (c == "." || c == "," || c ==";" || c =="?" || c == "!") word[word.size()-1] = '\0';
			compare=strdup(word.c_str());
			word = compare;
			tree=where(tr, word);
			str  = tree->mot;
			if      (str > word)    tree->tleft  = new_tree(word, i);
			else if (str < word)  	tree->tright = new_tree(word, i);
			else if (/*str == word &&*/ tree->position[tree->position[0]] != i)   add_index(tree, i);
			if (c == ".") i++;
		}
		file.close();
		return tr; 
    }
	return 0;
}

void infix(Tree *tr, bool b) {
	int j;
	if (b==1) cout << "|\tLES MOTS    |                LES POSITION               |\n";
	if (tr->tleft  != NULL) infix(tr->tleft , 0);
	cout << "|\t" << tr->mot << "\t" << "    | ";
	for (j=1; j <= tr->position[0]; j++) cout << tr->position[j] << " -- ";
	cout << "\n";
	if (tr->tright != NULL) infix(tr->tright, 0);  	
 
}

Tree *find_word(Tree *tr, std::string word) {  //si exist retourner le sommet sinon retourer NULL 
	Tree *tree = where(tr, word);
	std::string s=tree->mot;
	if (s==word) return tree;
	return NULL;
}

int *intersection(Tree *tr, std::string word1, std::string word2) { //if no intersection the value of inter[0] is 0
	Tree *tr1=find_word(tr, word1);
	Tree *tr2=find_word(tr, word2);
	int k=0, b=0;
	int *inter=(int*)calloc(100, sizeof(int));
	if      (tr1==NULL) {
		cout << '"' << word1 << '"' << " doesn't exist\n" ;
	} 
	else if (tr2==NULL) {
		cout << '"' << word2 << '"' << " doesn't exist\n" ;
	} 
	else {
 		for (int i=1; i<=tr1->position[0]; i++) {
			for (int j=1; j<=tr2->position[0]; j++) {
				if (tr1->position[i]==tr2->position[j]) {
					k++;
					inter[k]=tr1->position[i];
					break;
				}
			}
		}
	}
	inter[0]=k;
	return inter;
}
int *intersection_table(int *t1, int *t2) {
	int k=0;
	int *inter=(int*)calloc(100, sizeof(int));
	if  (t1[0]==0 || t2[0]==0) {
		free(inter);
		inter=NULL;
		cout << " word " << " doesn't exist\n" ;
	}
	else {
 		for (int i=1; i<=t1[0]; i++) {
			for (int j=1; j<=t2[0]; j++) {
				if (t1[i]==t2[j]) {
					k++;
					inter[k]=t1[i];
					break;
				}
			}
		}
	}
	inter[0]=k;
	return inter;
}

int *find_phrase(Tree *tr, string phrase) {
	int *val;
	Tree *tree, *finding;
	std::string word;	
	istringstream iss(phrase);
	iss >> word;
	tree= find_word(tr, word);
	val = tree->position;
	if (tree == NULL) val =NULL;
	while (iss >> word) {
		finding = find_word(tr, word);
		if (finding == NULL || tree == NULL) {
			val == NULL;
			break;
		}
		else val= intersection_table(val, finding->position);	
	}
	return val;
}

int main() {
	int i;
	int *intersection_word;
	const char *file_name="txt.txt";
	Tree *f, *tr;
	string phrase_a_trouver, s1, s2;
	
	//FONCTION DE CREATION DE L'ARBRE BINAIRE
	tr=creating(file_name);
	
	//PROCEDURE D'AFFICHAGE DE L'ARBRE BINAIRE
	infix(tr, 1);
	
	//FONCTION D'INTERSECTION DES POSITION DES MOTS DANS L'ARBRE BINAIRE
	cout << "------------------intersection_function:---------------\n->enter word 1:";
	cin  >> s1;
	cout << "->enter word 2:";
	cin  >> s2;
	intersection_word=intersection(tr , s1, s2);
	if (intersection_word[0]==0) cout << "no intersection!\n";
	else {
		cout << "Intersection paragraphes between (" << s1 << ") and (" << s2 << ") are: ";
		for (i=1; i<intersection_word[0]; i++) cout << intersection_word[i] << ", ";
		cout << intersection_word[i] << ".\n";
	} 

	//FONCTION DE RECHERCHE D'UNE PHRASE DANS LE FICHIER ".txt" EN UTILISON L'ARBRE BINAIRE DE RECHERCHE
	cout << "#############################################################################\n-> enter the sentence you wait to find: ";
	cin  >> phrase_a_trouver;
	int *vecteur = find_phrase(tr, phrase_a_trouver);
	if (vecteur != NULL) {
		cout << "the senence existe in paragraphe: ";
		for (i=1; i<vecteur[0]; i++) cout << vecteur[i] << ", ";
		cout << vecteur[i] << ".";
		cout << "\n";
	}
	else   cout << "the sentence > " << phrase_a_trouver << " < doesn't exist\n";
	return 0;
}
/*hicham. my name is hicham hicham. hicham. hicham. hicham. hicham.*/
