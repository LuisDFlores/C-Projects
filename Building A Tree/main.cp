#include <fstream>
#include <iostream>
#include "bt.h"
#include "st.h"
#include "avl.h"
const int seed = 373;

int main()
{
	srand(seed);
	std::ofstream output("output.txt");

	int random;
	BTree binaryTree;
	STree searchTree;
	AVLTree avlTree;
	// BHTree heapTree;

	//filling the Binary Tree with 100 random numbers  
    for (int i = 1; i <= 100; i++)
    {
         random = rand() % 100 + 1;
         binaryTree.insert(random);
    }

    output << "Binary Tree Demo" << std::endl;
    output << "----------------------------------------------------------------";

    output << std::endl;
    output << "Balance state: ";

    if (binaryTree.checkBal() == true)
    	output << "true";
    else
    	output << "false";

    output << std::endl << "Tree size:     " << binaryTree.getSize();
      
    output << std::endl <<std::endl;
    output << "PreOrder" << std::endl;
    binaryTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    binaryTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    binaryTree.postOrder(output);

    for (int i = 1; i <= 50; i++)
    	binaryTree.rmRoot();

    output << std::endl << std::endl << "After deletion ------------------------------------------------";

    output << std::endl <<std::endl;
    output << "PreOrder" << std::endl;
    binaryTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    binaryTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    binaryTree.postOrder(output);
    output << std::endl << std::endl << " searching 8: ";
    binaryTree.search(output, 8);
    

    for (int i = 1; i <= 100; i++)
    {
    	random = rand() % 100 + 1;
    	searchTree.insert(random);
    }

    output << std::endl << std::endl << std::endl << "Search Tree Demo" << std::endl;
    output << "----------------------------------------------------------------";

    output << std::endl;

    output << std::endl << "Tree size:     " << searchTree.getNodes();
    output << std::endl << std::endl;
    output << "PreOrder" << std::endl;
    searchTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    searchTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    searchTree.postOrder(output);

    for (int i = 1; i <= 100; i++)
    {
    	random = rand() % 100 + 1;
    	avlTree.insert(random);
    }

    output << std::endl << std::endl << std::endl << "AVL Tree Demo" << std::endl;
    output << "----------------------------------------------------------------";

    output << std::endl;
    output << "Balance state: ";
     if (avlTree.getBal() == true)
    	output << "true";
    else
    	output << "false";

    output << std::endl << "Tree size:     " << avlTree.size();

    output << std::endl << std::endl;
    output << "PreOrder" << std::endl;
    avlTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    avlTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    avlTree.postOrder(output);

    for (int i = 1; i <= 50; i++)
    	avlTree.rmRoot();

    output << std::endl << std::endl << "After deletion ------------------------------------------------";

    output << std::endl << std::endl;
    output << "PreOrder" << std::endl;
    avlTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    avlTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    avlTree.postOrder(output);


//filling the Heap Tree with 100 random numbers  
   
   /*
    int arr[100];
    for(int i=0; i<100; i++)
    {
   	   arr[i] = rand() % 100 + 1;
	   random = arr[i];
	   heapTree.insert(random);
	    
    }
    
	int n = sizeof(arr)/sizeof(arr[0]);

    output << "Heap Tree Demo" << std::endl;
    output << "----------------------------------------------------------------";

    output << std::endl;
    output << "Balance state: ";

    if (heapTree.checkBal() == true)
    	output << "true";
    else
    	output << "false";

    output << std::endl << "Tree size:     " << heapTree.getSize();
      
    output << std::endl <<std::endl;
    output << "PreOrder" << std::endl;
    heapTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    heapTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    heapTree.postOrder(output);	
    output << "Max Heap Print: " << std::endl;
    heapTree.heapSortMax(arr, n);
    heapTree.printMaxheap(output, arr, n);
    output << std::endl << std::endl;
    output << "Min Heap Print: " << std::endl;
    heapTree.heapSort(arr,n);
    heapTree.printminheap(output, arr, n);

	

    for (int i = 1; i <= 50; i++)
    	heapTree.rmRoot();

    output << std::endl << std::endl << "After deletion ------------------------------------------------";

    output << std::endl <<std::endl;
    output << "PreOrder" << std::endl;
    heapTree.preOrder(output);
    output << std::endl << std::endl;
    output << "InOrder" << std::endl;
    heapTree.inOrder(output);
    output << std::endl << std::endl;
    output << "PostOrder" << std::endl;
    heapTree.postOrder(output);
    output << "Max Heap Print: " << std::endl;
    //function to heapsort
    heapTree.heap_sort();
    heapTree.printMaxheap();
    output << std::endl << std::endl;
    //sorting Tree
    heapTree.heapSort();
    output << "Min Heap Print: " << std::endl;
    heapTree.printminheap();
    
    */

    int option = 0;
    int opt = 0;
    int userInput = 0;
    
    BTree userBT;
    STree userST;
    AVLTree userAVLT;
    // BHTree userBHT;
    
    
    
    std::cout <<" __| |____________________________________________| |__                                                \n";
    std::cout <<"(__   ____________________________________________   __)                           //  ;              \n";
    std::cout <<"   | |_____(1) Use Binary Tree                    | |                             /'   |              \n";
    std::cout <<"   | |_____(2) Use Binary Search Tree             | |           .----..._    _../ |   \\               \n";
    std::cout <<"   | |_____(3) AVL Tree                           | |            \'---._ `.-'      `  .'              \n";
    std::cout <<"   | |_____(4) Use Tree with Heap Applications    | |             `.    '              `.             \n";
    std::cout <<"   | |_____(5)If professor, select when done      | |               :            _,.    '.            \n";
    std::cout <<"   | |                                            | |               |     ,_    (() '    |            \n";
    std::cout <<"   | |___________________________________________ | |__             ;   .'(().  '      _/__..-        \n";
    std::cout <<"(__   ____________________________________________   __)            \\ _ '       __  _.-'--._          \n";
    std::cout <<"     |                                            | |               ,'.'...____'::-'  \\     `'        \n";
    std::cout <<"                                                                   / |   /         .---.              \n";
    std::cout <<"       373 PROJECT 2 Friday 8am                              .-.  '  '  / ,---.   (     )             \n";
    std::cout <<"       By Luis, Sebastian, Avery, Janalry                   / /       ,' (     )---`-`-`-.._          \n";
    std::cout <<"                                                           : '       /  '-`-`-`..........--'\\         \n";
    std::cout <<"                                                           ' :      /  /                     '.       \n";
    std::cout <<"                                                           :  \\    |  .'         o             \\      \n";
    std::cout <<"                                                            \\  '  .' /          o       .       '     \n";
    std::cout <<"                                                             \\  `.|  :      ,    : _o--'.\\      |     \n";
    std::cout <<"                                                              `. /  '       ))    (   )  \\ >     |     \n";
    std::cout <<"                                                                ;   |      ((     \\ /    \\ ___  |     \n";
    std::cout <<"                                                                ;   |      _))      `'.-'. ,-'`  '    \n";
    std::cout <<"                                                                |    `.   ((`            |/    /      \n";
    std::cout <<"                                                                \\     ).  .))            '    .       \n";
    std::cout <<"                                                             ----`-'-'  `''.::.________:::mx'' ---    \n";
    std::cout <<"                                                                                                      \n";
    std::cout <<"                                                                                                      \n";
    
    std::cin.get();
    
    
    
    
    while (option != -1)
    {
        
        std::cout<<"Enter An Available Number to Perform an Action :" <<std::endl;
        std::cout<<"Type -1 to Quit from the program\n" <<std::endl;
        std::cin>>option;
        
        if(option == 1)
        {
            while(opt!=-1)
            {
                
                std::cout<<"           Using Binary Tree           "<<std::endl;
                std::cout<<"_____(1) Add Node "<<std::endl;
                std::cout<<"_____(2) Remove root "<<std::endl;
                std::cout<<"_____(3) Print Tree "<<std::endl;
                std::cout<<"Enter An Available Number to Perform an Action :" <<std::endl;
                std::cout<<"Type -1 to Quit from the program\n" <<std::endl;
                std::cin>>opt;
                
                if(opt == 1)
                {
                    std::cout<<"   Adding A Node was selected:   "<<std::endl;
                    std::cout<<"Enter a Value to Add to Tree"<<std::endl;
                    std::cin>>userInput;
                    
                    //function to add a node to Binary Tree
                    userBT.insert(userInput);
                }
                if(opt == 2)
                {
                    std::cout<<"   Removing root was selected:   "<<std::endl;
                    
                    //function to remove a node to Binary Tree
                    userBT.rmRoot();
                    
                }
                
                if(opt == 3)
                {
                    
                    std::cout<<"   Print Tree was selected: Printing PostOrder  "<<std::endl;
                    std::cout<<""<<std::endl;
                    
                    //function to Print Tree post Order
                    userBT.postOrder(output);
                    
                }
                
                if(opt ==-1)
                {
                    std::cout<<"Thank you for using This menu"<<std::endl;
                    option = opt;
                    
                }
               
            }
            
        }
        
        
        if(option == 2)

        {
            while(opt!=-1)
            {
                std::cout<<"           Using Binary Search Tree           "<<std::endl;
                std::cout<<"_____(1) Add Node "<<std::endl;
                std::cout<<"_____(2) Remove Root "<<std::endl;
                std::cout<<"_____(3) Print Tree "<<std::endl;
                std::cout<<"Enter An Available Number to Perform an Action :" <<std::endl;
                std::cout<<"Type -1 to Quit from the program\n" <<std::endl;
                std::cin>>opt;

                if(opt == 1)
                {
                    std::cout<<"   Adding A Node was selected:   "<<std::endl;
                    std::cout<<"Enter a Value to Add to Tree"<<std::endl;
                    std::cin>>userInput;

                    //function to add a node to Binary Search Tree
                    userST.insert(userInput);
                }
                if(opt == 2)
                {
                    std::cout<<"   Removing root was selected:   "<<std::endl;

                    //function to remove root from Binary search Tree
                   //  userST.rmRoot();
                    
                }

                if(opt == 3)
                {

                    std::cout<<"   Print Tree was selected: Printing PreOrder  "<<std::endl;
                    std::cout<<""<<std::endl;
                    //function to Print Tree preOrder
                    userST.preOrder(output);
                    
                }

                if(opt ==-1)
                {
                    std::cout<<"Thank you for using This menu"<<std::endl;
                    option = opt;
                }
            }
        }



        if(option == 3)
        {
            while(opt!=-1)
            {
                std::cout<<"           Using AVL Tree           "<<std::endl;
                std::cout<<"_____(1) Add Node "<<std::endl;
                std::cout<<"_____(2) Remove Root "<<std::endl;
                std::cout<<"_____(3) Print Tree "<<std::endl;
                std::cout<<"Enter An Available Number to Perform an Action :" <<std::endl;
                std::cout<<"Type -1 to Quit from the program\n" <<std::endl;
                std::cin>>opt;

                if(opt == 1)
                {
                    std::cout<<"   Adding A Node was selected:   "<<std::endl;
                    std::cout<<"Enter a Value to Add to Tree"<<std::endl;
                    std::cin>>userInput;

                    //function to add a node to AVL Tree
                    userAVLT.insert(userInput);
                }
                if(opt == 2)
                {
                    std::cout<<"   Removing Root was selected:   "<<std::endl;
                    std::cout<<"Enter a Value remove from Tree"<<std::endl;
                    std::cin>>userInput;

                    //function to remove node from AVL Tree
                    // userAVLT.rmRoot(userInput);
                    

                }

                if(opt == 3)
                {

                    std::cout<<"   Print Tree was selected: Printing postOrder  "<<std::endl;
                    std::cout<<""<<std::endl;
                    //function to Print Tree postORDER
                    userAVLT.postOrder(output);
                }

                if(opt ==-1)
                {
                    std::cout<<"Thank you for using This menu"<<std::endl;
                     option = opt;
                }

            }

        }

        if(option == 4)
        {
        	std::cout << "This heap is commented out, but we tried very long and hard to make everything work." << std::endl;

        	/*

            while(opt!=-1)
            {

                std::cout<<"           Using Tree With Heap Applications         "<<std::endl;
                std::cout<<"_____(1) Add Node "<<std::endl;
                std::cout<<"_____(2) Remove Root "<<std::endl;
                std::cout<<"_____(3) Print Tree max "<<std::endl;
		std::cout<<"_____(4) Print Tree min "<<std::endl;
                std::cout<<"Enter An Available Number to Perform an Action :" <<std::endl;
                std::cout<<"Type -1 to Quit from the program\n" <<std::endl;
                std::cin>>opt;

                if(opt == 1)
                {
                    std::cout<<"   Adding A Node was selected:   "<<std::endl;
                    std::cout<<"Enter a Value to Add to Tree"<<std::endl;
                    std::cin>>userInput;

                    //function to add a node to Heap Tree
                    userBHT.insert(userInput);
                }
                if(opt == 2)
                {
                    std::cout<<"   Removing Root was selected:   "<<std::endl;
                    std::cout<<"Enter a Value remove from Tree"<<std::endl;
                    std::cin>>userInput;

                    //function to remove a node from Heap Tree
                    userBHT.rmRoot(userInput);

                }

                if(opt == 3)
                {

                    std::cout<<"   Print Tree max was selected: "<<std::endl;
                    std::cout<<""<<std::endl;
                    //function to Print Tree max
		    
                }
		    
		if(opt == 4)
                {

                    std::cout<<"   Print Tree min was selected: "<<std::endl;
                    std::cout<<""<<std::endl;
                    //function to Print Tree min
		    userBHT.printminheap();
		    
                }

                if(opt ==-1)
                {
                    std::cout<<"Thank you for using This menu"<<std::endl;
                     option = opt;
                }
            }

        } */

    	}

    if(option !=1&& option !=2 && option != 3 && option !=4 && option!=-1)
    {
        std::cout<<"Invalid Option: "<<std::endl;
    }
    
    if( option == -1)
        std::cout<<"If you want to use a different Option Restart Program";
    if(option ==5)
        std::cout<<"We tried hard, thank you for your lectures!!"<<std::endl;
    
    



    return 0;
    }
}