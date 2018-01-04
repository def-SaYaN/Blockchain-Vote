#include "hash_sha.h"
#include<string>
using namespace std;


string calculate_sha (string message)
{
   CryptoPP::SHA256 hash;
    byte digest[ CryptoPP::SHA256::DIGESTSIZE ];

    hash.CalculateDigest( digest, reinterpret_cast<byte*>(&message[0]), message.length() );
 
    CryptoPP::HexEncoder encoder;
    string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
        encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

      return output;

}


string SHA256(string data)
{
    byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[CryptoPP::SHA256::DIGESTSIZE];

    CryptoPP::SHA256().CalculateDigest(abDigest, pbData, nDataLen);

    return string((char*)abDigest);
}

