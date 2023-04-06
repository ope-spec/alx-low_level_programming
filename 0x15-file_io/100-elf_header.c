#include "main.h"

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/***
 * check_elf - checks if a file is an ELF file by verifying that it starts with the correct magic number.
 * If it's not an ELF file, the program exits with an error code
 *
 * @e_indent - pointer to an array containing elf file content
 *
 * print_magic() prints the magic numbers of the ELF header in hexadecimal format.
 * print_class() prints the class of the ELF header (either ELF32 or ELF64).
 * print_data() prints the data of the ELF header (either little-endian or big-endian).
 * print_version() prints the version of the ELF header.
 * print_osabi() prints the OS/ABI of the ELF header.
 * print_abi() prints the ABI version of the ELF header.
 * print_type() prints the type of the ELF header (executable, shared object, etc.).
 *
 *
 * Return - displays the information contained in the ELF header at the start of an ELF file.
 *
 ***/
void check_elf(unsigned char *e_ident)
{
    int i;

    for (int i = 0; i <= 3; i++)
    {
        switch (e_ident[i])
        {
        case 127:
        case 'E':
        case 'L':
        case 'F':
            continue;
        default:
            fprintf(stderr, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/***
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array holding the ELF magic numbers.
 *
 * Description: Magic digits are separated by spaces.
***/
void print_magic(unsigned char *e_ident)
{
    int i;

    printf(" Magic:             ");

    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);
        if (i == EI_NIDENT - 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
}

/***
 * print_class - prints the ELF class
 * @e_ident: returns the ELF identification bytes
 * The EI_CLASS * byte of the ELF identification bytes, 
 * which is what this function outputs, 
 * specifies the ELF class.
 * 
***/
void print_class(unsigned char *e_ident)
{
    printf(" Class:              ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: 0x%x>\n", e_ident[EI_CLASS]);
    }
}

/***
 * print_data - prints the ELF data encoding
 * @e_ident: returns the ELF identification bytes
 * The EI_CLASS * byte of the ELF identification bytes, 
 * which is what this function outputs, 
 * specifies the ELF class.
***/
void print_data(unsigned char *e_ident)
{
    printf(" Data:                    ");

    unsigned char elf_data = e_ident[EI_DATA];
    if (elf_data == ELFDATANONE)
    {
        printf("none\n");
    }
    else if (elf_data == ELFDATA2LSB)
    {
        printf("2's complement, little endian\n");
    }
    else if (elf_data == ELFDATA2MSB)
    {
        printf("2's complement, big endian\n");
    }
    else
    {
        printf("<unknown: 0x%x>\n", elf_data);
    }
}

/***
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
***/
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d",
           e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/***
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
***/
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");

    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/***
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
***/
void print_abi(unsigned char *e_ident)
{
    printf("  ABI Version: %d\n", (int)e_ident[EI_ABIVERSION]);
}

/***
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
***/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("  Type:                              ");

    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

/***
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
***/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:              ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        // Swap bytes for big-endian data
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    // Use a conditional operator to print the address
    printf("%#lx\n", (e_ident[EI_CLASS] == ELFCLASS32) ? (unsigned int)e_entry : e_entry);
}

/***
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
***/
void close_elf(int elf_fd) 
{
    if (close(elf_fd) == -1) 
    {
        fprintf(stderr, "Error: Failed to close file descriptor %d\n", elf_fd);
        exit(EXIT_FAILURE);
    }
}


/***
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
***/
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        perror("read");
        close_elf(fd);
        exit(1);
    }

    check_elf(header.e_ident);
    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abi(header.e_ident);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close_elf(fd);
    return 0;
}


