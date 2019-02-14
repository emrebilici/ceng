#ifndef TWOPHASEBST_H
#define TWOPHASEBST_H

#include <iostream>
#include <string>
#include <stack>
#include <list>
// do not add any other library.
// modify parts as directed by assignment text and comments here.

template <class T>
class TwoPhaseBST {
private: //do not change
    struct SecondaryNode {
        std::string key;
        T data;
        SecondaryNode *left;
        SecondaryNode *right;

        SecondaryNode(const std::string &k, const T &d, SecondaryNode *l, SecondaryNode *r);
    };

    struct PrimaryNode {
        std::string key;
        PrimaryNode *left;
        PrimaryNode *right;
        SecondaryNode *rootSecondaryNode;

        PrimaryNode(const std::string &k, PrimaryNode *l, PrimaryNode *r, SecondaryNode *rsn);
    };

public: // do not change.
    TwoPhaseBST();
    ~TwoPhaseBST();

    TwoPhaseBST &insert(const std::string &primaryKey, const std::string &secondaryKey, const T &data);
    TwoPhaseBST &remove(const std::string &primaryKey, const std::string &secondaryKey);
    TwoPhaseBST &print(const std::string &primaryKey = "", const std::string &secondaryKey = "");
    T *find(const std::string &primaryKey, const std::string &secondaryKey);

private: // you may add your own utility member functions here.
    void destructNode(PrimaryNode * &root);
    void destructNode(SecondaryNode * &root);

    TwoPhaseBST &insert_helper1(const std::string & k, const std::string & k1, const T & d, PrimaryNode* &p );
    TwoPhaseBST &insert_helper2(const std::string & k1, const T & d , SecondaryNode* &s);
    void print_helper(PrimaryNode* &p, SecondaryNode* &s);
    void print_helper2(PrimaryNode* &p, SecondaryNode* &s);
    T *findpr(PrimaryNode* &p, const std::string &primaryKey, const std::string &secondaryKey);
    T *findsec(SecondaryNode* &s, const std::string &secondaryKey);
    bool search2(const std::string &secondaryKey, SecondaryNode* &s);
    bool search1(const std::string &primaryKey, PrimaryNode* &p);
    TwoPhaseBST &removehelper(SecondaryNode* &s, const std::string &secondaryKey);

private: // do not change.
    PrimaryNode *root; //designated root.

    // do not provide an implementation. TwoPhaseBST's are not copiable.
    TwoPhaseBST(const TwoPhaseBST &);
    const TwoPhaseBST &operator=(const TwoPhaseBST &);
};

template <class T>
TwoPhaseBST<T>::SecondaryNode::SecondaryNode(const std::string &k, const T &d, SecondaryNode *l, SecondaryNode *r)
        : key(k), data(d), left(l), right(r) {}

template <class T>
TwoPhaseBST<T>::PrimaryNode::PrimaryNode(const std::string &k, PrimaryNode *l, PrimaryNode *r, SecondaryNode *rsn)
        : key(k), left(l), right(r), rootSecondaryNode(rsn) {}

template <class T>
TwoPhaseBST<T>::TwoPhaseBST() : root(NULL) {}

template <class T>
TwoPhaseBST<T>::~TwoPhaseBST() {
    destructNode(root);
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::insert(const std::string &primaryKey, const std::string &secondaryKey, const T &data) {
    /* IMPLEMENT THIS */
    insert_helper1(primaryKey, secondaryKey, data, root);
    //std::cout<<std::endl;
    //std::cout<<root->key;
    return *this ;
    
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::remove(const std::string &primaryKey, const std::string &secondaryKey) {
    /* IMPLEMENT THIS */
	//primarykey olmaması durumu buraya gelecek
		PrimaryNode* current = root;
	    while (current != NULL) 
	    { 
	        if (primaryKey > current->key) 
	            current = current->right; 
	  
	        else if (primaryKey < current->key) 
	            current = current->left; 
	        else {
	            
	            removehelper(current->rootSecondaryNode,secondaryKey);  //removehelper olabilir
	            break; // if the key is found break
	        }
	                
	    }
	    return *this;
		
}

template <class T>
TwoPhaseBST<T> &TwoPhaseBST<T>::print(const std::string &primaryKey, const std::string &secondaryKey) {
    /* IMPLEMENT THIS */
    
    if(primaryKey=="" && secondaryKey==""){
      if(root!=NULL){
        std::cout<<"{";
        print_helper(root,root->rootSecondaryNode);
        std::cout<< "}\n";
      }
      else{
        std::cout<<"{}\n";
      }
    }
    else if(primaryKey!="" && secondaryKey==""){
      std::cout<<"{";
      PrimaryNode* current = root;
      while (current != NULL) 
      { 
      	if(!search1(primaryKey, current)){
            	break;
        }
        // pass right subtree as new tree 
        if (primaryKey > current->key) 
            current = current->right; 
  
        // pass left subtree as new tree 
        else if (primaryKey < current->key) 
            current = current->left; 
        else {
            //std::cout<<"{";
            std::cout<<"\"";
            std::cout<<current->key;
            std::cout<<"\"";
            std::cout<<" : ";
            std::cout<<"{";
            print_helper2(current,current->rootSecondaryNode);
            std::cout<<"}";
            break; // if the key is found break
        }        
      }    
      std::cout<<"}\n";
    }

    else if(primaryKey!="" && secondaryKey!=""){

          std::cout<<"{";
          PrimaryNode* current = root;
          while (current != NULL) 
          { 
          	if(!search1(primaryKey, current)){
            	break;
            }
            // pass right subtree as new tree 
            if (primaryKey > current->key) 
                current = current->right; 
      
            // pass left subtree as new tree 
            else if (primaryKey < current->key) 
                current = current->left; 
            else {

            	if(!search2(secondaryKey, current->rootSecondaryNode)){
            		break;
            	}
            	else{
	                std::cout<<"\"";
	                std::cout<<current->key;
	                std::cout<<"\"";
	                std::cout<<" : ";
	                std::cout<<"{";
	                std::cout<<"\"";
	                std::cout<<secondaryKey;
	                std::cout<<"\"";
	                std::cout<<" : ";
	                std::cout<<"\"";
	                std::cout<< *findsec(current->rootSecondaryNode, secondaryKey);
	                std::cout<<"\"";
	                std::cout<<"}";
	                break; // if the key is found break
	           } 
            }                     
          }             
          std::cout<<"}\n";        
    }   
    return *this;
}

template <class T>
T *TwoPhaseBST<T>::find(const std::string &primaryKey, const std::string &secondaryKey) {
    /* IMPLEMENT THIS */
  	return findpr(this->root, primaryKey,secondaryKey);

 


}





template <class T>
T* TwoPhaseBST<T>::findpr(PrimaryNode* &p,const std::string &primaryKey, const std::string &secondaryKey){
    if(p==NULL){
    	return NULL;
    }
  
	else if(primaryKey==p->key){
	    return findsec(p->rootSecondaryNode, secondaryKey );
	}
	else if(primaryKey < p->key){
		findpr(p->left, primaryKey,secondaryKey);
	}
	else if(primaryKey > p->key) {
		findpr(p->right, primaryKey,secondaryKey);
	}
  
}
template <class T>
T* TwoPhaseBST<T>::findsec(SecondaryNode* &s, const std::string &secondaryKey){
 	if(s==NULL){
    	return NULL;
    }
    else if(secondaryKey==s->key){
		return &s->data;
	}
	else if(secondaryKey < s->key){
		findsec(s->left,secondaryKey);
	}
	else if(secondaryKey > s->key) {
		findsec(s->right,secondaryKey);
	}

}

template <class T>
void TwoPhaseBST<T>::destructNode(TwoPhaseBST::PrimaryNode * &root)
{
    if (root == NULL)
        return;

    destructNode(root->left);
    destructNode(root->right);

    destructNode(root->rootSecondaryNode);

    delete root;

    root = NULL;
}

template <class T>
void TwoPhaseBST<T>::destructNode(TwoPhaseBST::SecondaryNode * &root)
{
    if (root == NULL)
        return;

    destructNode(root->left);
    destructNode(root->right);

    delete root;

    root = NULL;
}


template <class T>
bool TwoPhaseBST<T>::search2(const std::string &secondaryKey, SecondaryNode* &sec) {
	if(sec == NULL){
		return false;
	}


	  SecondaryNode* s = sec;
      if (secondaryKey == s->key)

            return true;

      else if (secondaryKey < s->key) {

            if (s->left == NULL)

                  return false;

            else

                  return search2(secondaryKey,s->left);

      } else if (secondaryKey > s->key) {

            if (s->right == NULL)

                  return false;

            else

                  return search2(secondaryKey,s->right);

      }

      return false;
}

template <class T>
bool TwoPhaseBST<T>::search1(const std::string &primaryKey, PrimaryNode* &p) {
	if(p == NULL){
		return false;
	}
      if (primaryKey == p->key)

            return true;

      else if (primaryKey < p->key) {

            if (p->left == NULL)

                  return false;

            else

                  return search1(primaryKey,p->left);

      } else if (primaryKey > p->key) {

            if (p->right == NULL)

                  return false;

            else

                  return search1(primaryKey,p->right);
      }
      return false;
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::insert_helper1(const std::string &primaryKey , const std::string & secondaryKey, const T & data, PrimaryNode* & p){
  if( p == NULL){
    //std::cout<<"root null"<<std::endl;
    p = new PrimaryNode(primaryKey, NULL, NULL, NULL);
    insert_helper2(secondaryKey, data, p->rootSecondaryNode);
  }
  else if(primaryKey.compare(p->key) < 0){
    //std::cout<<"p < "<<std::endl;
    insert_helper1(primaryKey, secondaryKey,data, p->left);
  }
  else if(primaryKey.compare(p->key) > 0 ){
    //std::cout<<"p > "<<std::endl;
    insert_helper1(primaryKey, secondaryKey,data,p->right);
  }
  else if(primaryKey == p->key){
    //std::cout<<" = "<<std::endl;
    insert_helper2(secondaryKey,data,p->rootSecondaryNode);
  }
    return *this;
}

template <class T>
TwoPhaseBST<T> & 
TwoPhaseBST<T>::insert_helper2(const std::string & sec, const T & d, SecondaryNode* & s){
  if(s==NULL){

    s = new SecondaryNode(sec,d,NULL,NULL);
    
  }
  else if(sec.compare(s->key) < 0){

    insert_helper2(sec, d, s->left);
  }
  else if(sec.compare(s->key) > 0){
    insert_helper2(sec, d, s->right);
  }
    return *this;
}

template <class T>
void TwoPhaseBST<T>::print_helper(PrimaryNode* &p, SecondaryNode* &s){
   
    if(p!=NULL){;
    
        print_helper(p->left, s);
       
        std::cout<<"\"";
        std::cout<<p->key;
        std::cout<<"\"";

        std::cout<< " : ";
        
        std::cout<< "{";
        print_helper2(p, p->rootSecondaryNode);

        std::cout<< "}";
       
        PrimaryNode* c = root;
        while(c->right){
          c = c->right;
        }
        if(c->key!=p->key) std::cout<< ", ";

        print_helper(p->right,s);
    }

}

template <class T>
void TwoPhaseBST<T>::print_helper2(PrimaryNode* &p, SecondaryNode* &s){

   if(s!=NULL){

		
        print_helper2(p,s->left);

        std::cout<< "\"";
        std::cout<<s->key;
        std::cout<< "\"";
        std::cout<< " : ";
 	
        std::cout<< "\"";
        std::cout<<s->data ;
        std::cout<< "\"";
        SecondaryNode* c = p->rootSecondaryNode;
        while(c->right){
            c = c->right;
        }
        if(c->key!=s->key) std::cout<< ", ";

      	
        print_helper2(p,s->right);


}




}



template <class T>
TwoPhaseBST<T> & 
TwoPhaseBST<T>::removehelper(SecondaryNode* &s, const std::string &secondaryKey){

		if(s==NULL){
			return *this;
		}
		if(s->key > secondaryKey){
			removehelper(s->left, secondaryKey);
		}
		else if(s->key < secondaryKey){
			removehelper(s->right, secondaryKey);
		}
		else if(s->left !=NULL && s->right != NULL){
			SecondaryNode* current = s->right;
			while(current->left){
				current = current->left;
			}
			//s->key = current->key;
			//s->data = current->data;
            
			removehelper(s->right, s->key);
            //s=NULL;
            //insert_helper2(current->key, current->data, s);
			s = new SecondaryNode(current->key,current->data,s->left,s->right);
		}
		else{
			SecondaryNode* old = s;
			s = (s->left != NULL) ? s->left : s->right;
			delete old;
		}
    return *this;
}

#endif //TWOPHASEBST_H
