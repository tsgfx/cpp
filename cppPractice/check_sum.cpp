#include <iostream>
#include <fstream>
#include <vector>

uint16_t calculate_checksum(const std::vector<uint8_t> &data)
{
    // 计算网际校验和
    std::vector<uint8_t> modified_data = data;
    if (data.size() % 2 == 1)
    {
        modified_data.push_back(0x00);
    }

    uint32_t checksum = 0;
    for (size_t i = 0; i < modified_data.size(); i += 2)
    {
        uint16_t word = (modified_data[i] << 8) + modified_data[i + 1];
        checksum += word;
        checksum = (checksum & 0xffff) + (checksum >> 16);
    }

    checksum = ~checksum & 0xffff;
    return static_cast<uint16_t>(checksum);
}

std::vector<uint8_t> read_message(const std::string &file_path)
{
    // 从文件中读取报文
    std::ifstream file(file_path, std::ios::binary);
    std::vector<uint8_t> data;
    char byte;
    while (file.get(byte))
    {
        data.push_back(static_cast<uint8_t>(byte));
    }
    return data;
}

int main()
{
    std::string file_path = "test.txt"; // 输入文件路径
    std::vector<uint8_t> data = read_message(file_path);
    uint16_t checksum = calculate_checksum(data);

    // 输出原始的报文内容
    std::cout << "报文内容: ";
    for (const auto &byte : data)
    {
        std::cout << byte;
    }
    std::cout << std::endl;
    std::cout << "校验和: " << std::hex << checksum << std::endl;

    return 0;
}
