# Robust Journal System

**Robust Journal System** is a locally run, privacy-focused journaling application designed for secure offline usage.  
It implements an **XOR encryption algorithm** to protect both text entries and images, keeping sensitive data fully offline while maintaining functional code locally.  

There’s also some bonus C/C++ code included — mostly me experimenting with lower-level implementations, but it’s pretty cool if you’re interested in how the system logic works under the hood.

---

## System Overview
- Uses **XOR encryption** for all stored text and image data  
- Stores **encrypted data and keys on a USB drive** for added physical security  
- Keeps **functional code on the local machine**, isolating the logic from the data  
- Designed for **local, offline journaling** without dependency on external servers  

---

## Setup (C++ Version)

Recreating this setup can be a bit tedious since it was originally configured for my own system, but here’s a general outline:

1. **Create the file architecture:**
   - A USB drive should contain:
     - The XOR key  
     - Encrypted text and image files  
     - Pad text file  
   - The main program runs locally, referencing paths on the USB.

2. **Configure file paths:**
   - In the `.cpp` file, replace all instances of `"REPLACE HERE"` with your actual file paths.

3. **Set a password:**
   - Choose a password and update it in the relevant section of the C++ source code.

---

## Notes
This project was primarily built as an experiment in **local encryption, data security, and system architecture**.  
While not built for mass use, it demonstrates how **encryption principles and physical data separation** can combine to create a secure journaling system.

---

## Future Improvements
- Migrate XOR to AES or hybrid encryption  
- Add a minimal GUI for easier use  
- Implement multi-user support and recovery options
