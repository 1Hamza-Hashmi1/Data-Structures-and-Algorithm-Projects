Hamza Hashmi, 501093570, 7/10/23

Question:
Another legal XML tag not used in this lab is the "stand-alone" tag. This kind of tag combines both a start-tag and end-tag in one. It is identified with a '/'(slash) preceding the final >. (For example, the <foo/> is a stand-alone tag
that is "self balancing". Describe briefly how you would modify Requirement 1 to allow this kind of tag.

Answer:
After pushing the identity of the tag onto the stack, there would be an extra if-statement that will check for a "/" character. If the character is found the identity will be popped off the stack.
