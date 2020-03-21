#pragma once

#include "transactions/OperationFrame.h"

namespace stellar
{

class AbstractLedgerTxn;

class CreatePollOpFrame : public OperationFrame
{
    CreatePollResult&
    innerResult()
    {
        return mResult.tr().createPollResult();
    }
    CreatePollOp const& mCreatePoll;

  public:
    CreatePollOpFrame(Operation const& op, OperationResult& res,
                      TransactionFrame& parentTx);

    bool doApply(AbstractLedgerTxn& ltx) override;
    bool doCheckValid(uint32_t ledgerVersion) override;
    void insertLedgerKeysToPrefetch(
        std::unordered_set<LedgerKey>& keys) const override;

    static CreatePollResultCode
    getInnerCode(OperationResult const& res)
    {
        return res.tr().createPollResult().code();
    }
};
}
