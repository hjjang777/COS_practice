#include <cstdio>
#include <cstdlib>
#include <cstring>
#define BIT_VECTOR_LENGTH 8
#define MSB_INDEX BIT_VECTOR_LENGTH - 1
#define LSB_INDEX 0

void print_command(char *argv[]);
int check_validity(char *input);
void init_bit_vector(char *input, char *bv);
void print_bit_vector(char *bv);

int exp(int b, int e);
unsigned int b2u(char *bv);
int b2s(char *bv);
int b2o(char *bv);
int b2t(char *bv);

void bit_addition(char *bv1, char *bv2, char *result);
unsigned int unsigned_addition(char *bv1, char *bv2);
int twos_complement_addition(char *bv1, char *bv2);
int ones_complement_addition(char *bv1, char *bv2);
int sign_magnitude_addition(char *bv1, char *bv2);

int main(int argc, char *argv[])
{
    char bv1[BIT_VECTOR_LENGTH];
    char bv2[BIT_VECTOR_LENGTH];

    if (argc != 3)
    {
        printf("Error: invalid number of arguments\n");
        print_command(argv);
    }

    if (!(check_validity(argv[1]) && check_validity(argv[2])))
    {
        printf("Error: invalid arguments\n");
        print_command(argv);
    }

    init_bit_vector(argv[1], bv1);
    init_bit_vector(argv[2], bv2);
    print_bit_vector(bv1);
    printf(" - B2U: %u\n", b2u(bv1));
    printf(" - B2S: %d\n", b2s(bv1));
    printf(" - B2O: %d\n", b2o(bv1));
    printf(" - B2T: %d\n", b2t(bv1));
    print_bit_vector(bv2);
    printf(" - B2U: %u\n", b2u(bv2));
    printf(" - B2S: %d\n", b2s(bv2));
    printf(" - B2O: %d\n", b2o(bv2));
    printf(" - B2T: %d\n", b2t(bv2));

    printf("Addition >>>\n");
    printf(" - Unsigned addition: %u\n", unsigned_addition(bv1, bv2));
    printf(" - Sign magnitude addition: %d\n", sign_magnitude_addition(bv1, bv2));
    printf(" - Twos complement addition: %d\n", twos_complement_addition(bv1, bv2));
    printf(" - Ones complement addition: %d\n", ones_complement_addition(bv1, bv2));
    
    return 0;
}

void print_command(char *argv[])
{
    printf("Command: %s <first bit vector> <second bit vector>\n", argv[0]);
    printf("Example: %s 0110 1000\n", argv[0]);
    exit(1);
}

int check_validity(char *input)
{
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] != '0' && input[i] != '1')
        {
            return 0;
        }
    }
    if (strlen(input) != BIT_VECTOR_LENGTH)
    {
        return 0;
    }
    return 1;
}

void init_bit_vector(char *input, char *bv)
{
    char c;
    int i, len;
    len = strlen(input);
    for (i = 0; i < BIT_VECTOR_LENGTH; i++)
    {
        c=input[i];
        // if (c == '0')
        //     bv[MSB_INDEX-i] = 0;
        // else 
        //     bv[MSB_INDEX-i] = 1;
        bv[MSB_INDEX-i] = (c=='1');
        // bv[i] = input[len-i-1];
    }
}
void print_bit_vector(char *bv)
{
    int i;
    printf("Bit vector: ");
    // for (i = 0; i < BIT_VECTOR_LENGTH; i++)
    for (i=MSB_INDEX; i>=LSB_INDEX; i--)
    {
        printf("%d", bv[i]);
    }
    printf("\n");
}

int exp(int b, int e)
{
    int i, ret;
    ret = 1;
    for (i = 0; i < e; i++)
    {
        ret *= b;
    }
    return ret;
}


unsigned int b2u(char *bv)
{
    unsigned int ret;
    ret = 0;
    for (int i = LSB_INDEX; i <= MSB_INDEX; i++)
    {
        ret+= bv[i] * exp(2, i);
    }
    return ret;
}

int b2s(char *bv){
    int ret, i, sign;
    ret = 0;
    sign = exp(-1, bv[MSB_INDEX]);
    for (i = LSB_INDEX; i < MSB_INDEX; i++)
    {
        ret += bv[i] * exp(2, i);
    }
    ret = ret * sign;
    return ret;
}

int b2o(char *bv){
    int ret, i, term;
    ret = 0;

    term=-1*bv[MSB_INDEX] * (exp(2, MSB_INDEX)-1);
    for (i = LSB_INDEX; i < MSB_INDEX; i++)
    {
        ret += bv[i] * exp(2, i);
    }
    ret = ret + term;
    return ret;
}

int b2t(char *bv){
    int ret, i, term;
    ret = 0;
    term=-1*bv[MSB_INDEX] * (exp(2, MSB_INDEX));
    for (i = LSB_INDEX; i < MSB_INDEX; i++)
    {
        ret += bv[i] * exp(2, i);
    }
    ret = ret + term;
    return ret;
}

void bit_addition(char *bv1, char *bv2, char *result)
{
    // int carry = 0;
    // for (int i = LSB_INDEX; i <= MSB_INDEX; i++)
    // {
    //     result[i] = (bv1[i] + bv2[i] + carry) % 2;
    //     carry = (bv1[i] + bv2[i] + carry) / 2;
    // }
    int i;
    char sum;
    char carry[BIT_VECTOR_LENGTH+1] = {0,};

    for (i = LSB_INDEX; i <= MSB_INDEX; i++)
    {
        sum = bv1[i] + bv2[i] + carry[i];
        if (sum == 0)
        {
            result[i] = 0;
            carry[i + 1] = 0;
        }
        else if (sum == 1)
        {
            result[i] = 1;
            carry[i + 1] = 0;   
        }
        else if (sum == 2)
        {
            result[i] = 0;
            carry[i + 1] = 1;
        }
        else
        {
            result[i] = 1;
            carry[i + 1] = 1;
        }
    }
}

unsigned int unsigned_addition(char *bv1, char *bv2){
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2u(result);
}

int twos_complement_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2t(result);
}

int ones_complement_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2o(result);
}

int sign_magnitude_addition(char *bv1, char *bv2)
{
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2s(result);
}