#include "Multi_Set.h"

// Default constructor
Multi_Set::Multi_Set(void) {
	for (int i = 0; i < num; i++) elements[i] = '0';
}

// Constructor
Multi_Set::Multi_Set(char* str,int len) {

	for (int i = 0; i < len+1; i++) elements[i] = '/0';
    int i=0;
   /* char* strif;
    for (int i=0;i<len+1;i++)
        strif[i]=str[i];*/
    char * pch = strtok (str,",");
    while (pch != NULL)
    {

        strcpy(&elements[i++],pch);
        capacity++;
        pch = strtok (NULL, ",");
    }
    sort(elements,elements+capacity);
	}


// Output all CharSet on screen
void Multi_Set::outputSet(void) const {
    cout<<"Number of elements in a set: "<<capacity<<"   ";
    cout<<endl<<"SET :  ";
    for (int i=0;i<capacity;i++){
        cout<<elements[i]<<"  ";
    }
    cout<<endl;
}

bool Multi_Set::checkout(){
    if ((elements[0]=='/0')||capacity==0)
        return false;
    return true;
}

int Multi_Set::getter()
{
    return capacity;
}

void Multi_Set::push(char* str,int len){
    for (int i = 0; i < len+1; i++) elements[i] = '/0';
    int i=0;
    char * pch = strtok (str,",");
    while (pch != NULL)
    {
        strcpy(&elements[i++],pch);
        capacity++;
        pch = strtok (NULL, ",");
    }
    sort(elements,elements+capacity);
}

// ---- OPERATIONS ----

//Union
Multi_Set Multi_Set::operator+ ( Multi_Set &obj){
	Multi_Set tmp = (*this);
	Multi_Set result;
	result.capacity=tmp.capacity;
	for (int i=0;  i<tmp.capacity; i++)
        result.elements[i]=tmp.elements[i];


        for (int j=0;j<obj.capacity;j++)

        result.elements[result.capacity++]=obj.elements[j];

	sort(result.elements,result.elements+result.capacity);
	result.elements[result.capacity]='/0';
	return result;
}

Multi_Set Multi_Set::operator+= ( Multi_Set obj) {
	for (int i = 0; i <obj.capacity; i++)
            this->elements[this->capacity++] = obj.elements[i];

	sort(this->elements,this->elements+this->capacity);
	this->elements[this->capacity]='/0';
	return (*this);
}

//Difference
Multi_Set Multi_Set::operator- (Multi_Set obj) {
	Multi_Set tmp=(*this);
	Multi_Set result;
	result.capacity=tmp.capacity;
	for (int i=0;  i<tmp.capacity;i++)
        result.elements[i]=tmp.elements[i];
	for (int i = 0; i < obj.capacity; i++){
        for (int j=0;j<result.capacity;j++){
            if (result.elements[j]==obj.elements[i]){
                int ccount = j;
                for (;ccount<result.capacity;ccount++)
                    result.elements[ccount]=result.elements[ccount+1];
                    //result.elements[ccount+1]='/0';
                    result.capacity--;
                    break;
            }

        }
	}
	return result;
}

Multi_Set Multi_Set::operator-= ( Multi_Set obj) {
    int ccount=0;
	for (int i = 0; i < obj.capacity; i++)
        for (int j=0; j<this->capacity;j++)
            if (this->elements[j]==obj.elements[i]){
                for ( ccount = j;ccount<this->capacity;ccount++)
                    this->elements[ccount]=this->elements[ccount+1];
                this->elements[ccount+1]='/0';
                this->capacity--;
                break;
            }

	return (*this);
}

//Intersection
 Multi_Set Multi_Set::operator* (Multi_Set obj)  {
	Multi_Set tmp = (*this);
	Multi_Set result;
	Multi_Set help;
	for (int i=0;i<obj.capacity;i++)
        help.elements[i]=obj.elements[i];
    help.capacity=obj.capacity;
	int ccount=0;
	for (int i = 0; i < tmp.capacity; i++)
        for (int j=0;j<help.capacity;j++)
		if (tmp.elements[i]==help.elements[j]){
            result.elements[ccount++]=tmp.elements[i];
            result.capacity++;
            help.elements[j]='/0';
            break;
		}
    sort(result.elements,result.elements+result.capacity);
    result.elements[ccount]='/0';
	return result;
}

Multi_Set Multi_Set::operator*= ( Multi_Set obj) {
    Multi_Set help;
	for (int i=0;i<obj.capacity;i++)
        help.elements[i]=obj.elements[i];
    help.capacity=obj.capacity;
    int ccount;
	for (int i = 0; i < help.capacity; i++){
        if (this->elements[0]=='/0')
            break;
        bool flag=false;
        for (int j=0;j<this->capacity;j++)
            if (this->elements[j]==help.elements[i]){
                for ( ccount=j;ccount<this->capacity;ccount++)
                    this->elements[ccount]=this->elements[ccount+1];
            this->elements[ccount]='/0';
            this->capacity--;
                break;
        }

	}
    sort(this->elements,this->elements+this->capacity);
	return (*this);
}

// Adding and remove
Multi_Set& Multi_Set::operator<< (const char c) {

	this->elements[(this->capacity)] = c;
	this->capacity++;
	sort(this->elements,this->elements+this->capacity);
	return (*this);
}

Multi_Set& Multi_Set::operator>> ( const char c) {
    bool issuch=false;
	for (int i=0;i<(this->capacity);i++)
        if (this->elements[i]==c){
            int ccount=i;
            for (;ccount<this->capacity-1;ccount++)
                this->elements[ccount]=this->elements[ccount+1];
            this->capacity--;
            issuch=true;
            break;
        }
        if (!issuch)
            cout<<"No such element"<<endl;
	return (*this);
}
