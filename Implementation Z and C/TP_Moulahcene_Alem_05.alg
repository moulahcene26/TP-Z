/*
 _____ ____ ____       _    _     ____  ____  ____  
|_   _|  _ \___ \     / \  | |   / ___||  _ \|  _ \ 
  | | | |_) |__) |   / _ \ | |   \___ \| | | | | | |
  | | |  __// __/   / ___ \| |___ ___) | |_| | |_| |
  |_| |_|  |_____| /_/   \_\_____|____/|____/|____/  
 */






SOIT

    BST0 UN ARB DE CHAINE;              /* normal bst (to compare) */
    BST1 UN ARB DE CHAINE;
    BST2 UN ARB DE CHAINE;
    BST3 UN ARB DE CHAINE;


    gen_words UNE ACTION;                /* generate the file  */
    make_bsts UNE ACTION;                /* inserting the wors into bsts with the different methods */
    show_bst UNE ACTION;                 /* display bst inorder traversal */
    add_node UNE ACTION;                 /* insert a node (word) into a bst */
    move_to_root UNE ACTION;             /* rotates the inserted node to root */
    move_to_middle UNE ACTION;           /* rotates the inserted node to middle of path */
    range_find UNE ACTION;               /* searches for words in a range in a specific bst */
    range_on_custom_bsts UNE ACTION;      /* performs range search across the custom bsts */
    find_word UNE FONCTION (ARB DE CHAINE) ; /* searches for a word in a specific bst */
    find_in_bst UNE FONCTION (ARB DE CHAINE); /* searches for a word in the three bsts */
    rot_right UNE ACTION;                /* performs right rotation operation */
    rot_left UNE ACTION;                 /* performs left rotation operation */
    Choix UN ENTIER;
    search_word, Mot1, Mot2 DES CHAINE; /* search word and range borders */
    search_result UN ARB DE CHAINE;        /* result node from search */
    serach_result_list UNE LISTE DE CHAINES;    /* list to store range search results */

DEBUT
    /* */
    BST0 := NIL;
    BST1 := NIL;
    BST2 := NIL;
    BST3 := NIL;


    APPEL gen_words; /* generate the file  */
    APPEL make_bsts; /* inserting the wors into bsts with the different methods */


    Choix := -1;
    TQ Choix <> 10
        ECRIRE('');
        ECRIRE('========== MAIN MENU ==========');
        ECRIRE('1 - Display BST1 (rotate to root on ''Y''/''Z''/''a'')');
        ECRIRE('2 - Display BST2 (rotate to middle on ''Y''/''Z''/''a'')');
        ECRIRE('3 - Display BST3 (rotate to root on non-''Y''/''Z''/''a'')');
        ECRIRE('4 - Search for a single word'); /*it crashes for some reason(but works fine in c)*/
        ECRIRE('5 - Search for a word range [Word1, Word2] in Custom BSTs');
        ECRIRE('6 - Exit');
        ECRIRE('small note: if the word doesnt exist, the z code crashes, but it says not found normally in c code')  ;
        ECRIRE('Enter your choice: ');
        LIRE(Choix);


        SI Choix = 1
            ECRIRE('BST1 (inorder traversal):');
            APPEL show_bst(BST1);
        SINON SI Choix = 2
            ECRIRE('BST2 (inorder traversal):');
            APPEL show_bst(BST2);
        SINON SI Choix = 3
            ECRIRE('BST3 (inorder traversal):');
            APPEL show_bst(BST3);
        SINON SI Choix = 4
            ECRIRE('Enter a word to search: ');
            LIRE(search_word);
            search_result := find_word(search_word);
            SI search_result <> NIL
                ECRIRE('Word found: ', INFO(search_result));
            SINON
                ECRIRE('Word not found.');
            FSI;
        SINON SI Choix = 5
            ECRIRE('Enter the lower bound (Word1): ');
            LIRE(Mot1);
            ECRIRE('Enter the upper bound (Word2): ');
            LIRE(Mot2);
            serach_result_list := NIL;
            APPEL range_on_custom_bsts(Mot1, Mot2, serach_result_list);
            ECRIRE('Words in range [', Mot1, ', ', Mot2, ']:');
            TQ serach_result_list <> NIL
                ECRIRE(VALEUR(serach_result_list));
                serach_result_list := SUIVANT(serach_result_list);
            FTQ;

        SINON SI Choix = 6
            ECRIRE('Exiting program.');
        SINON
            ECRIRE('Invalid choice. Please try again.');
        FSI;
        FSI;
        FSI;
        FSI;
        FSI;
        FSI;
    FTQ;
FIN


/* -------------------------------------------------- */
/* function to generate random words for testing */
ACTION gen_words
SOIENT
    F UN FICHIER DE (CHAINES, chaine) BUFFER S ;
    I : ENTIER ;
DEBUT
    OUVRIR ( F , 'F2.z' , 'N' ) ;
    POUR I := 1 , 101
        init_struct(S, [ALEACHAINE ( 5 ) , ALEACHAINE ( 5 )]);
        ECRIRESEQ ( F , S )
    FPOUR ;
    FERMER ( F ) ;
    ECRIRE('File F2.z created with 100 words (as structures).');
FIN

/* -------------------------------------------------- */
/* function to build all bsts from the file */
ACTION make_bsts
SOIENT
    F UN FICHIER DE (CHAINES, chaine) BUFFER S;
    C UN CAR;                           /* first character of the word */
    CurrentWord UNE CHAINE;             /* current word being processed */
    spec_char_Y, spec_char_Z, spec_char_a UN CAR;
DEBUT
    spec_char_Y := 'Y';
    spec_char_Z := 'Z';
    spec_char_a := 'a';

    OUVRIR(F, 'F2.z', 'A');
    TQ NON FINFICH(F)
        LIRESEQ(F, S);                  /* read next structure */
        CurrentWord := struct(S, 1);    /* use the first string in the structure */

        SI LONGCHAINE(CurrentWord) > 0  /* check that word is not empty */
            C := CARACT(CurrentWord, 1); /* get first character */


            APPEL add_node(BST0, CurrentWord, 0); /* insert into bst0 (for commparision) with no rotation */

            /* decide which bst to use based on first character ('y', 'z', 'a') */
            SI ((C = spec_char_Y) OU (C = spec_char_Z) OU (C = spec_char_a))
                APPEL add_node(BST1, CurrentWord, 1); /* bst1: y/z/a words, root rotation */
                APPEL add_node(BST2, CurrentWord, 2); /* bst2: y/z/a words, middle rotation */
            SINON
                APPEL add_node(BST3, CurrentWord, 1); /* bst3: other words, root rotation */
            FSI
        FSI
    FTQ;
    FERMER(F);
FIN

/* -------------------------------------------------- */
/* function to insert a word into a bst with different methods */
ACTION add_node (UnArbre, Mot, Mode)
SOIENT
    UnArbre UN ARB DE CHAINE;       /* tree to insert into*/
    Mot UNE CHAINE;                     /* word to insert */
    Mode UN ENTIER;                     /* 0=no rotation, 1=root rotation, 2=middle rotation */
    left_child_temp, right_child_temp UN ARB DE CHAINE;
DEBUT
    SI UnArbre = NIL
        CREERNOEUD(UnArbre);
        AFF_INFO(UnArbre, Mot);
        AFF_FG(UnArbre, NIL);
        AFF_FD(UnArbre, NIL);
    SINON
        SI Mot < INFO(UnArbre)
            left_child_temp := FG(UnArbre); /* get left child */
            APPEL add_node(left_child_temp, Mot, Mode); /* recursive call to insert in left subtree */
            AFF_FG(UnArbre, left_child_temp); /* update left child */
        SINON SI Mot > INFO(UnArbre)
            right_child_temp := FD(UnArbre); /* get right child */
            APPEL add_node(right_child_temp, Mot, Mode); /* recursive call to insert in right subtree */
            AFF_FD(UnArbre, right_child_temp); /* update right child */
        FSI
    FSI;


    /* after insertion, rotate the node to root or middle of path */
    SI (UnArbre <> NIL) ET (INFO(UnArbre) = Mot) /* only rotate if the node is the one we just inserted */
        SI Mode = 1                     /* mode 1: rotate to root */
            APPEL move_to_root(UnArbre, Mot); /* bring the node to root */
        SINON SI Mode = 2               /* mode 2: rotate to middle of path */
            APPEL move_to_middle(UnArbre, Mot); /* bring the node to the middle */
        FSI;
    FSI;
    FSI
    FSI
FIN


/* -------------------------------------------------- */
/* function to display a bst inorder */
ACTION show_bst (UnArbre)
SOIENT
    UnArbre UN ARB DE CHAINE;
DEBUT
    SI UnArbre <> NIL
        APPEL show_bst(FG(UnArbre));
        ECRIRE(INFO(UnArbre));
        APPEL show_bst(FD(UnArbre));
    FSI
FIN

/* -------------------------------------------------- */
/* function to perform left rotation */
ACTION rot_left(node_to_rotate)
SOIENT
    node_to_rotate UN ARB DE CHAINE;  /* node to rotate */
    temp_node UN ARB DE CHAINE;            /* temporary node for rotation */
DEBUT
    SI ((node_to_rotate <> NIL) ET (FD(node_to_rotate) <> NIL)) /* check if right child exists */
        temp_node := FD(node_to_rotate); /* get right child */
        AFF_FD(node_to_rotate, FG(temp_node)); /* update left child of right child */
        AFF_FG(temp_node, node_to_rotate); /* set the current node as left child of right child */
        node_to_rotate := temp_node;     /* update root of this subtree */
    FSI
FIN

/* -------------------------------------------------- */
/* function to perform right rotation */
ACTION rot_right(node_to_rotate)
SOIENT
    node_to_rotate UN ARB DE CHAINE;  /* node to rotate  */
    temp_node UN ARB DE CHAINE;            /* temporary node for rotation */
DEBUT
    SI ((node_to_rotate <> NIL) ET (FG(node_to_rotate) <> NIL)) /* check if left child exists */
        temp_node := FG(node_to_rotate); /* get left child */
        AFF_FG(node_to_rotate, FD(temp_node));  /* update right child of left child */
        AFF_FD(temp_node, node_to_rotate); /* set the current node as right child of left child */
        node_to_rotate := temp_node;     /* update root of this subtree */
    FSI
FIN


/* -------------------------------------------------- */
/* move to root */
ACTION move_to_root(Tree, mot)
SOIENT
    Tree UN ARB DE CHAINE;    /* tree to change */
    mot UNE CHAINE;           /* target word */
    child_node UN ARB DE CHAINE;
DEBUT
    SI Tree <> NIL : /* check if tree is not empty */
        SI INFO(Tree) <> mot : /* check if current node is not the target */
            SI mot < INFO(Tree) /* target in left subtree */
                child_node := FG(Tree); /* get left child */
                SI child_node <> NIL  /* check if left child exists */
                    APPEL move_to_root(child_node, mot);  /* recursive call to move to root */
                    AFF_FG(Tree, child_node); /* relink */
                    SI INFO(FG(Tree)) = mot /* check if child became target */
                        APPEL rot_right(Tree); /* Tree is roatted */
                    FSI;
                FSI;
            SINON SI mot > INFO(Tree) /* target in right subtree */
                child_node := FD(Tree); /* get right child */
                SI child_node <> NIL /* check if right child exists */
                    APPEL move_to_root(child_node, mot); /* recursive call to move to root */
                    AFF_FD(Tree, child_node); /* relink */
                    SI INFO(FD(Tree)) = mot /* check if child became target */
                        APPEL rot_left(Tree);  /* Tree is rotated */
                    FSI;
                FSI;
            FSI;
        FSI;
    FSI;
     FSI
FIN

/* -------------------------------------------------- */

ACTION move_to_middle(Tree, mot)
SOIENT
    Tree UN ARB DE CHAINE;
    mot UNE CHAINE;
    child_node, grand_child_node UN ARB DE CHAINE;
DEBUT
    SI (Tree <> NIL) ET (INFO(Tree) <> mot) /* check if tree is not empty and current node is not the target */
        SI mot < INFO(Tree) /* target in left subtree */
            child_node := FG(Tree); /* get left child */
            SI child_node <> NIL : /* check if left child exists */
                SI INFO(child_node) = mot /* target is left child */
                    APPEL rot_right(Tree); /* Tree becomes child_node */
                SINON SI mot < INFO(child_node) /* target is left-left grandchild */
                    grand_child_node := FG(child_node); /* get left child of child */
                    SI (grand_child_node <> NIL) ET (INFO(grand_child_node) = mot)
                        APPEL rot_right(child_node); /* rotate child with grandchild */
                        AFF_FG(Tree, child_node); /* relink new child */
                        APPEL rot_right(Tree); /* rotate root with new child */
                    FSI;
                SINON SI mot > INFO(child_node) /* target is left-right grandchild */
                    grand_child_node := FD(child_node); /* get right child of child */
                    SI (grand_child_node <> NIL )ET (INFO(grand_child_node) = mot )
                        APPEL rot_left(child_node); /* rotate child with grandchild */
                        AFF_FG(Tree, child_node); /* relink new child */
                        APPEL rot_right(Tree); /* rotate root with new child */
                    FSI;
                FSI;
            FSI;
FSI
        SINON SI mot > INFO(Tree) /* target in right subtree */
            child_node := FD(Tree);
            SI child_node <> NIL :
                SI INFO(child_node) = mot /* target is right child */
                    APPEL rot_left(Tree); /* Tree becomes child_node */
                SINON SI mot > INFO(child_node) /* target is right-right grandchild */
                    grand_child_node := FD(child_node);
                    SI (grand_child_node <> NIL) ET (INFO(grand_child_node) = mot)
                        APPEL rot_left(child_node);
                        AFF_FD(Tree, child_node);
                        APPEL rot_left(Tree);
                    FSI;
                SINON SI mot < INFO(child_node) /* target is right-left grandchild */
                    grand_child_node := FG(child_node);
                    SI (grand_child_node <> NIL) ET (INFO(grand_child_node) = mot)
                        APPEL rot_right(child_node);
                        AFF_FD(Tree, child_node);
                        APPEL rot_left(Tree);
                    FSI;
                FSI;
            FSI;
        FSI;
    FSI;
    FSI ;
    FSI ;
    FSI ;
    FSI ;

FIN

/* -------------------------------------------------- */
/* function to search for a word in a given bst */
FONCTION find_in_bst(Tree, searched_word) : ARB DE CHAINE
SOIENT
    Tree UN ARB DE CHAINE;              /* tree to search in */
    searched_word UNE CHAINE;              /* word to find */
    current_node UN ARB DE CHAINE;       /* current node being examined */
DEBUT
    current_node := Tree; /* start from the root of the tree */
    TQ (current_node <> NIL) ET (INFO(current_node) <> searched_word) /* loop until found or end of tree */
        SI searched_word < INFO(current_node) /* search in left subtree */
            current_node := FG(current_node); /* move to left child */
        SINON
            current_node := FD(current_node); /* search in right subtree */
        FSI;
    FTQ;
    find_in_bst := current_node; /* return the found node  */
FIN

/* -------------------------------------------------- */
/* function to search for a word using the custom BSTS */
FONCTION find_word(WordS) : ARB DE CHAINE
SOIENT
    WordS UNE CHAINE;                  /* word to search for */
    first_char UN CAR;                  /* first character of the word */
    found_node UN ARB DE CHAINE;        /* node found by search */
    spec_char_Y, spec_char_Z, spec_char_a UN CAR;
DEBUT
    found_node := NIL;
    spec_char_Y := 'Y'; spec_char_Z := 'Z'; spec_char_a := 'a';

    SI LONGCHAINE(WordS) > 0 :
        first_char := CARACT(WordS, 1); /* get first character of the word */
        SI ((first_char = spec_char_Y) OU (first_char = spec_char_Z) OU (first_char = spec_char_a) )
            found_node := find_in_bst(BST1, WordS); /* search in bst1 (y,z,a words) */
        SINON SI ((first_char > spec_char_Y) OU (first_char > spec_char_Z) OU (first_char > spec_char_a))
            found_node := find_in_bst(BST2, WordS); /* bst2 */
        SINON
            found_node := find_in_bst(BST3, WordS); /* bst3  */
        FSI;
        FSI ;
    SINON
        ECRIRE('Word is empty.');
    FSI;
    find_word := found_node; /* return the found node */
FIN

/* -------------------------------------------------- */
/* action to search for words in a range in a given bst */
ACTION range_find(Node, W1, W2, result_list)
SOIENT
    Node UN ARB DE CHAINE;             /* current node being examined */
    W1, W2 UNE CHAINE;                 /* lower and upper bounds */
    result_list UNE LISTE DE CHAINE; /* list to store results (passed by reference) */
    temp_node UN LISTE DE CHAINE;         /* temporary node for list */
    temp_list UN LISTE DE CHAINE; /* temporary list for traversal */
DEBUT
    SI Node <> NIL
        SI INFO(Node) >= W1
            APPEL range_find(FG(Node), W1, W2, result_list); /* search in left subtree */
        FSI ;

        SI ((INFO(Node) >= W1) ET (INFO(Node) <= W2)) /* if node is in range */
            ALLOUER(temp_node); /* allocate memory for new node */
            AFF_VAL(temp_node, INFO(Node)); /* store the value */
            AFF_ADR(temp_node, NIL);

            SI result_list = NIL
                result_list := temp_node;
            SINON
                temp_list := result_list; /* start from the head of the list */
                TQ SUIVANT(temp_list) <> NIL /* traverse to the end of the list */
                    temp_list := SUIVANT(temp_list);
                FTQ;
                AFF_ADR(temp_list, temp_node); /* link the new node to the end of the list */
            FSI;
        FSI;

        SI INFO(Node) <= W2 /* if node is less than or equal to upper bound */
            APPEL range_find(FD(Node), W1, W2, result_list); /* search in right subtree */
       FSI
    FSI;
FIN

/* -------------------------------------------------- */
/* action to perform range search across custom bsts */
ACTION range_on_custom_bsts(W1, W2, combined_results)
SOIENT
    W1, W2 UNE CHAINE;                /* lower and upper bounds */
    combined_results UNE LISTE DE CHAINE; /* combined result list*/
    temp_list_bst1_bst2, temp_list_bst3 UN LISTE DE CHAINE; /* temp result lists */
    temp_list_trav, new_node, temp_list_end UN LISTE DE CHAINE;
DEBUT
    combined_results := NIL;
    temp_list_bst1_bst2 := NIL;
    temp_list_bst3 := NIL;


    APPEL range_find(BST1, W1, W2, temp_list_bst1_bst2); /* words from bst1 */
    APPEL range_find(BST3, W1, W2, temp_list_bst3);     /* words from bst3 */

    /* combine results from temp_list_bst1_bst2 */
    temp_list_trav := temp_list_bst1_bst2; /* traverse the list */
    temp_list_end := NIL;

    TQ temp_list_trav <> NIL /* traverse the list */
        ALLOUER(new_node);
        AFF_VAL(new_node, VALEUR(temp_list_trav));
        AFF_ADR(new_node, NIL);
        SI combined_results = NIL /* if combined_results is empty */
            combined_results := new_node; /* set it to the new node */
            temp_list_end := combined_results;  /* make it the end of the list */
        SINON
            AFF_ADR(temp_list_end, new_node); /* link the new node to the end of the list */
            temp_list_end := SUIVANT(temp_list_end); /* update the end of the list */
        FSI;
        temp_list_trav := SUIVANT(temp_list_trav);/* move to the next node */
    FTQ;


    temp_list_trav := temp_list_bst3; /* combine results from temp_list_bst3 */


    TQ temp_list_trav <> NIL
        ALLOUER(new_node);
        AFF_VAL(new_node, VALEUR(temp_list_trav));
        AFF_ADR(new_node, NIL);
        SI combined_results = NIL /* covers case where bst1/2 had no results in range */
            combined_results := new_node;
            temp_list_end := combined_results;
        SINON
            AFF_ADR(temp_list_end, new_node);
            temp_list_end := SUIVANT(temp_list_end);
        FSI;
        temp_list_trav := SUIVANT(temp_list_trav); /*same as above */
    FTQ;

FIN

/* -------------------------------------------------- */