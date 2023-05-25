<h1>PriorityQueue</h1>

<p>
The PriorityQueue is a C++ implementation of a priority queue based on a linked list. It allows elements to be stored and retrieved based on their priority. The priority is determined using a user-defined comparison function.
</p>

<h2>Motivation</h2>

<p>
The exercise's goal is to learn how to implement template classes, functors, and functions in C++.
</p>

<h2>Features</h2>

<ul>
  <li>Insert elements into the priority queue while maintaining their order based on priority.</li>
  <li>Retrieve the element with the highest priority from the priority queue.</li>
  <li>Exception handling for an empty priority queue.</li>
</ul>

<h2>Customizing Priority Comparison</h2>

<p>
By default, the priority comparison is performed using the <code>MyComparator</code> struct, which subtracts the second element from the first element. However, you can customize the comparison logic by providing your own comparison function or functor. Simply modify the <code>MyComparator</code> struct or provide your own comparison struct and pass it as a template argument to the <code>PriorityQueue</code> class.
</p>

<h2>Error Handling</h2>

<p>
If the priority queue is empty and you try to retrieve an element using <code>poll</code>, a <code>std::runtime_error</code> exception will be thrown. Make sure to handle this exception appropriately in your code.
</p>
