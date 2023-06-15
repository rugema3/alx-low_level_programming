<h1> 0x17. C - Doubly linked lists </h1>

<h2> Tasks</h2>
<h3>0. Print list</h3>
Write a function that prints all the elements of a dlistint_t list.
<ul>
  <li>Prototype: size_t print_dlistint(const dlistint_t *h);</li>
  <li>Return: the number of nodes</li>
</ul>

<h3>1. List length </h3>
Write a function that returns the number of elements in a linked dlistint_t list.
<ul>
  <li>Prototype: size_t dlistint_len(const dlistint_t *h);</li>
</ul>
<h3>2. Add node</h3>
Write a function that adds a new node at the beginning of a dlistint_t list.
<ul>
  <li>Prototype: dlistint_t *add_dnodeint(dlistint_t **head, const int n);</li>
  <li>Return: the address of the new element, or NULL if it failed</li>
</ul>
<h3>3. Add node at the end</h3>
mandatory
Write a function that adds a new node at the end of a dlistint_t list.
<ul>
  <li>Prototype: dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);</li>
  <li>Return: the address of the new element, or NULL if it failed </li>
</ul>
  
<h3><b>4. Free list</b></h3>
<b>mandatory</b>
<b>Write a function that frees a dlistint_t list.</b>
<ul>
<li>Prototype: void free_dlistint(dlistint_t *head);</li>
</ul>
  <h3><b>5. Get node at index </b></h3>
<b>mandatory</b>
Write a function that returns the nth node of a dlistint_t linked list.
<ul>
<li>Prototype: dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);</li>
<li>where index is the index of the node, starting from 0</li>
<li>if the node does not exist, return NULL</li>
</ul>

<h3>6. Sum list</h3>
<b>mandatory </b>
Write a function that returns the sum of all the data (n) of a dlistint_t linked list.
<ul>
<li>Prototype: int sum_dlistint(dlistint_t *head); </li>
<li>if the list is empty, return 0</li>
</ul>

<h3><b>7. Insert at index</b></h3>
<b>mandatory</b>
Write a function that inserts a new node at a given position.
<ul>
<li>Prototype: dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);</li>
<li>where idx is the index of the list where the new node should be added. Index starts at 0 </li>
<li>Returns: the address of the new node, or NULL if it failed</li>
<li>if it is not possible to add the new node at index idx, do not add the new node and return NULL</li>
<li>Your files 2-add_dnodeint.c and 3-add_dnodeint_end.c will be compiled during the correction</li>
</ul>

<h3><b>8. Delete at index</b></h3>
<b>mandatory</b>
Write a function that deletes the node at index index of a dlistint_t linked list.
<ul>
<li>Prototype: int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);</li>
<li>where index is the index of the node that should be deleted. Index starts at 0</li>
<li>Returns: 1 if it succeeded, -1 if it failed</li>
</ul>

<h3><b>9. Crackme4</b></h3>
<b>#advanced</b>
Find the password for [crackme4](https://github.com/alx-tools/0x17.c)
<ul>
<li>Save the password in the file 100-password </li>
<li>Your file should contain the exact password, no new line, no extra space</li>
<li>Hint: The program prints “OK” when the password is correct</li>
</ul>

<h3><b>10. Palindromes</b></h3>
<b>#advanced</b>
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
<ul>
<li>Find the largest palindrome made from the product of two 3-digit numbers.</li>
<li>Save the result in the file 102-result</li>
<li>Your file should contain the exact result, no new line, no extra space</li>
</ul>
<h3><b>11. crackme5 </b></h3>
<b>#advanced</b>
Write a keygen for [crackme5](https://github.com/alx-tools/0x17.c)
<ul>
<li>Usage of the crackme: ./crackme5 username key </li>
<li>The crackme will segfault if you do not enter the correct key for the user</li>
<li>Usage for your keygen: ./keygen5 username </li>
<li>Your keygen should print a valid key for the username</li>
</ul>

