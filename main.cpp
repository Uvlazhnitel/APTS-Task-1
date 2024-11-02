struct Node {
    int info;
    Node* next;
};

int SeqLen(Node* listHead1, Node* listHead2) {
    // Initialize pointers for traversing both lists
    Node* current1 = listHead1;
    Node* current2 = listHead2;
    
    // The sequence should start with 1
    int current_number = 1;
    
    // Check both lists are not empty and contain at least number 1
    bool has_one = false;
    
    // Check the first list for the presence of 1
    while (current1 != nullptr && current1->info >= current_number) {
        if (current1->info == 1) {
            has_one = true;
            break;
        }
        current1 = current1->next;
    }
    
    // Check the second list for the presence of 1
    while (current2 != nullptr && current2->info >= current_number) {
        if (current2->info == 1) {
            has_one = true;
            break;
        }
        current2 = current2->next;
    }
    
    // If neither list contains 1, return 0
    if (!has_one) {
        return 0;
    }
    
    // Reset the pointers to the head of the lists for the main traversal
    current1 = listHead1;
    current2 = listHead2;
    
    // Traverse both lists to find the longest contiguous sequence
    while (current1 != nullptr || current2 != nullptr) {
        // Find the next element in the merged sorted order
        int next_value;
        if (current1 != nullptr && (current2 == nullptr || current1->info > current2->info)) {
            next_value = current1->info;
            current1 = current1->next;
        } else {
            next_value = current2->info;
            current2 = current2->next;
        }
        
        // If the next value matches the current expected number in the sequence
        if (next_value == current_number) {
            // Increment the expected number to the next in the sequence
            current_number++;
        } else if (next_value < current_number) {
            // If the value is less than the expected number, skip it
            continue;
        } else {
            // If the value is greater than the expected number, the sequence is broken
            break;
        }
    }
    
    // Return the length of the contiguous sequence starting from 1
    return current_number - 1;
}
