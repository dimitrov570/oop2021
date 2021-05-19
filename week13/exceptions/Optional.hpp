#pragma once

class Optional 
{
    bool isError;
    int errorCode;
    int result;

public:
    Optional(int errorCode, bool isError = true, int result = 0) : errorCode(errorCode), isError(isError), result(result)
    {}


    bool hasError() const
    {
        return isError;
    }

    int getResult() const
    {
        return result;
    }

    int getErrorCode() const
    {
        return errorCode;
    }
};