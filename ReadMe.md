# Basic System Call
Adding  a syscall (system call) in a table of already existing system calls, to copy one matrix into another.
<br>
<br>
## Adding a system call
Go to directory:- ```build/linux-5.xx.xx/arch/x86/entry/syscalls/syscall_64.tbl``` and add
<br>

    448 common kernel_2d_memcpy sys_kernel_2d_memcpy

Implement the same syscall in `sys.c` located at `build/linux-5.xx.xx/kernal/sys.c`

    SYSCALL_DEFINE4(kernel_2d_memcpy, float *, matrix1, float *, matrix2, int, row, int, column)

Here, 4 is the number of parameters (not including kernel_2d_memcpy) and by default first term is
the system call name.
<br>
<br>

## Functions used:
We use two functions copy_from_user and copy_to_user.

<br>

### Copy_from_user
We input a temporary matrix as our destination matrix and in our source we input the matrix 2. For bytes to copy we simply use sizeof(new Matrix(float)) function. If this does not return 0, then an error is returned.
    
    copy_from_user (destination address in kernel space, source address in user space,no. of bytes to copy)

<br>

### Copy_to_user
We input the matrix 1 where we need to provide the data and which is provided by making use of our temporary matrix. For bytes, we use sizeof()
function. If this does not return 0, then an error is thrown.

    copy_to_user (destination address in user space, source address in kernel space, no.
    of bytes to copy)

<br>

## Testing
After patching the patch file, recompile the kernel and then run the sample programme by typing

    gcc sample.c -o s
    ./s